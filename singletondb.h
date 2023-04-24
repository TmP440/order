#ifndef SINGLETONDB_H
#define SINGLETONDB_H
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QString>


class SingletonDB;

class DatabaseDestroyer
{
    private:
        SingletonDB * p_instance;
    public:
        ~DatabaseDestroyer();
        void initialize(SingletonDB * p);
};


class SingletonDB
{
private:
    static SingletonDB* p_instance;
    static DatabaseDestroyer destroyer;

    static QSqlDatabase db;

    static void openDB();
    static void createTables();
    SingletonDB() {};
    SingletonDB(const SingletonDB&) = delete;
    SingletonDB& operator = (SingletonDB&) = delete;
    ~SingletonDB() {};
    friend class DatabaseDestroyer;

public:
    static SingletonDB* getInstance();


    /// \brief createDB создаёт базу данных
    /// \param void
    /// \return void
    static void createDB();


    /// \brief insertUser добавляет пользователя в базу
    /// \param QString login, QString password
    /// \return void
    static void insertUser(QString login, QString password);


    /// \brief user_fio добавление пользователю ФИО
    /// \param QString login, QString surname, QString firstname, QString middle_name, int role
    /// \return void
    static void user_fio(QString login, QString surname, QString firstname, QString middle_name, int role);


    /// \brief changePassword изменяет пароль пользователя для входа
    /// \param QString login, QString oldPassword, QString newPassword
    /// \return bool
    static bool changePassword(QString login, QString oldPassword, QString newPassword);


    /// \brief log_in вход в аккаунт
    /// \param QString login, QString password
    /// \return bool
    static bool log_in(QString login, QString password);


    /// \brief check_task функция передает серверу информацию об ответе, 1 - правильно, 0 - неправильно
    /// \param QString login, int num_task, int correct
    /// \return bool
    static void check_task(QString login, int num_task, int correct);


    /// \brief close закрывает базу данных
    /// \param void
    /// \return void
    static void close();
};

#endif // SINGLETONDB_H
