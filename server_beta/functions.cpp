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

QByteArray task_4(QString login, QString length, QString graf, QString answer)
{

    struct Edge {
        int destination;
        int weight;
    };

    class Graph {
        int numVertices;
        std::vector<std::vector<Edge>> adjacencyList;

    public:
        Graph(int vertices) : numVertices(vertices) {
            adjacencyList.resize(numVertices);
        }

        void addEdge(int source, int destination, int weight) {
            Edge edge = {destination, weight};
            adjacencyList[source].push_back(edge);
        }

        std::vector<int> dijkstra(int source, int destination) {
            const int INF = std::numeric_limits<int>::max();
            std::vector<int> distance(numVertices, INF);
            std::vector<int> previous(numVertices, -1);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

            distance[source] = 0;
            pq.push(std::make_pair(0, source));

            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                for (const Edge& edge : adjacencyList[u]) {
                    int v = edge.destination;
                    int weight = edge.weight;

                    int newDistance = distance[u] + weight;
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        previous[v] = u;
                        pq.push(std::make_pair(newDistance, v));
                    }
                }
            }

            if (distance[destination] == INF) {
                return std::vector<int>();
            }

            std::vector<int> path;
            int vertex = destination;
            while (vertex != -1) {
                path.insert(path.begin(), vertex);
                vertex = previous[vertex];
            }
            return path;
        }
    };
        int numVertices = length.toInt();
        Graph graph(numVertices);
        int source = 0;
        int destination = numVertices - 1;

        graf.chop(1);
        QStringList parts = graf.left(graf.length()).split("|");

        for (int i = 0; i < parts.length(); i++)
        {
            QStringList edge_list = parts[i].split(",");
            graph.addEdge(edge_list[0].toInt(), edge_list[1].toInt(), edge_list[2].toInt());
        }

        std::vector<int> shortestPath = graph.dijkstra(source, destination);

        QString server_answer;
        for (int vertex : shortestPath)
        {
            server_answer = server_answer + QString::number(vertex) + "-";
        }
    server_answer.chop(1);
    qDebug() << server_answer << "\n";
    if (server_answer == answer)
    {
        SingletonDB::check_task(login, "4", "1");
        return "1";
    }
    else
        return "0";
}

QByteArray task_2(QString login, QString numVertices, QString numEdges, QString connections, QString answer)
{
    class Graph {
        int V; // Количество вершин
        std::vector<std::vector<int>> adjList; // Список смежности

    public:
        Graph(int v) {
            V = v;
            adjList.resize(V);
        }

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        bool isBipartite() {
            std::vector<int> color(V, -1); // Цвета вершин (-1: не покрашена, 0: цвет 1, 1: цвет 2)

            for (int i = 0; i < V; ++i) {
                if (color[i] == -1) {
                    // Запускаем поиск в ширину для новой компоненты связности
                    std::queue<int> q;
                    q.push(i);
                    color[i] = 0;

                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();

                        for (int v : adjList[u]) {
                            if (color[v] == -1) {
                                color[v] = 1 - color[u];
                                q.push(v);
                            } else if (color[v] == color[u]) {
                                return false; // Найден цикл нечетной длины, граф не двудольный
                            }
                        }
                    }
                }
            }
            return true; // Граф является двудольным
        }
    };
    int V = numVertices.toInt();
    Graph graph(V);
    QStringList parts_connections = connections.left(connections.length()).split("|");
    for (int i = 0; i < parts_connections.length() - 1; i++)
    {
        int u, v = 0;
        QStringList pairs = parts_connections[i].left(parts_connections.length()).split("-");
        u = pairs[0].toInt();
        v = pairs[1].toInt();
        graph.addEdge(u, v);
    }
    if (graph.isBipartite() == 1 && answer == "Да")
    {
        check_task(login, "2", "1");
        return "1";

    }
    else if (graph.isBipartite() == 0 && answer == "Нет")
    {
        check_task(login, "2", "1");
        return "1";
    }
    else
    {
        return "0";
    }
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
    else if (parts[0] == "task_4") return task_4(parts[1], parts[2], parts[3], parts[4]);
    else if (parts[0] == "task_02") return task_2(parts[1], parts[2], parts[3], parts[4], parts[5]);
    else return invalid_request();
}
