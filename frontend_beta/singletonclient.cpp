#include "singletonclient.h"
#include <QMessageBox>
#include <QTcpSocket>

singletonClient& singletonClient::Get()
{
    static singletonClient instance;
    return instance;
}

void singletonClient::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
}

void singletonClient::QDataIn()
{
    singletonClient::Get().str = "";
    QDataStream in(singletonClient::Get().socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "QDataStream::Ok";
        for(;;)
        {
            if(singletonClient::Get().nextBlockSize == 0)
            {
                if(singletonClient::Get().socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> singletonClient::Get().nextBlockSize;
                qDebug() << singletonClient::Get().nextBlockSize;
            }
            if(singletonClient::Get().socket->bytesAvailable() < singletonClient::Get().nextBlockSize)
            {
                break;
                qDebug() << "срабатала";
            }
        in >> singletonClient::Get().str;
        singletonClient::Get().nextBlockSize = 0;
        qDebug() << singletonClient::Get().str;
        break;
        }
    }
}
