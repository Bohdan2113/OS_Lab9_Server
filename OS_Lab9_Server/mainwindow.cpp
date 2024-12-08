#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QThread"
#include "QTimer"

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

#include "server.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug() << "Create UI";
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->homePage);

    ui->errorLabel->setText("");
    ui->errorLabel->setStyleSheet("QLabel { color: black; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");

    ui->voteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->hamstersTableWidget->setColumnWidth(1, 150);

    podium.push_back(ui->firstPlaceLabel);
    podium.push_back(ui->secondPlaceLabel);
    podium.push_back(ui->thirdPlaceLabel);

    do {
        int iResult = 1;
        do {
            mutexUI = CreateMutex(NULL, FALSE, NULL);
            if (mutexUI == NULL) break;

            mutexClients = CreateMutex(NULL, FALSE, NULL);
            if (mutexClients == NULL) break;

            mutexRecvMsg = CreateMutex(NULL, FALSE, NULL);
            if (mutexRecvMsg == NULL) break;

            mutexSendMsg = CreateMutex(NULL, FALSE, NULL);
            if (mutexSendMsg == NULL) break;

            mutexIdeas = CreateMutex(NULL, FALSE, NULL);
            if (mutexIdeas == NULL) break;

            iResult = 0;
        } while (false);

        if (iResult) {
            // printf("CreateMutex failed with error: %d\n", GetLastError());
            break;
        }

        WSADATA wsaData;


        struct addrinfo hints;

        char recvBuf[DEFAULT_BUFLEN];
        int  recvBufLen = DEFAULT_BUFLEN;

        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            // printf("WSAStartup failed with error: %d\n", iResult);
            break;
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_PASSIVE;

        // Resolve the server address and port
        iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
        if (iResult != 0) {
            // printf("getaddrinfo failed with error: %d\n", iResult);
            WSACleanup();
            break;
        }

        // printf("Enter \"RS\" to start:\n");


        DWORD threadID_send;
        HANDLE sendThread = CreateThread(
            NULL,
            0,
            sendMessages,
            &clients,
            0,
            &threadID_send
            );
        DWORD threadID_servent;
        HANDLE serventThread = CreateThread(
            NULL,
            0,
            receiveServent,
            &clients,
            0,
            &threadID_servent
            );

    } while (0);
}

MainWindow::~MainWindow()
{
    WSACleanup();
    CloseHandle(mutexUI);
    CloseHandle(mutexClients);
    CloseHandle(mutexRecvMsg);
    CloseHandle(mutexSendMsg);
    CloseHandle(mutexIdeas);

    delete ui;
}


QTimer *updateTimer;
int prevClientsCount = 0;
int prevIdeasCount = 0;


void MainWindow::updateClientsTable() {

    WaitForSingleObject(mutexClients, INFINITY);
    int clientsCount = clients.size();
    if (clientsCount > prevClientsCount) {
        for (int i = prevClientsCount; i < clientsCount; i++) {
            AddUserInTable(ui->hamstersPage, clients[i].name);
        }
    }
    prevClientsCount = clientsCount;
    ReleaseMutex(mutexClients);
}

void MainWindow::updateIdeasTable() {

    WaitForSingleObject(mutexIdeas, INFINITY);
    int ideasCount = ideaVector.size();
    if (ideasCount > prevIdeasCount) {
        for (int i = prevIdeasCount; i < ideasCount; i++) {
            AddIdea(ideaVector[i].message.message, ideaVector[i].ideaTID);
        }
    }
    prevIdeasCount = ideasCount;
    ReleaseMutex(mutexIdeas);
}

void MainWindow::updateVoteTable()
{
    // Перевіряємо, чи кількість рядків у таблиці відповідає розміру ideaVector
    if (ui->voteTableWidget->rowCount() != static_cast<int>(ideaVector.size())) {
        qWarning() << "Mismatch between table rows and ideaVector size.";
        return;
    }

    // Оновлюємо дані у кожному рядку таблиці
    for (int i = 0; i < ideaVector.size(); ++i) {
        // Оновлюємо колонку з ідеєю
        QTableWidgetItem* ideaItem = ui->voteTableWidget->item(i, 0);
        if (ideaItem) {
            ideaItem->setText(QString::fromStdString(ideaVector[i].message.message));
        } else {
            qWarning() << "Missing item in column 0 at row" << i;
        }

        // Оновлюємо колонку з кількістю голосів
        QTableWidgetItem* voteCountItem = ui->voteTableWidget->item(i, 1);
        if (voteCountItem) {
            voteCountItem->setText(QString::number(ideaVector[i].cntVoice));
        } else {
            qWarning() << "Missing item in column 1 at row" << i;
        }
    }
}

