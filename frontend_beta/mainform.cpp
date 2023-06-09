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
void MainForm::on_pushButton_2_clicked()
{
    ui->comboBoxAnswer->show();
    ui->labelTaskNum->setText("task_2");
    ui->labelTaskName->setText("Задание 2");
}

// Task 3 button
void MainForm::on_pushButton_3_clicked()
{
    if (ui->comboBoxAnswer->isVisible())
        ui->comboBoxAnswer->hide();
    ui->labelTaskNum->setText("task_3");
    ui->labelTaskName->setText("Задание 3");

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
    connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotCheckTask);
    sendToServer("task_4 " + ui->labelStudLogin->text() + " " + QString::number(numVertices) + " " + graf_task4 + " " + ui->lineEditAnswer->text());
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
