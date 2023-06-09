#include "functions.h"
#include "singletondb.h"
#include <QDebug>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QRegularExpression>

class OlegGraph {
public:
    OlegGraph(const QVector<QVector<int>>& adjacencyMatrix) : adjMatrix(adjacencyMatrix) {}

    QByteArray findMaximalIndependentSets() {
        QByteArray result;
        findMaximalIndependentSetsUtil(result, {}, 0);
        return result;
    }

private:
    QVector<QVector<int>> adjMatrix;

    void findMaximalIndependentSetsUtil(QByteArray &result, QVector<int> currentSet, int vertex) {
        if (vertex == adjMatrix.size()) {
            if (isMaximal(currentSet)) {
                result.append(setToString(currentSet));
            }
            return;
        }

        // Exclude the current vertex
        findMaximalIndependentSetsUtil(result, currentSet, vertex + 1);

        // Include the current vertex if it is independent
        bool isIndependent = true;
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if (adjMatrix[vertex][i] && std::find(currentSet.begin(), currentSet.end(), i) != currentSet.end()) {
                isIndependent = false;
                break;
            }
        }
        if (isIndependent) {
            currentSet.push_back(vertex);
            findMaximalIndependentSetsUtil(result, currentSet, vertex + 1);
        }
    }

    bool isMaximal(const QVector<int>& set) {
        for (int u = 0; u < adjMatrix.size(); ++u) {
            if (std::find(set.begin(), set.end(), u) == set.end()) {
                bool isNeighbor = false;
                for (int v : set) {
                    if (adjMatrix[u][v]) {
                        isNeighbor = true;
                        break;
                    }
                }
                if (!isNeighbor) {
                    return false;
                }
            }
        }
        return true;
    }

    QByteArray setToString(const QVector<int>& set) {
        QByteArray setString = "{";
        for (int vertex : set) {
            setString.append(QByteArray::number(vertex) + " ");
        }
        setString.append("}\n");
        return setString;
    }
};

//ind_task_oleg

QByteArray externalStableSets(QString var) {
        QString SETS[4] = {
                         "(1,2),(1,3),(1,4),(2,3),(2,6),(2,7),(3,4),(3,5),(3,7),(5,6),(6,7)",
                         "(1,2),(1,4),(1,6),(1,7),(2,4),(2,6),(3,4),(3,5),(3,6),(3,7),(4,5),(5,6),(6,7)",
                         "(1,2),(1,3),(1,4),(1,7),(2,3),(2,4),(2,6),(3,4),(4,5),(4,6),(4,7)",
                         "(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(4,7),(6,7)"};

        QString ver = SETS[var.toInt()];

        ver.remove('(').remove(')');
        QStringList edgeList = ver.split(',');

        int max_vertex = 0;
        for (int k = 0; k < edgeList.size(); k += 2) {
            int u = edgeList[k].toInt();
            int v = edgeList[k + 1].toInt();
            max_vertex = qMax(max_vertex, qMax(u, v));
        }

        // Инициализация матрицы смежности нулями
        QVector<QVector<int>> adjacency_matrix(max_vertex + 1, QVector<int>(max_vertex + 1, 0));

        // Заполняем матрицу смежности
        for (int k = 0; k < edgeList.size(); k += 2) {
            int u = edgeList[k].toInt();
            int v = edgeList[k + 1].toInt();
            adjacency_matrix[u][v] = 1;
            adjacency_matrix[v][u] = 1;
        }

        OlegGraph graph(adjacency_matrix);

        QByteArray result = graph.findMaximalIndependentSets();
        qDebug() << result;
        return result;
}

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
    else if (parts[0] == "external_sets") return externalStableSets(parts[1]);
    else return invalid_request();
}



