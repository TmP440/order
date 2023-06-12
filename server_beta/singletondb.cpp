#include "singletondb.h"

DatabaseDestroyer::~DatabaseDestroyer(){delete p_instance;}
void DatabaseDestroyer::initialize(SingletonDB * p) {p_instance = p;}

void SingletonDB::openDB(){
    if (db.isOpen()) {
          return;
    }

    qDebug()<<"MyDB()\n";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MATH"); //для qt
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
                "password NVARCHAR(30) NOT NULL,"
                "status NVARCHAR(1) DEFAULT '0',"
                "connected_with INTEGER NOT NULL DEFAULT -1"
                ");");

    query.exec("CREATE TABLE IF NOT EXISTS task_name("
               "task_name_id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "login_user NVARCHAR(30),"
               "number_task NVARCHAR(2) NOT NULL,"
               "correctness NVARCHAR(1) NOT NULL,"
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

void SingletonDB::insertUser(QString login, QString password, int conn_with){
    qDebug() << login << password << "\n";
    qDebug() << typeid(login).name() << typeid(password).name() << "\n";
    bool ok = SingletonDB::check_login(login);
    if (!ok)
    {
        QSqlQuery query(db);
        query.prepare("INSERT INTO data_user (login, password, connected_with) "
                    "VALUES (:login, :password, :conn_with)");
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        query.bindValue(":conn_with", conn_with);
        if(!query.exec())
            qDebug() << query.lastError().text();
        else
        {
            for (int i = 1; i < 6; i++)
            {
                query.prepare("INSERT INTO task_name (login_user, number_task, correctness) "
                              "VALUES (:login_user, :number_task, 0)");
                query.bindValue(":login_user", login);
                query.bindValue(":number_task", QString::number(i));
                if(!query.exec())
                    qDebug() << query.lastError().text();
            }
        }
    }
    else
    {
        qDebug() << "Пользователь с таким логином уже есть!!!\r\n";
    }
}

bool SingletonDB::check_login(QString login)
{
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM data_user WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next())
    {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}



bool SingletonDB::log_in(QString login, QString password){
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM data_user WHERE login = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if(count > 0) {
            query.prepare("UPDATE data_user SET status = 1 "
                          "WHERE login = :login;");
            query.bindValue(":login", login);
            if(!query.exec())
                qDebug()<<query.lastError().text();
            return true;
            }
        }
    return false;
}

qint32 SingletonDB::check_connected_with(QString login)
{
    QSqlQuery query(db);
    query.prepare("SELECT connected_with FROM data_user WHERE login = :login");
    query.bindValue(":login", login);
    if (query.exec() && query.next()) {
        qint32 connect = query.value(0).toInt();
        return connect;
    }
    return 0;
}

void SingletonDB::log_out(QString login){
    QSqlQuery query(db);
    query.prepare("UPDATE data_user SET status = 0 "
                  "WHERE login = :login;");
    query.bindValue(":login", login);
    if(!query.exec())
        qDebug() << query.lastError().text();
}

void SingletonDB::user_fio(QString login, QString surname, QString firstname, QString middle_name, int role){
    QSqlQuery query(db);
        query.prepare("INSERT INTO name_user (login_user, surname, firstname, middle_name, role) "
                      "VALUES (:login, :surname, :firstname, :middle_name, :role)");
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
        query.prepare("UPDATE data_user SET password = :newPassword WHERE login = :login");
        query.bindValue(":newPassword", newPassword);
        query.bindValue(":login", login);
        return true;
    }
        if(!query.exec())
            qDebug()<<query.lastError().text();
    return false;
}

void SingletonDB::check_task(QString login, QString num_task, QString correct){
    qDebug() << typeid(login).name() << typeid(num_task).name() << typeid(correct).name() << "\n";
    QSqlQuery query(db);
    query.prepare("UPDATE task_name SET correctness = :correct "
                  "WHERE login_user = :login "
                  "AND number_task = :num_task;");
    query.bindValue(":correct", correct);
    query.bindValue(":login", login);
    query.bindValue(":num_task", num_task);
    if(!query.exec())
        qDebug()<<query.lastError().text();
}

QList<QStringList> SingletonDB::student_stats(QString login)
{
    QList<QStringList> rows;
    QSqlQuery query(db);
    query.prepare("SELECT number_task, correctness "
                  "FROM task_name "
                  "WHERE login_user = :login;");
    query.bindValue(":login", login);
    if(query.exec())
    {
        while (query.next()) {
            QStringList row;
            row << query.value("number_task").toString();
            row << query.value("correctness").toString();
            rows.append(row);
        }
    }
    return rows;
}

QList<QStringList> SingletonDB::teacher_stats(QString login)
{
    QList<QStringList> rows;
    QSqlQuery query(db);
    query.prepare("SELECT surname, firstname, middle_name, number_task, correctness "
                  "FROM name_user AS n_u "
                  "JOIN task_name AS t_n ON n_u.login_user = t_n.login_user "
                  "JOIN data_user ON t_n.login_user = login "
                  "WHERE t_n.login_user IN (SELECT login FROM data_user "
                                          "WHERE connected_with = "
                                           "(SELECT user_id FROM data_user "
                                           "WHERE login = :login));");
    query.bindValue(":login", login);
    if(query.exec())
    {
        while (query.next()) {
            QStringList row;
            row << query.value("surname").toString();
            row << query.value("firstname").toString();
            row << query.value("middle_name").toString();
            row << query.value("number_task").toString();
            row << query.value("correctness").toString();
            rows.append(row);
        }
    }
    return rows;
}

QString SingletonDB::who_connected_to_me(QString login)
{
    QString result;
    QSqlQuery query(db);
    query.prepare("SELECT login FROM data_user "
                  "WHERE (SELECT user_id FROM data_user WHERE login = :login) = connected_with;");
    query.bindValue(":login", login);
    if(query.exec())
    {
        while (query.next()) {
            result = result + query.value("login").toString() + " ";
        }
        return result;
    }
    else
    {
        qDebug()<< query.lastError().text();
        return "";
    }
}

QString SingletonDB::getID(QString login)
{
    QSqlQuery query(db);
    query.prepare("SELECT user_id FROM data_user WHERE login = :login;");
    query.bindValue(":login", login);
    if(query.exec())
    {
        query.next();
        return query.value("user_id").toString();
    }
    else
    {
        qDebug()<< query.lastError().text();
        return "";
    }
}

QSqlDatabase SingletonDB::db;
SingletonDB* SingletonDB::p_instance;
DatabaseDestroyer SingletonDB::destroyer;
