#include "mainwindow.h"

#include <windows.h>
#include <cstdio>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

#include <QApplication>

int main(int argc, char *argv[])
{
    // AllocConsole();
    // freopen("CONOUT$", "w", stdout);
    // printf("SERVER STARTED\n");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
