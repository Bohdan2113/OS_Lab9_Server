#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QThread"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createRoomButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->hamstersPage);
}


void MainWindow::on_startSessionPushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->createIdeaPage);
}


void MainWindow::on_EndSessionButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->votePage);

    QThread::sleep(2);
    ui->stackedWidget->setCurrentWidget(ui->podiumPage);
}


void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}

