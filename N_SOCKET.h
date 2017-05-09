//******************************************************************************
//
// Copyright (c) 2014-2015 by  Intralot  S.A. All Rights Reserved. The software,
// data, and  information  contained  herein  are  proprietary  to, and comprise
// valuable  trade  secrets  of,  Intralot  S.A.  which  intends  to  keep  them
// confidential  and  to  preserve them as trade secrets. Copies are provided in
// confidence by Intralot S.A., pursuant to a written license agreement, and may
// be used, copied, transmitted, and stored only in accordance with the terms of
// such a license. No title of such a license is transferable.
//
//                                       Intralot S.A.
//                                       64, Kifissias Ave. & 3, Premetis Str.
//                                       Athens, 15125 Greece
//                                       Phone : (+30) 210 615 6000
//                                       Fax: (+30) 210 610 6800
//                                       E-mail:info@intralot.com
//
// Unit name: N_SOCKET.h
// Description:
//
// Modification history:
// Kechris Nikolaos 24/04/2015: Initial design.
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


