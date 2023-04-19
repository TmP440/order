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
        static SingletonDB * p_instance;
        static DatabaseDestroyer destroyer;

        static QSqlDatabase db;

        static void openDB();
        static void createTables();
        SingletonDB(){};
        SingletonDB(const SingletonDB& ) = delete;
        SingletonDB& operator = (SingletonDB &) = delete;
        ~SingletonDB(){};
        friend class DatabaseDestroyer;

        static void generate_sevices();
    public:
        static SingletonDB* getInstance();

        /// \brief createDB создаёт базу данных
        /// \param void
        /// \return void
        static void createDB();

#endif // SINGLETONDB_H
