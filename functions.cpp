#include "functions.h"


QByteArray auth(QString login, QString password){
    return QByteArray("Авторизация!.!\r\n");
}

QByteArray reg(QString login, QString password){
    return QByteArray("Регситрация!.!\r\n");
}
