#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
/// <summary>
/// 
/// </summary>
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
//    void parsing(QString data_from_client);
//    void auth(QString log, QString pass);
//    void reg(QString log, QString pass, QString name);
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    int server_status;
};
#endif // MYTCPSERVER_H







