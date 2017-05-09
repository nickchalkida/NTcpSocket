//******************************************************************************
//
// Unit name: main.cpp
// Author Nikolaos Kechris
// Description:
//
// Modification history:
// Kechris Nikolaos 09/05/2017: Initial design.
//
//******************************************************************************

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
