#include "functions.h"
#include "singletondb.h"
#include <QDebug>


QByteArray log_in(QString login, QString password){
    bool ok = SingletonDB::log_in(login,password);
    if (ok) return QByteArray("Вы вошли\r\n");
    return QByteArray("Пользователь не найден\r\n");
}

QByteArray log_out(QString login){
    SingletonDB::log_out(login);
    return QByteArray("Вы вышли из системы!.!\r\n");
}

QByteArray reg(QString login, QString password, int conn_with){
    qDebug() << login << password << "\n";
    SingletonDB::insertUser(login, password, conn_with);
    return QByteArray("Регистрация!.!\r\n");
}

QByteArray reg_fio(QString login, QString surname, QString firstname, QString middle_name, int role){
    SingletonDB::user_fio(login, surname, firstname, middle_name, role);
    return QByteArray("Регистрация ФИО!.!\r\n");
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

std::string hamilton(int e, long long str){
    int i, j, N;
    // Варианты
    std::string E[12] = {
       "(1,2),(1,3),(1,5),(1,6),(2,3),(2,4),(2,6),(3,4),(3,5),(4,5),(4,6),(5,6). ",
       "(1,4),(1,5),(1,6),(1,7),(2,4),(2,7),(3,4),(3,5),(3,6),(3,7),(4,7),(5,6). ",
       "(1,2),(1,3),(1,4),(1,6),(2,3),(3,4),(3,6),(4,5),(4,6),(5,6). ",
       "(1,2),(1,3),(1,5),(1,6),(2,4),(3,4),(3,5),(3,6),(4,5),(4,6),(5,6). ",
       "(1,4),(1,5),(1,6),(1,7),(2,3),(2,4),(2,7),(3,4),(3,7),(4,5),(6,7). ",
       "(1,2),(1,3),(1,5),(1,6),(2,3),(2,4),(2,6),(3,4),(3,5),(4,5),(4,6),(5,6). ",
       "(1,2),(1,3),(1,4),(1,5),(2,4),(2,6),(2,7),(3,4),(4,5),(5,6),(5,7),(6,7). ",
       "(1,2),(1,3),(1,6),(1,7),(2,3),(2,5),(2,6),(3,4),(3,7),(4,7),(5,6),(6,7). ",
       "(1,2),(1,3),(1,5),(1,6),(2,5),(2,6),(3,7),(4,6),(4,7),(6,7). ",
       "(1,2),(1,3),(1,5),(1,7),(2,6),(3,4),(3,6),(3,7),(4,5),(4,6),(4,7),(6,7). ",
       "(1,2),(1,4),(1,5),(1,6),(2,3),(2,4),(2,7),(3,4),(3,5),(3,7),(4,5),(4,6),(4,7),(5,6),(6,7). ",
       "(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(3,5),(3,7),(4,5),(4,6),(4,7),(5,6),(5,7). " };
    std::string ver = E[e];
    // Ввод размера матрицы
       N = 7;
       // выделение памяти для матриц
       int** a = new int*[N];
       for (i = 0; i < N; i++) {
           a[i] = new int[N];
       }

       // добавление нулей в матрицу
       for (i = 0; i < N; i++)
           for (j = 0; j < N; j++)
           {
               a[i][j] = 0;
           }
       int ver1; int ver2; // доп переменные для матрицы
       for (i = 1; ver[i] != '\0'; i += 6)
       {
           //cout << ver[i] << " " << ver[i+2] << endl;
           ver1 = (int)(ver[i]-49); // с помощью таблицы anci
           ver2 = (int)(ver[i+2]-49);
           //cout << ver1 << " " << ver2 << endl;
           a[ver1][ver2] = 1;
           a[ver2][ver1] = 1;
       }
       long long  revstr = 0;
       while (str) // переворачиваем список
       {
           revstr = revstr * 10 + str % 10;
           str /= 10;
       }
       //cout <<"Перевернутый список" << "\n";
       //cout << revstr << endl;
       int m1 = revstr % 10-1;
       revstr /= 10;
       int m2;
       while (revstr) // обнуление столбцов
       {
           m2 = revstr % 10 - 1;
           if (a[m1][m2] == 0) {
               return "0";
               m1 = 100;
               break;
           }
           for (i = 0; i < N; i++) // обнуляем столбец, больше в него не можем прийти
           {
               a[i][m2] = 0;
           }
           revstr /= 10;
           m1 = m2;
       }
       //cou(N, a);
       int sum = 0;
       for (i = 0; i < N; i++) // проверка что всеь массив равен нулю
           for (j = 0; j < N; j++)
           {
               sum += a[i][j];
           }
       if (m1 == 100);
       else if (sum == 0)                return "1";
       else                return "0";
}

QByteArray parsing(QString command){
    QStringList parts = command.left(command.length() - 2).split(" ");
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
    else if (parts[0] == "hamilton") return QByteArray::fromStdString(hamilton(parts[1].toInt(),parts[2].toLongLong()))+"\r\n";
    else return invalid_request();

}