// Buttons
void MainWindow::on_createRoomButton_clicked()
{
    QLineEdit* lineEdit = ui->topicLineEdit;
    QLabel* errorLabel = ui->errorLabel;

    if (lineEdit->text().isEmpty()) {
        lineEdit->setStyleSheet(
            "QLineEdit { "
            "border: 2px solid red; "
            "color: rgb(0, 0, 0); "
            "width: 150px; "
            "height: 50px; "
            "background: transparent; "
            "background-color: rgb(255, 255, 255, 0.7); "
            "}"
            );

        errorLabel->setStyleSheet("QLabel { color: red; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");
        errorLabel->setText("Enter name of the topic");

        return;
    } else {
        lineEdit->setStyleSheet(
            "QLineEdit { "
            "color: rgb(0, 0, 0); "
            "width: 150px; "
            "height: 50px; "
            "background: transparent; "
            "background-color: rgb(255, 255, 255, 0.7); "
            "}"
            );
        errorLabel->setStyleSheet("QLabel { color: black; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");
        errorLabel->setText("");

        QTime time = ui->setTimeEdit->time();
        int minutes = time.minute();
        int seconds = time.second();

        sessionTimeSec = minutes * 60 + seconds;
        sessionTopic=lineEdit->text().toStdString();

        lineEdit->setText(" ");

        updateTimer = new QTimer(this);
        connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateClientsTable);
        updateTimer->start(1000);
    }

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("RS");
    ReleaseMutex(mutexSendMsg);

    ui->stackedWidget->setCurrentWidget(ui->hamstersPage);

}

void MainWindow::on_startSessionPushButton_clicked()
{
    prevClientsCount = 0;
    updateTimer->stop();

    disconnect(updateTimer, &QTimer::timeout, this, &MainWindow::updateClientsTable);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateIdeasTable);

    updateTimer->start(1000);

    ui->stackedWidget->setCurrentWidget(ui->createIdeaPage);

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("SS");
    ReleaseMutex(mutexSendMsg);
}

void MainWindow::on_EndSessionButton_clicked()
{
    prevIdeasCount = 0;
    updateTimer->stop();

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("ES");
    ReleaseMutex(mutexSendMsg);

    // ui->stackedWidget->setCurrentWidget(ui->votePage);
    // ui->topicNameLabel->setText(this->topicName);

}

void MainWindow::on_homeButton_clicked()
{
    ui->EndSessionButton->setEnabled(true); // Увімкнути кнопку

    ui->stackedWidget->setCurrentWidget(ui->homePage);
    this->topicName="";

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("RS");
    ReleaseMutex(mutexSendMsg);

    int rowCount = ui->voteTable->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->voteTable->removeRow(i);
    }

    rowCount = ui->hamstersTableWidget->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->hamstersTableWidget->removeRow(i);
    }

    rowCount = ui->voteTableWidget->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->voteTableWidget->removeRow(i);
    }
}


void MainWindow::on_topicLineEdit_textChanged(const QString &text)
{
    QLineEdit* lineEdit = ui->topicLineEdit;
     QLabel* errorLabel = ui->errorLabel;

    if (text.isEmpty()) {
         lineEdit->setStyleSheet(
             "QLineEdit { "
             "border: 2px solid red; "
             "color: rgb(0, 0, 0); "
             "width: 150px; "
             "height: 50px; "
             "background: transparent; "
             "background-color: rgb(255, 255, 255, 0.7); "
             "}"
             );

         errorLabel->setStyleSheet("QLabel { color: red; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");
         errorLabel->setText("Enter name of the topic");
    } else {
        lineEdit->setStyleSheet(
            "QLineEdit { "
            "color: rgb(0, 0, 0); "
            "width: 150px; "
            "height: 50px; "
            "background: transparent; "
            "background-color: rgb(255, 255, 255, 0.7); "
            "}"
            );

        errorLabel->setStyleSheet("QLabel { color: black; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");
        errorLabel->setText("");
    }
}

