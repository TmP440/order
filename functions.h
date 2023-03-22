#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QByteArray>
#include <QMap>
#include <QStringList>
/// \brief log_in отвечавет за вход
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray log_in(QString login, QString password);

/// \brief log_out отвечавет за выход из системы
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray log_out(QString login, QString password);

/// \brief reg отвечавет за регистрацию в системе
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray reg(QString login, QString password);

#endif // FUNCTIONS_H
