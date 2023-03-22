#include "functions.h"
#include <iostream>
#include <Windows.h>


QByteArray log_in(QString login, QString password){
    return QByteArray("Авторизация!.!\r\n");
}

QByteArray log_out(QString login, QString password){
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
    QStringList parts = command.split(" ");
    std::cout << &parts;
}

int main() {
    parsing("Привет как дела");
    return 0;
}
