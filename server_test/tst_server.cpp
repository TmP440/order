#include <QtTest>
#include "../server_beta/functions.h"

// add necessary includes here

class server : public QObject
{
    Q_OBJECT

public:
    server();
    ~server();

private slots:
    void test_case1();

};

server::server()
{

}

server::~server()
{

}

void server::test_case1()
{ 
    QVERIFY(task_4("0", "5", "0,1,2|0,2,6|1,2,4|1,3,1|2,3,6|2,4,7|3,4,5", "0-1-3-4") == "1");
}

QTEST_APPLESS_MAIN(server)

#include "tst_server.moc"
