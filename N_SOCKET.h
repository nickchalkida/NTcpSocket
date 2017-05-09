//******************************************************************************
//
// Unit name: N_SOCKET.h
// Author Nikolaos Kechris
// Description:
//
// Modification history:
// Kechris Nikolaos 09/05/2017: Initial design.
//
//******************************************************************************

#ifndef N_SOCKET_H
#define N_SOCKET_H

#include <QtCore>
#include <QObject>
#include <QMessageBox>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QNetworkInterface>

#include <QQueue>
#include <QMutex>
#include <QListView>
#include <QDebug>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
public:
    void addListData(const QString &a);
    void setAuthor(const QString &a);
    QString author();
    Q_INVOKABLE void myfunc();
signals:
    void authorChanged();
    void addListViewData(QVariant lvdata);
private:
    QString m_author;
};

class LISTENS_THREAD : public QThread
{
    Q_OBJECT
    QTcpServer *tcp_server;
    QTcpSocket *tcp_client;
    int conid;
protected:
    void run();
};

class SERVICE_THREAD : public QThread
{
    Q_OBJECT
protected:
    void run();
};


class NSOCKET : public QObject {
    Q_OBJECT

    QString remote_ipAddress;
    int remote_port;

    LISTENS_THREAD *lthread;
    SERVICE_THREAD *sthread;
public :
    NSOCKET();
	~NSOCKET();
    Q_INVOKABLE int InitSocket(QString CP, int lp, int rp);
    Q_INVOKABLE int Send_Message(QString, QString, int);
    Q_INVOKABLE int StartListenService();

};

#endif

//******************************************************************************
//******************************************************************************


