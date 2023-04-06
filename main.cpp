#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include "SingletonClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingletonClient::getInstance();
   
   // SingletonClient::getInstance()->send_msg_to_server("auth&user&123");


    return a.exec();
}