void MainWindow::on_stackedWidget_currentChanged(int pageIndex)
{
    int minutes = 0;
    int seconds = 0;

    static QTimer* progStageTimer = nullptr; // Таймер для перевірки progStage
    static QTimer* progStageTimer2 = nullptr; // Таймер для перевірки progStage

    switch (pageIndex)
    {
    case 0: break;
    case 1:
        break;
    case 2:
        minutes = sessionTimeSec / 60;
        seconds = sessionTimeSec % 60;

        timer = new CountdownTimer(minutes, seconds, ui->timerCrIdeaLabel, [this]() {
            WaitForSingleObject(mutexSendMsg, INFINITE);
            sendMessageQueue.push("ES");
            ReleaseMutex(mutexSendMsg);
        });

        // Створюємо новий таймер
        progStageTimer = new QTimer(this);
        connect(progStageTimer, &QTimer::timeout, [this]() {
            if (progStage == "ES") {
                progStage = "DS";

                ui->EndSessionButton->setEnabled(false);
            }
            if (progStage == "SV") {
                progStage = "DS";

                WaitForSingleObject(mutexSendMsg, INFINITE);
                sendMessageQueue.push("SV");
                ReleaseMutex(mutexSendMsg);





                ui->voteTableWidget->setRowCount(ideaVector.size());

                printf("ideaVector.size() = %d\n", ideaVector.size());
                // Перебираємо всі ідеї у векторі
                for (int i = 0; i < ideaVector.size(); i++) {

                    // Створюємо елемент для ідеї
                    QTableWidgetItem* ideaItem = new QTableWidgetItem(QString::fromStdString(ideaVector[i].message.message));
                    // ideaItem->setFont(QFont("Arial", 16)); // Форматування тексту
                    ui->voteTableWidget->setItem(i, 0, ideaItem);

                    // Створюємо елемент для кількості голосів
                    QTableWidgetItem* voteCountItem = new QTableWidgetItem(QString::number(ideaVector[i].cntVoice));
                    voteCountItem->setTextAlignment(Qt::AlignCenter); // Вирівнювання по центру
                    ui->voteTableWidget->setItem(i, 1, voteCountItem);
                }

                updateTimer->stop();

                disconnect(updateTimer, &QTimer::timeout, this, &MainWindow::updateIdeasTable);
                connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateVoteTable);

                updateTimer->start(1000);
                ui->stackedWidget->setCurrentWidget(ui->votePage);






                progStageTimer->stop();
                progStageTimer->deleteLater();
                progStageTimer = nullptr;
            }
        });

        progStageTimer->start(100); // Перевірка кожні 100 мс

        break;
    case 3:
        printf("case 3: enter\n");
        delete timer;
        timer = nullptr;

        timer = new CountdownTimer(1, 0, ui->timeVoteLabel, [this]() {
            timerOut = true;
        });

        printf("case 3: progStageTimer2 before\n");
        // Створюємо новий таймер
        progStageTimer2 = new QTimer(this);
        if (!progStageTimer2) {
            printf("Failed to create progStageTimer2\n");
            return;
        }

        if (!connect(progStageTimer2, &QTimer::timeout, this, [this]() {
                printf("case 3: Timeout triggered\n");
                printf("case 3: Cur progStage = ");
                std::cout << progStage << "\n";
                if (progStage == "EV") {
                    progStage = "DS";
                    ui->stackedWidget->setCurrentWidget(ui->podiumPage);

                    progStageTimer2->stop();
                    progStageTimer2->deleteLater();
                    progStageTimer2 = nullptr;
                }
            })) {
            printf("Failed to connect timeout signal\n");
            return;
        }
        printf("case 3: progStageTimer2 after\n");

        progStageTimer2->start(500); // Перевірка кожні 100 мс

        break;
    case 4:
        delete timer;
        timer = nullptr;

        OutputPodium();

        break;
    default:
        break;
    }
}


// Додавання 1 нового користувача в табличку на hamstersTableWidget
bool MainWindow::AddUserInTable(QWidget* page, std::string sUserName){

    QTableWidget* table = page->findChild<QTableWidget*>("hamstersTableWidget");
    if (!table) {
        qDebug() << "Table hamstersTableWidget not found on the page!";
        return false;
    }

    qDebug() << "Table founded ";
    int currentRowCount = table->rowCount();
    int iRowIndex= currentRowCount;
    table->setRowCount(currentRowCount+1);

    qDebug() << "Table: set iteam " ;
    table->setItem(iRowIndex, 0, new QTableWidgetItem(QString::fromStdString(sUserName)));

    QPushButton* button = new QPushButton("REMOVE", table);
    QFont font = button->font();
    font.setPointSize(16);
    button->setFont(font);
    button->setFixedSize(150, 50);

    table->setCellWidget(iRowIndex, 1, button);
    table->resizeRowsToContents();

    connect(button, &QPushButton::clicked, this, [iRowIndex, table]() {

        QMessageBox::StandardButton reply = QMessageBox::question(
            nullptr, "Confirm deeltion",
            "Are you sure that you want\n  to delete this user?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            WaitForSingleObject(mutexClients, INFINITY);
            table->removeRow(iRowIndex);
            closeClientWithUID(clients, clients[iRowIndex].clientUID);
            ReleaseMutex(mutexClients);

            qDebug() << "User row removed";

            if (table->rowCount() == 0) {
                qDebug() << "Table is now empty";
            }
        } else {
            qDebug() << "User removal cancelled";
        }
    });

    qDebug() << "Table: sucessfully set user "<< sUserName ;
    return  true;
}

