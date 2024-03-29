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

QByteArray task_1(QString login, QString answer) {

    QList<QString> dif_answers = {
        "1,4,1,5,1,6,2,4,2,5,2,6,3,4,3,5,3,6,",
        "1,4,1,5,1,6,2,4,2,5,2,6,3,4,3,5,3,6",
        "1,5,1,6,1,7,1,8,1,9,2,5,2,6,2,7,2,8,2,9,3,5,3,6,3,7,3,8,3,9,4,5,4,6,4,7,4,8,4,9,",
        "1,5,1,6,1,7,1,8,1,9,2,5,2,6,2,7,2,8,2,9,3,5,3,6,3,7,3,8,3,9,4,5,4,6,4,7,4,8,4,9",
        "1,3,1,4,2,3,2,4,",
        "1,3,1,4,2,3,2,4"
    };
    for (int i = 0; i < dif_answers.size(); i++)
    {
        if (answer == dif_answers[i])
        {
            check_task(login, "1", "1");
            return "1";
        }
    }
    return "0";
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

QByteArray task_3(QString login, QString numVertices, QString connections, QString answer) {
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
            QByteArray setString = "|";
            for (int vertex : set) {
                setString.append(QByteArray::number(vertex));
            }
            setString.append("|");
            return setString;
        }
    };
    //QString SETS[4] = {
    //                   "(1,2),(1,3),(1,4),(2,3),(2,6),(2,7),(3,4),(3,5),(3,7),(5,6),(6,7)",
    //                   "(1,2),(1,4),(1,6),(1,7),(2,4),(2,6),(3,4),(3,5),(3,6),(3,7),(4,5),(5,6),(6,7)",
    //                   "(1,2),(1,3),(1,4),(1,7),(2,3),(2,4),(2,6),(3,4),(4,5),(4,6),(4,7)",
    //                   "(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(4,7),(6,7)"};

    connections.remove('(').remove(')');
    QStringList edgeList = connections.split(',');

    int n = numVertices.toInt();

    // Инициализация матрицы смежности нулями
    QVector<QVector<int>> adjacency_matrix(n + 1, QVector<int>(n + 1, 0));

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

    if(result == answer){
        check_task(login, "3", "1");
    }

    return result;
}

QByteArray task_5(QString login, QString e1, QString str1){
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
    int e = e1.toInt();
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
    long long str = str1.toLongLong();
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
    for (i = 0; i < N; i++) { // проверка что всеь массив равен нулю
        for (j = 0; j < N; j++)
        {
            sum += a[i][j];
        }
    }
    if (m1 == 100);
    else if (sum == 0) {        SingletonDB::check_task(login, "5", "1");               return "1";}
    else                return "0";
}

bool ascending_sort(const QStringList& a, const QStringList& b)
{
    return a[1].toInt() > b[1].toInt();
}

bool descending_sort(const QStringList& a, const QStringList& b)
{
    return a[1].toInt() < b[1].toInt();
}

QByteArray sort_stats(QString login, QString sort_type)
{
    QList<QStringList> records = SingletonDB::student_stats(login);
    QString result = "\r\nНомер\tОценка\r\n";
    if (sort_type == "1")
    {
        std::sort(records.begin(), records.end(), ascending_sort);
    }
    else if (sort_type == "0")
    {
        std::sort(records.begin(), records.end(), descending_sort);
    }
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

QByteArray sort_by_task_desk(QString login)
{
    QList<QStringList> records = SingletonDB::sort_by_task_desk(login);
    QString result = "\r\nЛогин\tФИ\t\tВыполнено\r\n";
    if (!records.isEmpty())
    {
        QByteArray to_console = "\r\nСтатистика учеников:\r\n";
        for (int i = 0; i < records.size(); i++)
        {
            QString logn = records[i][0];
            QString fi = records[i][1];
            QString is_correct_sum = records[i][2];
            result += logn + "\t" + fi;
            for (int i = fi.length(); i < 25; i++)
            {
                result += " ";
            }
            result += "\t" + is_correct_sum + "\r\n";
        }
        to_console += result.toUtf8();
        return to_console;
    }
    else return QByteArray("Невозможно вывести статистику учеников\r\n");
}

QByteArray sort_by_task(QString login)
{
    QList<QStringList> records = SingletonDB::sort_by_task(login);
    QString result = "\r\nЛогин\tФИ\t\tВыполнено\r\n";
    if (!records.isEmpty())
    {
        QByteArray to_console = "\r\nСтатистика учеников:\r\n";
        for (int i = 0; i < records.size(); i++)
        {
            QString logn = records[i][0];
            QString fi = records[i][1];
            QString is_correct_sum = records[i][2];
            result += logn + "\t" + fi;
            for (int i = fi.length(); i < 25; i++)
            {
                result += " ";
            }
            result += "\t" + is_correct_sum + "\r\n";
        }
        to_console += result.toUtf8();
        return to_console;
    }
    else return QByteArray("Невозможно вывести статистику учеников\r\n");
}

QByteArray sort_by_fi(QString login)
{
    QList<QStringList> records = SingletonDB::sort_by_fi(login);
    QString result = "\r\nЛогин\tФИ\t\tВыполнено\r\n";
    if (!records.isEmpty())
    {
        QByteArray to_console = "\r\nСтатистика учеников:\r\n";
        for (int i = 0; i < records.size(); i++)
        {
            QString logn = records[i][0];
            QString fi = records[i][1];
            QString is_correct_sum = records[i][2];
            result += logn + "\t" + fi;
            for (int i = fi.length(); i < 25; i++)
            {
                result += " ";
            }
            result += "\t" + is_correct_sum + "\r\n";
        }
        to_console += result.toUtf8();
        return to_console;
    }
    else return QByteArray("Невозможно вывести статистику учеников\r\n");
}

QByteArray sort_by_fi_desc(QString login)
{
    QList<QStringList> records = SingletonDB::sort_by_fi_desc(login);
    QString result = "\r\nЛогин\tФИ\t\tВыполнено\r\n";
    if (!records.isEmpty())
    {
        QByteArray to_console = "\r\nСтатистика учеников:\r\n";
        for (int i = 0; i < records.size(); i++)
        {
            QString logn = records[i][0];
            QString fi = records[i][1];
            QString is_correct_sum = records[i][2];
            result += logn + "\t" + fi;
            for (int i = fi.length(); i < 25; i++)
            {
                result += " ";
            }
            result += "\t" + is_correct_sum + "\r\n";
        }
        to_console += result.toUtf8();
        return to_console;
    }
    else return QByteArray("Невозможно вывести статистику учеников\r\n");
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
    else if (parts[0] == "task_1") return task_1(parts[1], parts[2]);
    else if (parts[0] == "task_4") return task_4(parts[1], parts[2], parts[3], parts[4]);
    else if (parts[0] == "task_02") return task_2(parts[1], parts[2], parts[3], parts[4], parts[5]);
    else if (parts[0] == "task_3") return task_3(parts[1], parts[2], parts[3], parts[4]);
    else if (parts[0] == "task_5") return task_5(parts[1], parts[2], parts[3]);
    else if (parts[0] == "sort_stud_stats") return sort_stats(parts[1], parts[2]);
    else if (parts[0] == "sort_by_task_desk") return sort_by_task_desk(parts[1]);
    else if (parts[0] == "sort_by_task") return sort_by_task(parts[1]);
    else if (parts[0] == "sort_by_fi") return sort_by_fi(parts[1]);
    else if (parts[0] == "sort_by_fi_desc") return sort_by_fi_desc(parts[1]);
    else return invalid_request();
}
