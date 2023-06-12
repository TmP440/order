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
    void test_case2();
    void test_case3();
    void test_case4();

};

server::server()
{

}

server::~server()
{

}

void server::test_case1()
{ 
    QVERIFY(task_1("0", "1,3,1,4,2,3,2,4") == "1");
    QVERIFY(task_1("0", "1,4,1,5,1,6,2,4,2,5,2,6,3,4,3,5,3,6") == "1");
    QVERIFY(task_1("0", "1,5,1,6,1,7,1,8,1,9,2,5,2,6,2,7,2,8,2,9,3,5,3,6,3,7,3,8,3,9,4,5,4,6,4,7,4,8,4,9") == "1");

}
void server::test_case2()
{
    QVERIFY(task_2("0", "3", "2", "0-1|0-2|", "Да") == "0");

}
void server::test_case3()
{

    QVERIFY(task_3("0", "7", "(1,2),(1,3),(1,4),(2,3),(2,6),(2,7),(3,4),(3,5),(3,7),(5,6),(6,7)", "|046||0457||036||0245||016||0157|") == "|046||0457||036||0245||016||0157|");
}
void server::test_case4()
{
    QVERIFY(task_4("0", "5", "0,1,2|0,2,6|1,2,4|1,3,1|2,3,6|2,4,7|3,4,5", "0-1-3-4") == "0");

}



QTEST_APPLESS_MAIN(server)

#include "tst_server.moc"
