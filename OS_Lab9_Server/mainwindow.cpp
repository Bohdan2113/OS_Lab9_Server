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
    std::cout << "CONSTRUCTOR STARTED\n";
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->homePage);

    ui->errorLabel->setText("");
    ui->errorLabel->setStyleSheet("QLabel { color: black; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");

    ui->voteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->voteTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->hamstersTableWidget->setColumnWidth(1, 150);

    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->hamstersTableWidget->setColumnWidth(1, 150);

    ui->voteTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->voteTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->voteTable->setColumnWidth(1, 150);


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
            printf("CreateMutex failed with error: %d\n", (int)GetLastError());
            break;
        }

        WSADATA wsaData;
        struct addrinfo hints;

        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            printf("WSAStartup failed with error: %d\n", iResult);
            break;
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_PASSIVE;

        iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
        if (iResult != 0) {
            printf("getaddrinfo failed with error: %d\n", iResult);
            WSACleanup();
            break;
        }

        DWORD threadID_send;
        HANDLE sendThread = CreateThread(
            NULL,
            0,
            sendMessages,
            &clients,
            0,
            &threadID_send
            );

        if (sendThread == NULL) {
            printf("Error creating sendThread\n");
            break;
        }

        DWORD threadID_servent;
        HANDLE serventThread = CreateThread(
            NULL,
            0,
            receiveServent,
            &clients,
            0,
            &threadID_servent
            );

        if (serventThread == NULL) {
            printf("Error creating serventThread\n");
            break;
        }

    } while (0);

    std::cout << "CONSTRUCTOR ENDED\n";
}

MainWindow::~MainWindow()
{
    std::cout << "\nDESSTRUCTOR STARTED\n";
    WSACleanup();
    CloseHandle(mutexUI);
    CloseHandle(mutexClients);
    CloseHandle(mutexRecvMsg);
    CloseHandle(mutexSendMsg);
    CloseHandle(mutexIdeas);
    std::cout << "\nDESSTRUCTOR ENDED\n";
    delete ui;
}


QTimer *updateTimer;
int prevClientsCount = 0;
int prevIdeasCount = 0;


void MainWindow::updateClientsTable() {

    WaitForSingleObject(mutexClients, INFINITY);
    int clientsCount = (int)clients.size();
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
    int ideasCount = (int)ideaVector.size();
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
    if (ui->voteTableWidget->rowCount() != static_cast<int>(ideaVector.size())) {
        qWarning() << "Mismatch between table rows and ideaVector size.\n"
                   << ui->voteTableWidget->rowCount() << " != " << ideaVector.size();
        return;
    }

    for (int i = 0; i < ideaVector.size(); ++i) {
        QTableWidgetItem* ideaItem = ui->voteTableWidget->item(i, 0);
        if (ideaItem) {
            ideaItem->setText(QString::fromStdString(ideaVector[i].message.message));
        } else {
            qWarning() << "Missing item in column 0 at row" << i;
        }

        QTableWidgetItem* voteCountItem = ui->voteTableWidget->item(i, 1);
        if (voteCountItem) {
            voteCountItem->setText(QString::number(ideaVector[i].cntVoice));
        } else {
            qWarning() << "Missing item in column 1 at row" << i;
        }
    }
}


void MainWindow::on_createRoomButton_clicked()
{
    printf("BUTTON createRoom CLICKED\n");
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
    }

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


    printf("Push message: RS\n");
    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("RS");
    ReleaseMutex(mutexSendMsg);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateClientsTable);
    updateTimer->start(1000);

    ui->stackedWidget->setCurrentWidget(ui->hamstersPage);

    printf("BUTTON createRoom UNCLICKED\n");
}

void MainWindow::on_startSessionPushButton_clicked()
{
    printf("BUTTON startSession CLICKED\n");

    prevClientsCount = 0;
    updateTimer->stop();

    disconnect(updateTimer, &QTimer::timeout, this, &MainWindow::updateClientsTable);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateIdeasTable);

    updateTimer->start(1000);

    ui->stackedWidget->setCurrentWidget(ui->createIdeaPage);

    printf("Push message: SS\n");
    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("SS");
    ReleaseMutex(mutexSendMsg);

    printf("BUTTON startSession UNCLICKED\n");
}

void MainWindow::on_EndSessionButton_clicked()
{
    printf("BUTTON EndSession CLICKED\n");

    prevIdeasCount = 0;
    updateTimer->stop();

    printf("Push message: ES\n");
    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("ES");
    ReleaseMutex(mutexSendMsg);

    printf("BUTTON EndSession UNCLICKED\n");
}

