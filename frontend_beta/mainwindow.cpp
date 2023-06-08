#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    ui->labelFio->setVisible(false);
    ui->lineEditFio->setVisible(false);

    ui->labelPrepID->setVisible(false);
    ui->lineEditPrepID->setVisible(false);

    ui->toAuthButton->setVisible(false);
    ui->RegButton->setVisible(false);

    ui->labelStatus->setVisible(false);
    ui->comboBoxStatus->setVisible(false);

    ui->lineEditPrepID->setGeometry(ui->lineEditPrepID->x(), ui->AuthButton->y(), ui->lineEditPrepID->width(), ui->lineEditPrepID->height());
    ui->labelPrepID->setGeometry(ui->labelPrepID->x(), ui->AuthButton->y(), ui->labelPrepID->width(), ui->labelPrepID->height());

    ui->comboBoxStatus->setGeometry(ui->lineEditPassword->x(), ui->lineEditPassword->y(), ui->comboBoxStatus->width(), ui->comboBoxStatus->height());
    ui->labelStatus->setGeometry(ui->labelPassword->x(), ui->labelPassword->y(), ui->labelStatus->width(), ui->labelStatus->height());

    ui->labelFio->setGeometry(ui->labelLogin->x(), ui->labelLogin->y(), ui->labelFio->width(), ui->labelFio->height());
    ui->lineEditFio->setGeometry(ui->lineEditLogin->x(), ui->lineEditLogin->y(), ui->lineEditFio->width(), ui->lineEditFio->height());

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 4747);
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
}


void MainWindow::on_AuthButton_clicked()
{
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotAuth);
    sendToServer("login " + ui->lineEditLogin->text() + " " + ui->lineEditPassword->text());
}


void MainWindow::slotAuth()
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
            QStringList parts = str.left(str.length()).split(" ");
            if(parts[0] == "1")
            {
                if (parts[1] == "-1")
                {
                    p = new prepform(this, ui->lineEditLogin->text());
                    this->hide();
                    p->show();
                }
                else
                {
                    m = new MainForm(this, ui->lineEditLogin->text());
                    this->hide();
                    m->show();
                }
            }
            else if(parts[0] == "0")
            {
                QMessageBox::information(this, "авторизация", "неверно введен логин или пароль");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotAuth);
}



void MainWindow::on_toRegButton_clicked()
{
    ui->AuthButton->setVisible(false);
    ui->toRegButton->hide();
    ui->RegButton->show();
    ui->toAuthButton->show();

    ui->labelLogin->setGeometry(ui->labelLogin->x(), ui->labelLogin->y() - 60, ui->labelLogin->width(), ui->labelLogin->height());
    ui->lineEditLogin->setGeometry(ui->lineEditLogin->x(), ui->lineEditLogin->y() - 60, ui->lineEditLogin->width(), ui->lineEditLogin->height());

    ui->labelFio->setVisible(true);
    ui->lineEditFio->setVisible(true);

    ui->labelPassword->setGeometry(ui->labelPassword->x(), ui->labelPassword->y() - 60, ui->labelPassword->width(), ui->labelPassword->height());
    ui->lineEditPassword->setGeometry(ui->lineEditPassword->x(), ui->lineEditPassword->y() - 60, ui->lineEditPassword->width(), ui->lineEditPassword->height());
    ui->pushButtonEye->setGeometry(ui->pushButtonEye->x(), ui->pushButtonEye->y() - 60, ui->pushButtonEye->width(), ui->pushButtonEye->height());

    ui->labelStatus->setVisible(true);
    ui->comboBoxStatus->setVisible(true);

    ui->groupBox->setTitle("Регистрация");
}


