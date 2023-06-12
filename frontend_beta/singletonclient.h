#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H
#include <QMessageBox>
#include <QTcpSocket>

class singletonClient
{
public:
    singletonClient(const singletonClient&) = delete;

    static singletonClient& Get();

    /// \brief sendToServer отправляет данные на сервер
    /// \param
    /// \return
    ///
    void sendToServer(QString str);

    /// \brief QDataIn проверяет целостность входящих данных
    /// \param
    /// \return
    ///
    void QDataIn();
    QTcpSocket *socket;
    QByteArray data;
    quint16 nextBlockSize;
    QString str = "";
private:
    singletonClient() {};


};

#endif // SINGLETONCLIENT_H
