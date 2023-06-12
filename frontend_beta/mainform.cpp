#include "mainform.h"
#include "ui_mainform.h"
#include "singletonclient.h"
#include <QMessageBox>

MainForm::MainForm(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->labelStudLogin->setText(login);
    ui->labelTaskNum->hide();
    ui->comboBoxAnswer->hide();
    singletonClient::Get().singletonClient::Get().socket = new QTcpSocket(this);
    singletonClient::Get().singletonClient::Get().socket->connectToHost("127.0.0.1", 4747);
    singletonClient::Get().nextBlockSize = 0;
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotGetId);
    singletonClient::Get().sendToServer("getid " + ui->labelStudLogin->text());
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::closeEvent (QCloseEvent *event)
{
    singletonClient::Get().sendToServer("logout " + ui->labelStudLogin->text());
    event->accept();
}

void MainForm::slotGetId()
{
    singletonClient::Get().QDataIn();
    ui->label_id->setText(singletonClient::Get().str);
    disconnect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotGetId);
    on_pushButtonUpdateStat_clicked();
}

void MainForm::getLogin(QString login)
{
    ui->labelStudLogin->setText(login);
}

void MainForm::on_pushButtonUpdateStat_clicked()
{
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotButtonUpdateStat);
    singletonClient::Get().sendToServer("show_stud_stats " + ui->labelStudLogin->text());
}

void MainForm::slotButtonUpdateStat()
{
    singletonClient::Get().QDataIn();
    if (singletonClient::Get().str != "")
    {
        ui->textBrowserStudStat->setText(singletonClient::Get().str);
        disconnect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotButtonUpdateStat);
    }
}

void MainForm::on_pushButton_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_1");
    ui->labelTaskName->setText("Задание 1");

    QList<QString> zads = {
        "Построить систему представителей двудольного графа.\nN1 = {1, 2, 3}\nN2 = {4, 5, 6}",
        "Построить систему представителей двудольного графа.\nN1 = {1, 2, 3, 4}\nN2 = {5, 6, 7, 8, 9}",
        "Построить систему представителей двудольного графа.\nN1 = {1, 2}\nN2 = {3, 4}"
    };

    QRandomGenerator::securelySeeded();

    // Генерация случайного числа в диапазоне [N, M]
    int randomNum = QRandomGenerator::global()->bounded(0, 3);

    ui->textBrowserTask->setText(zads[randomNum] +
                            "\n В ответе указать ответ в порядке N1i N2j. То есть для N1 = {1, 2}, N2 = {3, 4}"
                            "правильным ответом\n будет 1,3,1,4,2,3,2,4");

}

// Task 2 button
int random_vertices, random_edges;
QString graf;
void MainForm::on_pushButton_2_clicked()
{
    ui->comboBoxAnswer->show();
    ui->labelTaskNum->setText("task_2");
    ui->labelTaskName->setText("Задание 2");
    int choice;
    choice = QRandomGenerator::global()->bounded(0, 2);
    graf = "";
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::vector<std::pair<int, int>> edges;
    std::vector<std::pair<int, int>> allEdges;
    if (choice == 0)
    {
        random_vertices = QRandomGenerator::global()->bounded(3, 9);
        //    int random_edges  = QRandomGenerator::global()->bounded((random_vertices - 1), ((random_vertices * (random_vertices - 1)) / 2));
        random_edges  = ((random_vertices * (random_vertices - 1)) / 2);
        for (int i = 0; i < random_vertices; i++)
        {
            for (int j = i + 1; j < random_vertices; j++)
            {
                allEdges.push_back(std::make_pair(i, j));
            }
        }
        std::shuffle(allEdges.begin(), allEdges.end(), rng);
        for (int i = 0; i < allEdges.size(); i++)
        {
            graf += QString::number(allEdges[i].first) + "-" + QString::number(allEdges[i].second) + "|";
        }
    }
    else if (choice == 1)
    {
        std::vector<int> left_group;
        std::vector<int> right_group;
        random_vertices = QRandomGenerator::global()->bounded(3, 8);
        int left_vertices = random_vertices / 2;
        int right_vertices = random_vertices - left_vertices;
        for (int i = 0; i < left_vertices; i++) {
            left_group.push_back(i);
        }
        for (int i = left_vertices; i < random_vertices; i++) {
            right_group.push_back(i);
        }
        std::vector<std::pair<int, int>> allEdges;
        for (int i = 0; i < left_vertices; i++) {
            for (int j = 0; j < right_vertices; j++) {
                allEdges.push_back(std::make_pair(left_group[i], right_group[j]));
            }
        }
        std::shuffle(allEdges.begin(), allEdges.end(), rng);
        for (int i = 0; i < allEdges.size(); i++)
        {
            graf += QString::number(allEdges[i].first) + "-" + QString::number(allEdges[i].second) + "|";
        }
        random_edges  = allEdges.size();
    }
    ui->textBrowserTask->show();
    ui->textBrowserTask->setText("Количество вершин графа (отсчёт вершин от 0) = " + QString::number(random_vertices) + "\n\rКоличество ребер графа = " + QString::number(random_edges)
                                 + "\n\rСвязи вершин в графе = " + graf + "\n\rЯвляется ли данный граф двудольным?");
    ui->lineEditAnswer->show();
    ui->pushButtonAnswer->show();
}

