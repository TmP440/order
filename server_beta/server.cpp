#include "server.h"
#include "functions.h"

server::server() {
    if(this->listen(QHostAddress::Any, 4747))
    {
        qDebug() << "start";
    }
    else
    {
        qDebug() <<"error";
    }
    nextBlockSize = 0;
}

void server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &server::slotClientDisconnected);

    sockets.push_back(socket);
    qDebug() << "client connected " << socketDescriptor;
}

void server::slotReadyRead()
{
    QString str;
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
         qDebug() << "read...";
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                qDebug() << "nextBlockSize = 0";
                if(socket->bytesAvailable() < 2)
                {
                    qDebug() << "data < 2, break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize =" << nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                qDebug() << "data is not full, break";
                break;
            }
            in >> str;
            nextBlockSize = 0;
            qDebug() << str;
            str = parsing(str);
            qDebug() << str;
            SendToClient(str);
            break;
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void server::SendToClient(QString str)
{
   data.clear();
   QDataStream out(&data, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_6_4);
   out << quint16(0) << str;
   out.device()->seek(0);
   out << quint16(data.size() - sizeof(quint16));
   out << str;
   socket->write(data);
}

void server::slotClientDisconnected()
{
    QTcpSocket *cur_socket = (QTcpSocket*)sender();
    cur_socket->close();
}
