#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QThread"
#include "QTimer"
#include <Windows.h>

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

#include "server.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->homePage);

    ui->errorLabel->setText("");
    ui->errorLabel->setStyleSheet("QLabel { color: black; background: transparent;  font-size: 15px;  height: 15px; width: 150px; }");

    ui->voteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->hamstersTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->hamstersTableWidget->setColumnWidth(1, 150);

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
        printf("CreateMutex failed with error: %d\n", GetLastError());
        return 1;
    }

    WSADATA wsaData;


    struct addrinfo hints;

    char recvBuf[DEFAULT_BUFLEN];
    int  recvBufLen = DEFAULT_BUFLEN;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    printf("Enter \"RS\" to start:\n");

    DWORD  inputThreadID;
    HANDLE inputThread = CreateThread(
        NULL,
        0,
        inputMessages,
        NULL,
        0,
        &inputThreadID
        );

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

    DWORD exitCode;
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
            table->removeRow(iRowIndex);
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
void MainWindow::AddIdea(string sIdea){
    QWidget* contentWidget = ui->scrollAreaWidgetContents;
    if (!contentWidget) return; // Перевірка на наявність

    qDebug() << "Scroll area founded ";

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(contentWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(contentWidget);
        contentWidget->setLayout(layout);
    }

    QPushButton* button = new QPushButton(QString::fromStdString(sIdea), contentWidget);

    QFont font = button->font();
    font.setPointSize(16);
    button->setFont(font);

    button->adjustSize();
    button->setFixedSize(720, 70);

    QMenu *contextMenu = new QMenu(button);
    QAction *deleteAction = new QAction("Delete", contextMenu);


    contextMenu->addAction(deleteAction);
    connect(deleteAction, &QAction::triggered, [=]() {
        QMessageBox::StandardButton reply = QMessageBox::question(
            nullptr, "Confirm deletion",
             "Are you sure that you want\n  to delete this idea?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            layout->removeWidget(button);
            delete button;
        } else {
            qDebug() << "User removal cancelled";
        }

    });

    button->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(button, &QPushButton::customContextMenuRequested, [=](const QPoint &pos) {
        contextMenu->exec(button->mapToGlobal(pos));
    });


    layout->addWidget(button);
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

        this->topicName=lineEdit->text();
        lineEdit->setText(" ");
    }

    ui->stackedWidget->setCurrentWidget(ui->hamstersPage);

    string sUserName = "User7763";
    int iRes= AddUserInTable(ui->hamstersPage,sUserName );
    iRes = AddUserInTable(ui->hamstersPage, "Anonymus");
}

void MainWindow::on_startSessionPushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->createIdeaPage);

    AddIdea("Hello");
    AddIdea("Sleep");
    AddIdea("Coffee");
    AddIdea("tea jgjhfj kjhkhfowhc ihdiwefhwkj kw");
    AddIdea("Summer");
    AddIdea("Summer2");
    AddIdea("Summer3");
    AddIdea("Summer4");
}

void MainWindow::on_EndSessionButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->votePage);

    ui->topicNameLabel->setText(this->topicName);


    // QTimer::singleShot(5000, this, [this]() {
    //     ui->stackedWidget->setCurrentWidget(ui->podiumPage);
    // });
}

void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
    this->topicName="";

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

// Timer
void MainWindow::on_stackedWidget_currentChanged(int pageIndex)
{
    switch (pageIndex)
    {
    case 0: break;
    case 1:
        break;
    case 2:
        timer = new CountdownTimer(0, 7, ui->timerCrIdeaLabel, ui->votePage, ui->stackedWidget);
        break;
    case 3:
        delete timer;
        timer = nullptr;

        timer = new CountdownTimer(0, 7, ui->timeVoteLabel, ui->podiumPage, ui->stackedWidget);
        break;
    case 4:
        delete timer;
        timer = nullptr;
        break;
    default:
        break;
    }
}

