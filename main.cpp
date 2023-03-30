#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "db.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    MyDB::getInstance();
    qDebug()<<MyDB::query_select();
    MyDB::close();
    qDebug()<< MyDB::query_select();
    exit(0);

    return a.exec();
}
