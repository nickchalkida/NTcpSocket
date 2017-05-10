//******************************************************************************
//
// Unit name: N_SOCKET.cpp
// Author Nikolaos Kechris
// Description:
//
// Modification history:
// Kechris Nikolaos 09/05/2017: Initial design.
//
//******************************************************************************

#include "mainwindow.h"
#include "N_SOCKET.h"

//*****************************************************************************

QQueue<QString> process_queue;
QMutex process_mutex;

bool server_started;
bool server_finished;

QString local_ipAddress;
int local_port;


//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void LISTENS_THREAD::run()
{
    qDebug() << "LISTENS_THREAD Started";
    tcp_server = new QTcpServer();

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)){
            local_ipAddress = address.toString();
            qDebug() << local_ipAddress;
            //break;
        }
    }

    // if we did not find one, use IPv4 localhost
   if (local_ipAddress.isEmpty())
        local_ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << "local_ipAddress = " << local_ipAddress;
    qDebug() << "local_port = " << local_port;


    if (!tcp_server->listen(QHostAddress(local_ipAddress), local_port)) {
        qDebug() << "Error tcp_server could not listen!!!";
        return;
    }
    qDebug() << "Tcp Server is listening ... ";
    conid=0;
    tcp_server->setMaxPendingConnections(100);

    while (!server_finished) {
        if (tcp_server->waitForNewConnection(100)) {
            //qDebug() << "tcp_server::run: got a TCP connection\n";
            //process_mutex.lock();
            while (tcp_server->hasPendingConnections()) {
            tcp_client = tcp_server->nextPendingConnection();
            tcp_client->waitForReadyRead(100);

            QByteArray 	byteArray = tcp_client->readAll();
            QString s_data = byteArray.data();

            process_queue.push_back(s_data);

            tcp_client->close();
            tcp_client->abort();
            //process_mutex.unlock();
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

            emit SendSomeData(q_str);

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

int NSOCKET::StartListenService(MainWindow *mw) {

    if (server_started)
        return 0;
    server_started = true;

    // Start threads
    lthread = new LISTENS_THREAD;
    sthread = new SERVICE_THREAD;

    lthread->start();
    sthread->start();

    QObject::connect(
                sthread,
                SIGNAL(SendSomeData(QString)),
                mw,
                SLOT(MessageSlot(QString))
                );


	return 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************


