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

/// \brief invalid_request отвечает за вывод сообщения при несуществующей команды
/// или неверном кол-ве параметров той или иной команды
/// \return QByteArray response
///
QByteArray invalid_request();

/// \brief change_password отвечает за смену пароля в системе
/// \param QString old_pass, QString new_pass_1, QString new_pass_2
/// \return QByteArray response
///
QByteArray change_password(QString old_pass, QString new_pass_1, QString new_pass_2);

/// \brief start_task отвечает за запуск задания
/// \param QString is_start
/// \return QByteArray response
///
QByteArray start_task(QString is_start);

/// \brief check_task отвечает за проверку задания
/// \param int numb, QString
/// \return QByteArray response
///
QByteArray check_task(int numb, QString ready);

/// \brief parsing отвечает за вызов различных функций в зависимости от введенной команды
/// \param QString command
/// \return QByteArray response
///
QByteArray parsing(QString command);

#endif // FUNCTIONS_H

