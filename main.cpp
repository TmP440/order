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
    db::getInstance();
    qDebug()<<db::query_select();
    db::close();
    qDebug()<<db::query_select();
    exit(0);

    return a.exec();
}
