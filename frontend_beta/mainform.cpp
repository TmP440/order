#include "mainform.h"
#include "ui_mainform.h"
#include <QMessageBox>

MainForm::MainForm(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    ui->labelStudLogin->setText(login);
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

void MainForm::on_pushButton_clicked()
{

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

void MainForm::on_pushButton_4_clicked()
{
    connect(socket, &QTcpSocket::readyRead, this, &MainForm::slotButtonUpdateStat);
    sendToServer("external_sets 0");
}

