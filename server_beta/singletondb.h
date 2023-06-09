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
    /// \param QString login, QString password, int conn_with
    /// \return void
    static void insertUser(QString login, QString password, int conn_with);


    /// \brief user_fio добавление пользователю ФИО, 0 - Преподаватель, 1 - Ученик
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


    /// \brief check_connected_with проверяет к кому привязан пользователь
    /// \param QString login
    /// \return qint32
    static qint32 check_connected_with(QString login);


    /// \brief who_connected_to_me проверяет кто привязан к пользователю
    /// \param QString login
    /// \return QString
    static QString who_connected_to_me(QString login);

    /// \brief getID возвращает ID пользователя
    /// \param QString login
    /// \return QByteArray
    static QString getID(QString login);

    /// \brief check_login проврека уникальности логина
    /// \param QString login
    /// \return bool
    static bool check_login(QString login);


    /// \brief log_out выход из системы
    /// \param QString login
    /// \return void
    static void log_out(QString login);

    /// \brief check_task функция передает серверу информацию об ответе, 1 - правильно, 0 - неправильно
    /// \param QString login, QString num_task, QString correct
    /// \return bool
    static void check_task(QString login, QString num_task, QString correct);

    /// \brief student_stats возвращает результат запроса со столбцами (номер задания, выполнено/не выполнено)
    /// \param QString login
    /// \return QList<QStringList>
    static QList<QStringList> student_stats(QString login);

    /// \brief teacher_stats возвращает результат запроса, в котором приведана таблица успеваемости учеников преподавателя
    /// \param QString login
    /// \return QList<QStringList>
    static QList<QStringList> teacher_stats(QString login);

    /// \brief close закрывает базу данных
    /// \param void
    /// \return void
    static void close();
};

#endif // SINGLETONDB_H