//Додавання ідеї до scroll area
void MainWindow::AddIdea(string sIdea, int TID)
{
    // ui->voteTable->setRowCount(ideaVector.size());

    // for (int row = 0; row < ideaVector.size(); ++row) {
    //     QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(ideaVector[row].message));
    //     ui->voteTable->setItem(row, 0, item);
    // }



    // QWidget* contentWidget = ui->scrollAreaWidgetContents;
    // if (!contentWidget) return; // Перевірка на наявність

    // qDebug() << "Scroll area founded ";

    // QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(contentWidget->layout());
    // if (!layout) {
    //     layout = new QVBoxLayout(contentWidget);
    //     contentWidget->setLayout(layout);
    // }

    // QPushButton* button = new QPushButton(QString::fromStdString(sIdea), contentWidget);

    // button->setProperty("ideaID", TID);
    // QFont font = button->font();
    // font.setPointSize(16);
    // button->setFont(font);

    // button->adjustSize();
    // button->setFixedSize(720, 70);

    // QMenu *contextMenu = new QMenu(button);
    // QAction *deleteAction = new QAction("Delete", contextMenu);


    // contextMenu->addAction(deleteAction);
    // connect(deleteAction, &QAction::triggered, [=]() {

    //     QMessageBox::StandardButton reply = QMessageBox::question(
    //         nullptr, "Confirm deletion",
    //         "Are you sure that you want\n  to delete this idea?",
    //         QMessageBox::Yes | QMessageBox::No);

    //     if (reply == QMessageBox::Yes) {
    //         WaitForSingleObject(mutexIdeas, INFINITY);
    //         layout->removeWidget(button);
    //         deleteIdea(TID);
    //         ReleaseMutex(mutexIdeas);
    //         delete button;
    //     } else {
    //         qDebug() << "User removal cancelled";
    //     }

    // });

    // button->setContextMenuPolicy(Qt::CustomContextMenu);
    // connect(button, &QPushButton::customContextMenuRequested, [=](const QPoint &pos) {
    //     contextMenu->exec(button->mapToGlobal(pos));
    // });


    // layout->addWidget(button);


    // Додаємо новий рядок у таблицю
    int newRow = ui->voteTable->rowCount();
    ui->voteTable->insertRow(newRow);

    // Додаємо текст ідеї в першу колонку
    QTableWidgetItem* ideaItem = new QTableWidgetItem(QString::fromStdString(sIdea));
    ideaItem->setData(Qt::UserRole, TID); // Зберігаємо ID ідеї
    ideaItem->setFont(QFont("Arial", 16)); // Приклад форматування
    ui->voteTable->setItem(newRow, 0, ideaItem);

    // Створюємо кнопку для видалення і додаємо її у другу колонку
    QPushButton* deleteButton = new QPushButton("Delete", ui->voteTable);
    deleteButton->setFixedSize(100, 30);
    ui->voteTable->setCellWidget(newRow, 1, deleteButton);

    // Обробник видалення ідеї
    connect(deleteButton, &QPushButton::clicked, [=]() {
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Confirm deletion",
            "Are you sure that you want\n  to delete this idea?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            WaitForSingleObject(mutexIdeas, INFINITY);

            // Видаляємо рядок із таблиці
            ui->voteTable->removeRow(newRow);
            deleteIdea(TID); // Видаляємо ідею з бази чи вектора

            ReleaseMutex(mutexIdeas);
        } else {
            qDebug() << "User removal cancelled";
        }
    });
}

void MainWindow::OutputPodium()
{
    for(int i = 0; i < (ideaVector.size() < 3 ? ideaVector.size() : 3); i++) {
        if (podium[i] == nullptr)
            qDebug() << "podium " << i << " nullptr";
        podium[i]->setText(QString::fromStdString(ideaVector[i].message.message));

        qDebug() << "podium set: " << i;
    }
}

