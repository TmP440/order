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
    return QByteArray("Ошибка! Такой команды нет или неверное кол-во коканд\r\n");
}

QByteArray change_password(QString old_pass, QString new_pass_1, QString new_pass_2){
    return QByteArray("Пароль изменен!");
}

QByteArray start_task(QString is_start){
    return QByteArray("Ваша задача...\r\n");
}

QByteArray check_task(int numb, QString ready){
    return QByteArray("Проверка задачи...\r\n");
}

QByteArray parsing(QString command){
    QStringList parts = command.left(command.length() - 2).split(" ");
    if (parts[0] == "login") return log_in(parts[1], parts[2]);
    else if (parts[0] == "logout") return log_out();
    else if (parts[0] == "change_password") return change_password(parts[1], parts[2], parts[3]);
    else if (parts[0] == "start_task") return start_task(parts[1]);
    else if (parts[0] == "check_task") return check_task(parts[1].toInt(), parts[2]);
    else return invalid_request();

}