void MainWindow::on_homeButton_clicked()
{
    printf("BUTTON homeButton CLICKED\n");

    ui->EndSessionButton->setEnabled(true);

    QTime time(0, 3);
    ui->setTimeEdit->setTime(time);

    int rowCount = ui->hamstersTableWidget->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->hamstersTableWidget->removeRow(i);
    }

    rowCount = ui->voteTable->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->voteTable->removeRow(i);
    }

    rowCount = ui->voteTableWidget->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->voteTableWidget->removeRow(i);
    }

    ui->podiumTopicLabel->setText("");
    ui->firstPlaceLabel->setText(QString::fromStdString(""));
    ui->secondPlaceLabel->setText(QString::fromStdString(""));
    ui->thirdPlaceLabel->setText(QString::fromStdString(""));

    ui->stackedWidget->setCurrentWidget(ui->homePage);

    printf("BUTTON homeButton UNCLICKED\n");
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

    static QTimer* progStageTimer = nullptr;
    static QTimer* progStageTimer2 = nullptr;

    switch (pageIndex)
    {
    case 0:
        printf("UI Case 0: enter\n");
        break;
    case 1:
       printf("UI Case 1: enter\n");
        break;
    case 2:
        printf("UI Case 2: enter\n");
        minutes = sessionTimeSec / 60;
        seconds = sessionTimeSec % 60;

        timer = new CountdownTimer(minutes, seconds, ui->timerCrIdeaLabel, []() {
            WaitForSingleObject(mutexSendMsg, INFINITE);
            sendMessageQueue.push("ES");
            ReleaseMutex(mutexSendMsg);
        });

        progStageTimer = new QTimer(this);
        connect(progStageTimer, &QTimer::timeout, [this]() {
            if (progStage == "ES") {
                progStage = "DS";

                ui->EndSessionButton->setEnabled(false);
            }
            if (progStage == "SV") {
                progStage = "DS";

                ui->voteTableWidget->setRowCount((int)ideaVector.size());

                printf("ideaVector.size() = %d\n", (int)ideaVector.size());
                for (int i = 0; i < ideaVector.size(); i++) {

                    QTableWidgetItem* ideaItem = new QTableWidgetItem(QString::fromStdString(ideaVector[i].message.message));
                    // ideaItem->setFont(QFont("Arial", 16)); // Форматування тексту
                    ui->voteTableWidget->setItem(i, 0, ideaItem);

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
        progStageTimer->start(100);

        break;
    case 3:
        printf("UI Case 3: enter\n");
        delete timer;
        timer = nullptr;

        timer = new CountdownTimer(1, 0, ui->timeVoteLabel, []() {
            timerOut = true;
        });

        progStageTimer2 = new QTimer(this);
        if (!progStageTimer2) {
            printf("Failed to create progStageTimer2\n");
            return;
        }

        if (!connect(progStageTimer2, &QTimer::timeout, this, [this]() {
                if (progStage == "EV") {
                    progStage = "DS";
                    ui->stackedWidget->setCurrentWidget(ui->podiumPage);

                    updateTimer->stop();
                    updateTimer->deleteLater();
                    updateTimer = nullptr;

                    progStageTimer2->stop();
                    progStageTimer2->deleteLater();
                    progStageTimer2 = nullptr;
                }
            })) {
            printf("Failed to connect timeout signal\n");
            return;
        }

        progStageTimer2->start(500);

        break;
    case 4:
        printf("UI Case 3: enter\n");
        delete timer;
        timer = nullptr;

        OutputPodium();

        break;
    default:
        break;
    }
}


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

    connect(button, &QPushButton::clicked, this, [button, table]() {
        // Знаходимо рядок, до якого прив'язана кнопка
        QModelIndex index = table->indexAt(button->pos());
        int rowIndex = index.row();

        if (rowIndex == -1) {
            qDebug() << "Failed to find the row index!";
            return;
        }

        QMessageBox::StandardButton reply = QMessageBox::question(
            nullptr, "Confirm deletion",
            "Are you sure that you want\n  to delete this user?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            WaitForSingleObject(mutexClients, INFINITY);

            if (rowIndex < clients.size()) { // Перевіряємо, чи індекс в межах масиву
                printf("Trying to kick Client #%d\n", clients[rowIndex].clientUID);
                closeClientWithUID(clients, clients[rowIndex].clientUID);
            }

            table->removeRow(rowIndex);

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

void MainWindow::AddIdea(string sIdea, int TID)
{
    int newRow = ui->voteTable->rowCount();
    int iRowIndex= newRow;
    ui->voteTable->setRowCount(newRow+1);

    QTableWidgetItem* ideaItem = new QTableWidgetItem(QString::fromStdString(sIdea));
    ideaItem->setData(Qt::UserRole, TID); // Зберігаємо ID ідеї
    ideaItem->setFont(QFont("Arial", 16)); // Приклад форматування
    ui->voteTable->setItem(newRow, 0, ideaItem);

    QPushButton* deleteButton = new QPushButton("Delete", ui->voteTable);
    QFont font = deleteButton->font();
    font.setPointSize(16);
    deleteButton->setFont(font);
    deleteButton->setFixedSize(150, 50);

    ui->voteTable->setCellWidget(newRow, 1, deleteButton);
    ui->voteTable->resizeRowsToContents();

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
    ui->podiumTopicLabel->setText(QString::fromStdString(sessionTopic));

    for(int i = 0; i < (ideaVector.size() < 3 ? ideaVector.size() : 3); i++) {
        if (podium[i] == nullptr)
            qDebug() << "podium " << i << " nullptr";
        podium[i]->setText(QString::fromStdString(ideaVector[i].message.message));

        qDebug() << "podium set: " << i;
    }
}