void MainWindow::on_toAuthButton_clicked()
{
    if(ui->labelPrepID->isVisible())
    {
        ui->comboBoxStatus->setCurrentText("Преподаватель");
    }

    ui->toAuthButton->hide();
    ui->RegButton->hide();
    ui->AuthButton->show();
    ui->toRegButton->show();

    ui->labelLogin->setGeometry(ui->labelLogin->x(), ui->labelLogin->y() + 60, ui->labelLogin->width(), ui->labelLogin->height());
    ui->lineEditLogin->setGeometry(ui->lineEditLogin->x(), ui->lineEditLogin->y() + 60, ui->lineEditLogin->width(), ui->lineEditLogin->height());

    ui->labelPassword->setGeometry(ui->labelPassword->x(), ui->labelPassword->y() + 60, ui->labelPassword->width(), ui->labelPassword->height());
    ui->lineEditPassword->setGeometry(ui->lineEditPassword->x(), ui->lineEditPassword->y() + 60, ui->lineEditPassword->width(), ui->lineEditPassword->height());
    ui->pushButtonEye->setGeometry(ui->pushButtonEye->x(), ui->pushButtonEye->y() + 60, ui->pushButtonEye->width(), ui->pushButtonEye->height());

    ui->labelStatus->setVisible(false);
    ui->comboBoxStatus->setVisible(false);

    ui->labelFio->setVisible(false);
    ui->lineEditFio->setVisible(false);

    ui->groupBox->setTitle("Авторизация");
}


void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if(in.status() == QDataStream::Ok)
    {
        QString str;
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
        }
        QMessageBox::information(this, "подключение", str);
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
}

void MainWindow::on_RegButton_clicked()
{
    if ((ui->labelFio->text() != "") and (ui->labelLogin->text() != "") and (ui->labelPassword->text() != ""))
    {
        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReg);
        QString prepID;
        if(ui->comboBoxStatus->currentText() == "Студент")
        {
            prepID = ui->lineEditPrepID->text();
        }
        else
        {
            prepID = "-1";
        }
        sendToServer("reg " + ui->lineEditLogin->text() + " " + ui->lineEditPassword->text() + " " + prepID);
    }
    else
    {
        QMessageBox::information(this, "регистрация", "некорректный ввод данных");
    }
}

void MainWindow::slotReg()
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
            if(str == "1")
            {
                QString role;
                if(ui->comboBoxStatus->currentText() == "Студент")
                {
                    role = "1";
                }
                else
                {
                    role = "0";
                }
                disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReg);
                connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotRegFio);
                QStringList parts = ui->lineEditFio->text().split(" ");
                sendToServer("reg_fio " + ui->lineEditLogin->text() + " " + parts[0] + " " + parts[1] + " " + parts[2] + " " + role);
            }
            else
            {
                QMessageBox::information(this, "регистрация", "ошибка");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "подключение", "ошибка при подключении");
    }
    disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReg);
}

void MainWindow::slotRegFio()
{
    disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotRegFio);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotAuth);
    sendToServer("login " + ui->lineEditLogin->text() + " " + ui->lineEditPassword->text());
}

void MainWindow::on_comboBoxStatus_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Студент")
    {
    ui->toAuthButton->setGeometry(ui->toAuthButton->x(), ui->toAuthButton->y() + 30, ui->toAuthButton->width(), ui->toAuthButton->height());
    ui->RegButton->setGeometry(ui->RegButton->x(), ui->RegButton->y() + 30, ui->RegButton->width(), ui->RegButton->height());

    ui->labelPrepID->setVisible(true);
    ui->lineEditPrepID->setVisible(true);
    }
    else
    {
    ui->toAuthButton->setGeometry(ui->toAuthButton->x(), ui->toAuthButton->y() - 30, ui->toAuthButton->width(), ui->toAuthButton->height());
    ui->RegButton->setGeometry(ui->RegButton->x(), ui->RegButton->y() - 30, ui->RegButton->width(), ui->RegButton->height());

    ui->labelPrepID->setVisible(false);
    ui->lineEditPrepID->setVisible(false);
    }
}


void MainWindow::on_pushButtonEye_clicked()
{
    if(ui->lineEditPassword->echoMode() == QLineEdit::Password)
    {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}

