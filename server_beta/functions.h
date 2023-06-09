#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QByteArray>
#include <QMap>
#include <QStringList>
#include <queue>
#include <limits>
#include <vector>
#include <QRandomGenerator>

/// \brief log_in отвечает за вход
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray log_in(QString login, QString password);

/// \brief log_out отвечает за выход из системы
/// \param QString login
/// \return QByteArray response
///
QByteArray log_out(QString login);

/// \brief reg отвечает за регистрацию в системе
/// \param QString login, QString password, int conn_with
/// \return QByteArray response
///
QByteArray reg(QString login, QString password, int conn_with);

/// \brief reg_fio отвечает за регистрацию ФИО и роли в системе
/// \param QString login, QString surname, QString firstname, QString middle_name, int role
/// \return QByteArray response
///
QByteArray reg_fio(QString login, QString surname, QString firstname, QString middle_name, int role);

/// \brief check_connected_with проверяет к кому привязан пользователь
/// \param QString login
/// \return QByteArray
///
QByteArray check_connected_with(QString login);

/// \brief who_connected_to_me проверяет кто привязан к пользователю
/// \param QString login
/// \return QByteArray
///
QByteArray who_connected_to_me(QString login);

/// \brief getID возвращает ID пользователя
/// \param QString login
/// \return QByteArray
///
QByteArray getID(QString login);

/// \brief invalid_request отвечает за вывод сообщения при несуществующей команды или неверном кол-ве параметров той или иной команды
/// \param
/// \return QByteArray response
///
QByteArray invalid_request();

/// \brief change_password отвечает за смену пароля в системе
/// \param QString login, QString old_pass, QString new_pass
/// \return QByteArray response
///
QByteArray change_password(QString login, QString old_pass, QString new_pass);

/// \brief check_task функция передает серверу информацию об ответе, 1 - правильно, 0 - неправильно
/// \param QString login, QString num_task, QString correct
/// \return QByteArray response
///
QByteArray check_task(QString login, QString num_task, QString correct);

/// \brief parsing отвечает за вызов различных функций в зависимости от введенной команды
/// \param QString command
/// \return QByteArray response
///
QByteArray parsing(QString command);

/// \brief show_commands функция, выводящая в сервер список команд и их аргументы
/// \param
/// \return QByteArray response
///
QByteArray show_commands();

/// \brief show_students_stats(QString login) выводит информацию об успеваемости ученика
/// \param QString login
/// \QByteArray response
///
QByteArray show_students_stats(QString login);

/// \brief show_teacher_stats вывод статистики преподавателя
/// \param QString login
/// \return QByteArray respone
///
QByteArray show_teacher_stats(QString login);

/// \brief task_4 вывод статистики преподавателя
/// \param QString login, QString length, QString start, QString end, QString graf, QString answer
/// \return QByteArray respone
///
QByteArray task_4(QString login, QString length, QString graf, QString answer);

#endif // FUNCTIONS_H

