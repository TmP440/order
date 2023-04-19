#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QByteArray>
#include <QMap>
#include <QStringList>

/// \brief log_in отвечает за вход
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray log_in(QString login, QString password);

/// \brief log_out отвечает за выход из системы
/// \return QByteArray response
///
QByteArray log_out();

/// \brief reg отвечает за регистрацию в системе
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray reg(QString login, QString password);

/// \brief reg_fio отвечает за регистрацию ФИО и роли в системе
/// \param QString login, QString surname, QString firstname, QString middle_name, int role
/// \return QByteArray response
///
QByteArray reg_fio(QString login, QString surname, QString firstname, QString middle_name, int role);

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
/// \param QString login, int num_task, int correct
/// \return QByteArray response
///
QByteArray check_task(QString login, int num_task, int correct);

/// \brief parsing отвечает за вызов различных функций в зависимости от введенной команды
/// \param QString command
/// \return QByteArray response
///
QByteArray parsing(QString command);

#endif // FUNCTIONS_H

