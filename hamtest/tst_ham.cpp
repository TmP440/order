#include <QtTest>
#include "../order-beta/functions.cpp"
// add necessary includes here

class ham : public QObject
{
    Q_OBJECT

public:
    ham();
    ~ham();

private slots:
    void test_case1();
    void test_case2();
};

ham::ham()
{

}

ham::~ham()
{

}

void ham::test_case1()
{
QVERIFY2(hamilton(0,6213546)=="1","Неверно");
}
void ham::test_case2()
{
QVERIFY2(hamilton(0,621354)=="1","Неверно");
}
QTEST_APPLESS_MAIN(ham)

#include "tst_ham.moc"
