#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QByteArray>
#include <QMap>
#include <QStringList>
/// \brief auth отвечавет за авторизацию (вход в систему)
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray auth(QString login, QString password);

/// \brief reg отвечавет за регистрацию в системе
/// \param QString login, QString password
/// \return QByteArray response
///
QByteArray reg(QString login, QString password);

#endif // FUNCTIONS_H
