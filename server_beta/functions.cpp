#include "functions.h"
#include "singletondb.h"
#include <QDebug>


QByteArray log_in(QString login, QString password){
    bool ok = SingletonDB::log_in(login,password);
    if (ok)
    {
        return QByteArray("1 " + check_connected_with(login));
    }
    return QByteArray("0");
}

QByteArray log_out(QString login){
    SingletonDB::log_out(login);
    qDebug() << login << "logged out\n";
    return QByteArray("1");
}

QByteArray reg(QString login, QString password, int conn_with){
    qDebug() << login << password << "\n";
    SingletonDB::insertUser(login, password, conn_with);
    return QByteArray("1");
}

QByteArray reg_fio(QString login, QString surname, QString firstname, QString middle_name, int role){
    SingletonDB::user_fio(login, surname, firstname, middle_name, role);
    return QByteArray("null");
}

QByteArray invalid_request(){
    return QByteArray("Ошибка! Такой команды нет или неверное кол-во команд\r\n");
}

QByteArray change_password(QString login, QString old_pass, QString new_pass){
    bool ok = SingletonDB::changePassword(login, old_pass, new_pass);
    if (ok) return QByteArray("Пароль изменен!");
    return QByteArray("Введите данные заново\r\n");
}

QByteArray check_task(QString login, QString num_task, QString correct){
    SingletonDB::check_task(login, num_task, correct);
    return QByteArray("Проверка задачи...\r\n");
}

QByteArray check_connected_with(QString login)
{
    return QByteArray::number(SingletonDB::check_connected_with(login));
}

QByteArray who_connected_to_me(QString login)
{
    return (SingletonDB::who_connected_to_me(login)).toUtf8();
}

QByteArray getID(QString login)
{
    return (SingletonDB::getID(login)).toUtf8();
}

QByteArray show_student_stats(QString login)
{
    QList<QStringList> records = SingletonDB::student_stats(login);
    QString result = "\r\nНомер\tОценка\r\n";
    if (!records.isEmpty())
    {
        for (int i = 0; i < records.size(); i++)
        {
            QString task_num = records[i][0];
            QString is_correct = records[i][1];
            result += task_num + "\t" + is_correct + "\r\n";
        }
        QByteArray to_console = result.toUtf8();
        return to_console.append("\r\nСтатистика ученика: ").append(login.toUtf8()).append("\r\n");
    }
    else return QByteArray("Невозможно вывести статистику ученика: ").append(login.toUtf8()).append("\r\n");
}

QByteArray show_teacher_stats(QString login)
{
    QList<QStringList> records = SingletonDB::teacher_stats(login);
    QString fullName = "";
    QString result = "";
    int summ = 0;
    int count = 0;
    if (!records.isEmpty())
    {
        for (int i = 0; i < records.size(); i++)
        {
            QString dif_name = records[i][0] + " " + records[i][1] + " " + records[i][2];
            if (dif_name != fullName) {
                fullName = dif_name;
                result += "\r\n" + fullName + ": " + "\r\nНомер\tОценка\r\n";
                summ = 0;
                count = 0;
            }
            QString task_num = records[i][3];
            QString is_correct = records[i][4];
            result += task_num + "\t" + is_correct + "\r\n";
            summ += is_correct.toInt();
            count += 1;
            if (count == 5) result += "Кол-во выполненых заданий: " + QString::number(summ) + "\r\n";
        }
        QByteArray to_console = result.toUtf8();
        return to_console.append("\r\nСтатистика преподавателя: ").append(login.toUtf8()).append("\r\n");
    }
    else return QByteArray("Невозможно вывести статистику преподавателя: ").append(login.toUtf8()).append("\r\n");
}

QByteArray show_commands(){
    return QByteArray("login [login, password]\r\n"
                      "logout [login]\r\n"
                      "reg [login, password, connected_with]\r\n"
                      "reg_fio [login, surname, firstname, middle_name, role]\r\n"
                      "change_password [login, old_password, new_password]\r\n"
                      "check_task [login, num_task, correct]\r\n"
                      "show_stud_stats [login]\r\n");
}

QByteArray parsing(QString command){
    QStringList parts = command.left(command.length()).split(" ");
    //QStringList parts = command.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    qDebug() << parts << "\n";
    if (parts[0] == "login") return log_in(parts[1], parts[2]);
    else if (parts[0] == "commands") return show_commands();
    else if (parts[0] == "logout") return log_out(parts[1]);
    else if (parts[0] == "reg") return reg(parts[1], parts[2], parts[3].toInt());
    else if (parts[0] == "reg_fio") return reg_fio(parts[1], parts[2], parts[3], parts[4], parts[5].toInt());
    else if (parts[0] == "change_password") return change_password(parts[1], parts[2],  parts[3]);
    else if (parts[0] == "check_task") return check_task(parts[1], parts[2], parts[3]);
    else if (parts[0] == "show_stud_stats") return show_student_stats(parts[1]);
    else if (parts[0] == "show_teacher_stats") return show_teacher_stats(parts[1]);
    else if (parts[0] == "ccw") return check_connected_with(parts[1]);
    else if (parts[0] == "wctm") return who_connected_to_me(parts[1]);
    else if (parts[0] == "getid") return getID(parts[1]);
    else return invalid_request();
}
