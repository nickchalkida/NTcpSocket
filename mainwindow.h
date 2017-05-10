//******************************************************************************
//
// Unit name: mainwindow.h
// Author Nikolaos Kechris
// Description:
//
// Modification history:
// Kechris Nikolaos 09/05/2017: Initial design.
//
//******************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_pushButtonSend_clicked();
    void on_pushButtonStartListen_clicked();
    void MessageSlot(QString item);
private slots:
    void on_pushButton_Clear_clicked();
    void on_pushButton_ChangePorts_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