int n;
QString graf_3;
// Task 3 button
void MainForm::on_pushButton_3_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_3");
    ui->labelTaskName->setText("Задание 3");

    graf_3 = "";
    n = QRandomGenerator::global()->bounded(5, 10);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            graf_3 =  graf_3 + QString::number(i) + "," + QString::number(j) + "|";
            count++;
            if (count == 2)
                break;
        }
    }
    graf_3.chop(1);

    ui->textBrowserTask->setText("Найдите все внешне устойчивые множества в графе:\nКоличество вершин " + QString::number(n-1) + " (отчет вершин от 0)\nРебра (Откуда исходит, куда направлено)\n" + graf_3 + "\nПример ввода ответа: |123||045|");
}

int numVertices;
QString  graf_task4 = "";
void MainForm::on_pushButtonTask4_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_4");
    ui->labelTaskName->setText("Задание 4");

    graf_task4 = "";
    numVertices = QRandomGenerator::global()->bounded(5, 10);
    for (int i = 0; i < numVertices; i++)
    {
        int count = 0;
        for (int j = i + 1; j < numVertices; j++)
        {
             graf_task4 =  graf_task4 + QString::number(i) + "," + QString::number(j) + "," + QString::number(QRandomGenerator::global()->bounded(1, 8)) + "|";
            count++;
            if (count == 2)
                break;
        }
    }
    graf_task4.chop(1);

    ui->textBrowserTask->setText("Найдите кратчайший путь между двумя вершинами в графе:\nКоличество вершин " + QString::number(numVertices) + " (отчет вершин от 0)\nРебра (Откуда исходит, куда направлено, вес)\n" + graf_task4 + "\nПример ввода ответа: 0-1-2-3");
}


void MainForm::on_pushButtonTask5_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_5");
    ui->labelTaskName->setText("Задание 5");

    QString E[12] = {
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
    random_vertices = QRandomGenerator::global()->bounded(0, 12);
    QString ver = E[random_vertices];
    ui->textBrowserTask->setText("Вам необходимо найти Гамильтнов цикл в графе заданным ребрами: " + E[random_vertices] + "\nВ ответ введите список вершин без пробелов.");
}


void MainForm::on_pushButtonAnswer_clicked()
{
    if (ui->labelTaskNum->text() == "task_1")
    {
        connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        singletonClient::Get().sendToServer("task_1 " + ui->labelStudLogin->text() + " " + ui->lineEditAnswer->text());
    }
    else if (ui->labelTaskNum->text() == "task_2")
    {
        connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        singletonClient::Get().sendToServer("task_02 "+ ui->labelStudLogin->text() + " " + QString::number(random_vertices) + " " + QString::number(random_edges) + " " + graf + " " + ui->comboBoxAnswer->currentText());
    }
    else if (ui->labelTaskNum->text() == "task_4")
    {
        connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        singletonClient::Get().sendToServer("task_4 " + ui->labelStudLogin->text() + " " + QString::number(numVertices) + " " + graf_task4 + " " + ui->lineEditAnswer->text());
    }
    else if (ui->labelTaskNum->text() == "task_3")
    {
        connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        singletonClient::Get().sendToServer("task_3 "+ ui->labelStudLogin->text() + " " + QString::number(n) + " " + graf_3 + " " + ui->comboBoxAnswer->currentText());
    }
    else if (ui->labelTaskNum->text() == "task_5")
    {
        connect(singletonClient::Get().singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        singletonClient::Get().sendToServer("task_5 "+ ui->labelStudLogin->text() + " " + QString::number(random_vertices) + " " + ui->lineEditAnswer->text());
    }
}

void MainForm::slotCheckTask()
{
    singletonClient::Get().QDataIn();
    if (singletonClient::Get().str != "")
    {
        if (singletonClient::Get().str == "1")
            QMessageBox::information(this, "Задание", "Задание выполнено верно!");
        else
            QMessageBox::information(this, "Задание", "Задание выполнено неверно!");
        disconnect(singletonClient::Get().singletonClient::Get().socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
    }
}
