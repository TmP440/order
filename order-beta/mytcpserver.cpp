#include "mytcpserver.h"
#include "functions.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    int i = 0;
    while(i < mTcpSocket.length())
        mTcpSocket[i]->close();
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){

    if(server_status==1){
        QTcpSocket* cur_socket;
        cur_socket = mTcpServer->nextPendingConnection();
        cur_socket->write("Hello, World!!! I am echo server!\r\n");
        connect(cur_socket, &QTcpSocket::readyRead, this,&MyTcpServer::slotServerRead);
        connect(cur_socket,&QTcpSocket::disconnected, this,&MyTcpServer::slotClientDisconnected);
        mTcpSocket.push_back(cur_socket);
    }
}

void MyTcpServer::slotServerRead(){
    QByteArray array;
    QTcpSocket *cur_socket = (QTcpSocket*)sender();
    while(cur_socket->bytesAvailable()>0)
    {
        array.append(cur_socket->readAll());
    }
    if(array.right(1) == "\n")
    {
        cur_socket->write(parsing(array));
    }
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *cur_socket = (QTcpSocket*)sender();
    cur_socket->close();
}
