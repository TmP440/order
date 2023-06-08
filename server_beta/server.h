#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class server : public QTcpServer {
    Q_OBJECT
public:
    server();
    QTcpSocket *socket;
    QVector <QTcpSocket*> sockets;
    QByteArray data;
    void SendToClient(QString str);
    quint16 nextBlockSize;

public slots:
    void slotClientDisconnected();
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
