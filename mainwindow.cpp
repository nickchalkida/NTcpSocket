#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "N_SOCKET.h"

Message *neomessage;
NSOCKET *nsocket;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nsocket = new NSOCKET();
    neomessage = new Message();

    QObject::connect(
                neomessage,
                SIGNAL(addListViewData(QVariant)),
                //ui->listWidget,
                //SLOT(on_listWidget_itemEntered(QListWidgetItem *item))
                //ui->centralWidget,
                this,
                SLOT(mynewslot1(QVariant))
                );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSend_clicked()
{
    nsocket->Send_Message(ui->lineEdit->text(),ui->lineEditRIP->text(),ui->lineEditRPort->text().toInt());
}

void MainWindow::on_pushButtonStartListen_clicked()
{
    nsocket->InitSocket(ui->lineEditRIP->text(),ui->lineEditLPort->text().toInt(),ui->lineEditRPort->text().toInt());
    nsocket->StartListenService();
}

void MainWindow::mynewslot1(QVariant item){
    QListWidgetItem *newItem = new QListWidgetItem;
    QString qs = item.toString();
    newItem->setText(qs);
    ui->listWidget->addItem(newItem);
}
