#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <Windows.h>

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

    //function
    bool AddUserInTable(QWidget* page, std::string sUserName);
    void AddIdea(std::string sIdea);

    void on_topicLineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
