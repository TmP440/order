#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "singletonClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingletonClient::getInstance();
    SingletonClient::getInstance()->send_msg_to_server("1234");


    return a.exec();
}
