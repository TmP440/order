#ifndef db_h
#define db_h

#include <QCoreApplication>

#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "Singleton.h"

class MyDB : public Singleton
{
private:
    MyDB() {}
    MyDB& operator=(MyDB&) = delete;
    MyDB(const MyDB &Db) = delete;
    static QSqlDatabase mydb;
    //static QSqlQuery query;

    static void openDB(){
        qDebug()<<"MyDB()\n";
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Test");
        if(!mydb.open())
            qDebug()<<mydb.lastError().text();
    }
public:
    static QString query_select(){
        QSqlQuery query(mydb);
        query.exec("SELECT * FROM User");
        if (query.next()) {
            QSqlRecord rec = query.record();
            const int loginIndex = rec.indexOf("login"); // номер "столбца"
            const int passwordIndex = rec.indexOf("password");
            return query.value(loginIndex).toString()+" "+query.value(passwordIndex).toString();
        } else
            return "Sorry, something went wrong";
    }

    ~MyDB() override{
        if(mydb.isOpen())
            mydb.close();
        qDebug()<<"~MyDB";
    }

    static MyDB* getInstance(){
        if (!mydb.isOpen())
        {
            openDB();
        }
        return (MyDB*)Singleton::getInstance();
    }
    static void close(){
        if(mydb.isOpen())
            mydb.close();
    }
};

QSqlDatabase MyDB::mydb;
//QSqlQuery db::query;

#endif
