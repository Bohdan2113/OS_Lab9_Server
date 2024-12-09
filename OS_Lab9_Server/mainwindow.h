#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "countdowntimer.h"
#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Buttons
    void on_createRoomButton_clicked();
    void on_startSessionPushButton_clicked();
    void on_EndSessionButton_clicked();
    void on_homeButton_clicked();
    void on_saveAsButton_clicked();

    //function
    bool AddUserInTable(QWidget* page, std::string sUserName);
    void AddIdea(std::string sIdea, int TID);

    void on_topicLineEdit_textChanged(const QString &arg1);

    void on_stackedWidget_currentChanged(int arg1);

    void updateClientsTable();
    void updateIdeasTable();
    void updateVoteTable();

    void OutputPodium();

private:
    Ui::MainWindow *ui;

    QString topicName;
    CountdownTimer* timer;
    std::vector<QLabel*> podium;

};
#endif // MAINWINDOW_H
