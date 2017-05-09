/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonSend;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEditRIP;
    QPushButton *pushButtonStartListen;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditRPort;
    QLineEdit *lineEditLPort;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(441, 454);
        QPalette palette;
        QBrush brush(QColor(217, 217, 217, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 234, 157, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        pushButtonSend = new QPushButton(centralWidget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSend->sizePolicy().hasHeightForWidth());
        pushButtonSend->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButtonSend);

        verticalSpacer = new QSpacerItem(20, 268, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        lineEditRIP = new QLineEdit(centralWidget);
        lineEditRIP->setObjectName(QStringLiteral("lineEditRIP"));
        sizePolicy.setHeightForWidth(lineEditRIP->sizePolicy().hasHeightForWidth());
        lineEditRIP->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(lineEditRIP);

        pushButtonStartListen = new QPushButton(centralWidget);
        pushButtonStartListen->setObjectName(QStringLiteral("pushButtonStartListen"));
        sizePolicy.setHeightForWidth(pushButtonStartListen->sizePolicy().hasHeightForWidth());
        pushButtonStartListen->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButtonStartListen);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        lineEditRPort = new QLineEdit(centralWidget);
        lineEditRPort->setObjectName(QStringLiteral("lineEditRPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditRPort->sizePolicy().hasHeightForWidth());
        lineEditRPort->setSizePolicy(sizePolicy1);
        lineEditRPort->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(lineEditRPort);

        lineEditLPort = new QLineEdit(centralWidget);
        lineEditLPort->setObjectName(QStringLiteral("lineEditLPort"));
        sizePolicy1.setHeightForWidth(lineEditLPort->sizePolicy().hasHeightForWidth());
        lineEditLPort->setSizePolicy(sizePolicy1);
        lineEditLPort->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(lineEditLPort);


        verticalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 441, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButtonSend->setText(QApplication::translate("MainWindow", "Send Message", Q_NULLPTR));
        lineEditRIP->setText(QApplication::translate("MainWindow", "192.168.0.232", Q_NULLPTR));
        pushButtonStartListen->setText(QApplication::translate("MainWindow", "Start Listen", Q_NULLPTR));
        lineEditRPort->setText(QApplication::translate("MainWindow", "8060", Q_NULLPTR));
        lineEditLPort->setText(QApplication::translate("MainWindow", "8010", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
