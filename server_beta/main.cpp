#include <QCoreApplication>
#include "server.h"
#include "singletondb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SingletonDB::createDB();
    server s;
    return a.exec();
}
