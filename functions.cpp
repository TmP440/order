#include "functions.h"
#include "singletondb.h"


QByteArray log_in(QString login, QString password){
    bool ok = SingletonDB::log_in(login,password);
    if (ok) return QByteArray("Вы вошли\r\n");
    return QByteArray("Пользователь не найден\r\n");
}

QByteArray log_out(){
    return QByteArray("Выход из системы!.!\r\n");
}

QByteArray reg(QString login, QString password){
    SingletonDB::insertUser(login, password);
    return QByteArray("Регистрация!.!\r\n");
}

QByteArray reg_fio(QString login, QString surname, QString firstname, QString middle_name, int role){
    SingletonDB::user_fio(login, surname, firstname, middle_name, role);
    return QByteArray("Регистрация ФИО!.!\r\n");
}

QByteArray invalid_request(){
    return QByteArray("Ошибка! Такой команды нет или неверное кол-во коканд\r\n");
}

QByteArray change_password(QString login, QString old_pass, QString new_pass){
    bool ok = SingletonDB::changePassword(login, old_pass, new_pass);
    if (ok) return QByteArray("Пароль изменен!");
    return QByteArray("Введите данные заново\r\n");
}

QByteArray check_task(QString login, int num_task, int correct){
    SingletonDB::check_task(login, num_task, correct);
    return QByteArray("Проверка задачи...\r\n");
}

QByteArray parsing(QString command){
    QStringList parts = command.left(command.length() - 2).split(" ");
    if (parts[0] == "login") return log_in(parts[1], parts[2]);
    else if (parts[0] == "logout") return log_out();
    else if (parts[0] == "reg") return reg(parts[1], parts[2]);
    else if (parts[0] == "reg_fio") return reg_fio(parts[1], parts[2], parts[3], parts[4], parts[5].toInt());
    else if (parts[0] == "change_password") return change_password(parts[1], parts[2],  parts[3]);
    else if (parts[0] == "check_task") return check_task(parts[1], parts[2].toInt(), parts[3].toInt());
    else return invalid_request();

}
