#include "singletondb.h"

DatabaseDestroyer::~DatabaseDestroyer(){delete p_instance;}
void DatabaseDestroyer::initialize(SingletonDB * p) {p_instance = p;}

void SingletonDB::openDB(){
    if (db.isOpen()) {
          return;
    }

    qDebug()<<"MyDB()\n";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MATH");

    if(!db.open())
        qDebug()<<db.lastError().text();
}


//void SingletonDB::insertUser(QString login, QString password, int position_id){
//    QSqlQuery query(db);
//    query.prepare("INSERT INTO User (login, password, position_id) "
//                  "VALUES (:login, :password, :position_id)");
//    query.bindValue(":login", login);
//    query.bindValue(":password", password);
//    query.bindValue(":position_id", position_id);
//
//    if(!query.exec())
//        qDebug()<<query.lastError().text();
//}


void SingletonDB::createDB(){
    SingletonDB::getInstance();
    openDB();
    createTables();
}


SingletonDB* SingletonDB::getInstance() {
    if (!p_instance)
    {
        p_instance = new SingletonDB();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}


void SingletonDB::createTables(){
    QSqlQuery query(db);

    query.exec("CREATE TABLE IF NOT EXISTS name_user("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "surname VARCHAR(30) NOT NULL,"
               "firstname VARCHAR(30) NOT NULL,"
               "middle_name VARCHAR(30) NOT NULL,"
               "role int NOT NULL"
               ")");

    query.exec("CREATE TABLE IF NOT EXISTS task_name("
               "user_id bigint NOT NULL,"
               "number_task int NOT NULL,"
               "correctness int NOT NULL"
               "FOREIGN KEY(user_id) REFERENCES name_user(user_id)"
               ")");

    query.exec("CREATE TABLE IF NOT EXISTS task_name("
               "user_id bigint NOT NULL,"
               "login VARCHAR(30) NOT NULL,"
               "password VARCHAR(30) NOT NULL,"
               "FOREIGN KEY(user_id) REFERENCES name_user(user_id)"
               ")");

}

QSqlDatabase SingletonDB::db;
SingletonDB* SingletonDB::p_instance;
DatabaseDestroyer SingletonDB::destroyer;
