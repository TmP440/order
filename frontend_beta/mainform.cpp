#include "mainform.h"
#include "ui_mainform.h"
#include <QMessageBox>

MainForm::MainForm(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->labelStudLogin->setText(login);
    ui->labelTaskNum->hide();
    ui->comboBoxAnswer->hide();
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 4747);
    nextBlockSize = 0;
    connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotGetId);
    sendToServer("getid " + ui->labelStudLogin->text());
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::closeEvent (QCloseEvent *event)
{
    sendToServer("logout " + ui->labelStudLogin->text());
    event->accept();
}

void MainForm::slotGetId()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            in >> str;
            nextBlockSize = 0;
            ui->label_id->setText(str);
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка в slotGetID datastream in");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &MainForm::slotGetId);
    on_pushButtonUpdateStat_clicked();
}

void MainForm::getLogin(QString login)
{
    ui->labelStudLogin->setText(login);
}

// Task 1 button
void MainForm::on_pushButton_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_1");
    ui->labelTaskName->setText("Задание 1");

}

void MainForm::on_pushButtonUpdateStat_clicked()
{
    connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotButtonUpdateStat);
    sendToServer("show_stud_stats " + ui->labelStudLogin->text());
}

void MainForm::slotButtonUpdateStat()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize == 0)
             {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }

            QString str;
            in >> str;
            nextBlockSize = 0;
            ui->textBrowserStudStat->setText(str);
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &MainForm::slotButtonUpdateStat);
}

void MainForm::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
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
    ui->labelTaskNum->setText("task_4");
    ui->labelTaskName->setText("Задание 4");

}


void MainForm::on_pushButtonAnswer_clicked()
{
    if (ui->labelTaskNum->text() == "task_4")
    {
        connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        sendToServer("task_4 " + ui->labelStudLogin->text() + " " + QString::number(numVertices) + " " + graf_task4 + " " + ui->lineEditAnswer->text());
    }
    else if (ui->labelTaskNum->text() == "task_2")
    {
        connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        sendToServer("task_02 "+ ui->labelStudLogin->text() + " " + QString::number(random_vertices) + " " + QString::number(random_edges) + " " + graf + " " + ui->comboBoxAnswer->currentText());
    }
    else if (ui->labelTaskNum->text() == "task_3")
    {
        connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
        sendToServer("task_3 "+ ui->labelStudLogin->text() + " " + QString::number(n) + " " + graf_3 + " " + ui->comboBoxAnswer->currentText());
    }
}

void MainForm::slotCheckTask()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        for(;;)
        {
            if(nextBlockSize == 0)
             {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }

            QString str;
            in >> str;
            nextBlockSize = 0;
            if (str == "1")
                QMessageBox::information(this, "Задание", "Задание выполнено верно!");
            else
                QMessageBox::information(this, "Задание", "Задание выполнено неверно!");
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
}
