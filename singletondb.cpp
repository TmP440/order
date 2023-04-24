#include "singletondb.h"

DatabaseDestroyer::~DatabaseDestroyer(){delete p_instance;}
void DatabaseDestroyer::initialize(SingletonDB * p) {p_instance = p;}

void SingletonDB::openDB(){
    if (db.isOpen()) {
          return;
    }

    qDebug()<<"MyDB()\n";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../SingltetonTest/MATH"); //для qt
    //db.setDatabaseName("MATH"); //для докера

    if(!db.open())
        qDebug()<<db.lastError().text();
}


void SingletonDB::close(){
    if(db.isOpen())
        db.close();
}


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


    query.exec("CREATE TABLE IF NOT EXISTS data_user("
               "user_id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "login NVARCHAR(30) NOT NULL,"
               "password NVARCHAR(30) NOT NULL"
               ");");


    query.exec("CREATE TABLE IF NOT EXISTS task_name("
               "login_user NVARCHAR(30) PRIMARY KEY,"
               "number_task int NOT NULL,"
               "correctness int NOT NULL"
               "FOREIGN KEY(login_user) REFERENCES data_user(login)"
               ");");


    query.exec("CREATE TABLE IF NOT EXISTS name_user("
               "login_user NVARCHAR(30) PRIMARY KEY,"
               "surname NVARCHAR(30) NOT NULL,"
               "firstname NVARCHAR(30) NOT NULL,"
               "middle_name NVARCHAR(30) NOT NULL,"
               "role int NOT NULL,"
               "FOREIGN KEY(login_user) REFERENCES data_user(login)"
               ");");
}

void SingletonDB::insertUser(QString login, QString password){
    qDebug() << login << password << "\n";
    qDebug() << typeid(login).name() << typeid(password).name() << "\n";
    QSqlQuery query(db);
        query.prepare("INSERT INTO data_user (login, password) "
                      "VALUES (:login, :password)");
        query.bindValue(":login",login);
        query.bindValue(":password",password);

        if(!query.exec())
            qDebug()<<query.lastError().text();
        else{
           query.exec();
        }
}


bool SingletonDB::log_in(QString login, QString password){
    QSqlQuery query(db);
        query.prepare("SELECT COUNT(*) FROM data_user WHERE login = :login AND password = :password");
        query.bindValue(":login", login);
        query.bindValue(":password", password);

        if (!query.exec()) {
            qDebug() << query.lastError().text();
            return false;
        }

        return true;
}

void SingletonDB::user_fio(QString login, QString surname, QString firstname, QString middle_name, int role){
    QSqlQuery query(db);
        query.prepare("INSERT INTO name_user (login, surname, firstname, middle_name, role) "
                      "VALUES (:login, :password)");
        query.bindValue(":login", login);
        query.bindValue(":surname", surname);
        query.bindValue(":firstname", firstname);
        query.bindValue(":middle_name", middle_name);
        query.bindValue(":role", role);


        if(!query.exec())
            qDebug()<<query.lastError().text();
}

bool SingletonDB::changePassword(QString login, QString oldPassword, QString newPassword){
    QSqlQuery query(db);
    bool ok = SingletonDB::log_in(login, oldPassword);
    if (ok){
        query.prepare("UPDATE data_user SET password = :newPassword WHERE user_id = :user_id");
        query.bindValue(":newPassword", newPassword);
        query.bindValue(":login", login);
        return true;
    }
        if(!query.exec())
            qDebug()<<query.lastError().text();
    return false;
}

void SingletonDB::check_task(QString login, int num_task, int correct){
    QSqlQuery query(db);
    query.prepare("INSERT INTO task (login, num_task, correct) "
                  "VALUES (:login, :num_task, :correct)");
    query.bindValue(":login", login);
    query.bindValue(":num_task", num_task);
    query.bindValue(":correct", correct);
    if(!query.exec())
        qDebug()<<query.lastError().text();

}

QSqlDatabase SingletonDB::db;
SingletonDB* SingletonDB::p_instance;
DatabaseDestroyer SingletonDB::destroyer;
