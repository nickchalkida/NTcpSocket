//******************************************************************************
//
// Unit name: mainwindow.cpp
// Author Nikolaos Kechris
// Description:
//
// Modification history:
// Kechris Nikolaos 09/05/2017: Initial design.
//
//******************************************************************************

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "N_SOCKET.h"

NSOCKET *nsocket;
int linecounter=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nsocket = new NSOCKET();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSend_clicked()
{
    int num = ui->lineEdit_Times->text().toInt();
    for (int i=0; i<num; i++) {
        nsocket->Send_Message(ui->lineEdit->text(),ui->lineEditRIP->text(),ui->lineEditRPort->text().toInt());
        QApplication::processEvents();
    }
}

void MainWindow::on_pushButtonStartListen_clicked()
{
    nsocket->InitSocket(ui->lineEditRIP->text(),ui->lineEditLPort->text().toInt(),ui->lineEditRPort->text().toInt());
    nsocket->StartListenService(this);
}

void MainWindow::MessageSlot(QString item){
    QString linestr = QString::number(++linecounter) + " " + item;
    ui->listWidget->addItem(linestr);
    QApplication::processEvents();
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->listWidget->clear();
    linecounter=0;
}

void MainWindow::on_pushButton_ChangePorts_clicked()
{
    QString tmpstr = ui->lineEditLPort->text();
    ui->lineEditLPort->setText(ui->lineEditRPort->text());
    ui->lineEditRPort->setText(tmpstr);
}
