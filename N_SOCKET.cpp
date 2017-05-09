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
// Unit name: N_SOCKET.cpp
// Description:
//
// Modification history:
// Kechris Nikolaos 24/04/2015: Initial design.
//
//******************************************************************************

#include "N_SOCKET.h"

//*****************************************************************************

QQueue<QString> process_queue;
QMutex process_mutex;

bool server_started;
bool server_finished;

extern Message *neomessage;

QString local_ipAddress;
int local_port;

void Message::setAuthor(const QString &a) {
    if (a != m_author) {
        m_author = a;
        emit authorChanged();
    }
}

QString Message::author() {
    return m_author;
}

void Message::myfunc(){
    QMessageBox::information(NULL, "Hello World!", "Hi! LISTENS_THREAD");
}

void Message::addListData(const QString &a) {
 qDebug() << "addListViewData";
    emit addListViewData(a);
}


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void LISTENS_THREAD::run()
{
    qDebug() << "LISTENS_THREAD Started";
    tcp_server = new QTcpServer();

    //QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            local_ipAddress = ipAddressesList.at(i).toString();
            qDebug() << "local_ipAddress = " << local_ipAddress;
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (local_ipAddress.isEmpty())
        local_ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << "local_ipAddress = " << local_ipAddress;
    qDebug() << "local_port = " << local_port;


    if (!tcp_server->listen(QHostAddress("192.168.0.232"), local_port)) {
        qDebug() << "Error tcp_server could not listen!!!";
        return;
    }
    qDebug() << "Tcp Server is listening ... ";
    conid=0;
    tcp_server->setMaxPendingConnections(100);

    while (!server_finished) {
        if (tcp_server->waitForNewConnection(100)) {
            //qDebug() << "tcp_server::run: got a TCP connection\n";
            process_mutex.lock();
            while (tcp_server->hasPendingConnections()) {
            tcp_client = tcp_server->nextPendingConnection();
            tcp_client->waitForReadyRead(100);

            QByteArray 	byteArray = tcp_client->readAll();
            QString s_data = byteArray.data();

            process_queue.push_back(s_data);

            tcp_client->close();
            tcp_client->abort();
            process_mutex.unlock();
            }

        } else {
            QThread::msleep(100);
        }
    }
}

//*****************************************************************************

void SERVICE_THREAD::run()
{
    QString q_str;
    while (!server_finished) {
        if (!process_queue.empty()) {
            process_mutex.lock();
            q_str =  process_queue.front();
            process_queue.pop_front();
            neomessage->addListData(q_str);
            process_mutex.unlock();
        }
        else {
            QThread::msleep(100);
        }
    }
}

//*****************************************************************************

NSOCKET::NSOCKET() {
    qDebug() << "In NSOCKET Creator";
    server_started  = false;
    server_finished = false;

}

//*****************************************************************************

NSOCKET::~NSOCKET() {
    qDebug() << "In NSOCKET Destructor";
    server_finished = true;
}

//*****************************************************************************

int NSOCKET::Send_Message(QString msg, QString rip, int rp)
{
    QTcpSocket *socket = new QTcpSocket;
    QHostAddress rhosta;

    if (rip.isEmpty()) {
        rhosta = QHostAddress(local_ipAddress);
    } else {
        rhosta = QHostAddress(rip);
    }

    socket->connectToHost(rhosta, rp);
    if (!socket->waitForConnected(200)) {
        qDebug() << "Socket not connected";
        return 0;
    }

    socket->write(msg.toUtf8()); //write the data itself
    socket->waitForBytesWritten();
    socket->close();
    socket->abort();

    return 0;
}

//******************************************************************************

int NSOCKET::InitSocket(QString CIP, int lp, int rp) {

    qDebug() << "In InitSocket";
    process_queue.clear();
    // Get some form globals
    qDebug() << "CIP = " << CIP << "lp = " << lp << "rp = " << rp;

    remote_ipAddress = CIP;
    local_port = lp;
    remote_port = rp;

    return 0;
}

//******************************************************************************

int NSOCKET::StartListenService() {

    if (server_started)
        return 0;
    server_started = true;

    // Start threads
    lthread = new LISTENS_THREAD;
    sthread = new SERVICE_THREAD;

    lthread->start();
    sthread->start();

	return 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************


