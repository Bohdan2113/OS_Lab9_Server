#include "mainwindow.h"

#include <windows.h> // Для AllocConsole
#include <cstdio>    // Для freopen і printf

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << "main";

    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    printf("Hello, console!\n");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
