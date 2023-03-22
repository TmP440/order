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
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray log_out(QString login, QString password);

/// \brief reg отвечает за регистрацию в системе
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray reg(QString login, QString password);

/// \brief invalid_request отвечает за регистрацию в системе
/// \param QString login, QString password
/// \return QByteArray response
///

QByteArray invalid_request();

/// \brief change_password отвечает за смену пароля в системе
/// \param QString old_pass, QString new_pass_1, QString new_pass_2
/// \return QByteArray response
///
QByteArray change_password(QString old_pass, QString new_pass_1, QString new_pass_2);

/// \brief start_task отвечает за смену пароля в системе
/// \param QString old_pass, QString new_pass_1, QString new_pass_2
/// \return QByteArray response
///
QByteArray start_task(QString);

/// \brief check_task отвечает за проверку задания
/// \param int, QString
/// \return QByteArray response
///
QByteArray check_task(int, QString);

/// \brief parsing отвечает за вызов различных функций в зависимости от введенной команды
/// \param QString command
/// \return QByteArray response
///
void parsing(QString command);

#endif // FUNCTIONS_H
