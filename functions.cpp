#include "functions.h"


QByteArray log_in(QString login, QString password){
    return QByteArray("Авторизация!.!\r\n");
}

QByteArray log_out(){
    return QByteArray("Выход из системы!.!\r\n");
}

QByteArray reg(QString login, QString password){
    return QByteArray("Регистрация!.!\r\n");
}

QByteArray invalid_request(){
    return QByteArray("Ошибка! Такой команды нет\n или неверное кол-во коканд");
}

QByteArray change_password(QString old_pass, QString new_pass_1, QString new_pass_2){
    return QByteArray("Пароль изменен!");
}

QByteArray start_task(QString){
    return QByteArray("Ваша задача...\r\n");
}

QByteArray check_task(int, QString){
    return QByteArray("Проверка задачи...\r\n");
}

void parsing(QString command){
    QStringList parts = command.left(command.length() - 2).split(" ");
    if (parts[0] == "login") log_in(parts[1], parts[2]);
    else if (parts[0] == "logout") log_out();
    else if (parts[0] == "change_password") change_password(parts[1], parts[2], parts[3]);
    else if (parts[0] == "start_task") start_task(parts[1]);
    else if (parts[0] == "check_task") check_task(parts[1].toInt(), parts[2]);
    else invalid_request();

}
