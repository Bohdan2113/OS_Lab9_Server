#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QThread"
#include "QTimer"
#include <Windows.h>

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

    QTimer::singleShot(5000, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->podiumPage);
    });
}


void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}


