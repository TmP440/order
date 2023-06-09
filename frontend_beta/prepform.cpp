#include "prepform.h"
#include "ui_prepform.h"
#include <QMessageBox>

prepform::prepform(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::prepform)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 4747);
    nextBlockSize = 0;
    ui->labelPrepLogin->setText(login);
    connect(socket, &QTcpSocket::readyRead, this, &prepform::slotGetId);
    sendToServer("getid " + ui->labelPrepLogin->text());
}

void prepform::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
}

void prepform::slotGetId()
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
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &prepform::slotGetId);
    connect(socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStatLoad);
    sendToServer("wctm " + ui->labelPrepLogin->text());
}

void prepform::slotComboBoxStatLoad()
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
            QStringList parts = str.left(str.length() - 1).split(" ");
            for(int i = 0; i < parts.length(); i++)
            {
            ui->comboBoxStudents->addItem(parts[i]);
            }
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStatLoad);
}

prepform::~prepform()
{
    delete ui;
}

void prepform::closeEvent (QCloseEvent *event)
{
    sendToServer("logout " + ui->labelPrepLogin->text());
    event->accept();
}

void prepform::getLogin(QString login)
{
    ui->labelPrepLogin->setText(login);
}

void prepform::on_pushButtonUpdateStat_clicked()
{

}


void prepform::on_comboBoxStudents_currentTextChanged(const QString &arg1)
{
    connect(socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    sendToServer("show_stud_stats " + arg1);
}

void prepform::slotComboBoxStudents()
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
            ui->textBrowserStat->setText(str);
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
}


void prepform::on_pushButtonExit_clicked()
{
    this->close();
}

