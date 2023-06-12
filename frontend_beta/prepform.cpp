#include "prepform.h"
#include "ui_prepform.h"
#include "singletonclient.h"
#include <QMessageBox>

prepform::prepform(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::prepform)
{
    ui->setupUi(this);
    singletonClient::Get().socket = new QTcpSocket(this);
    singletonClient::Get().socket->connectToHost("127.0.0.1", 4747);
    singletonClient::Get().nextBlockSize = 0;
    ui->labelPrepLogin->setText(login);
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotGetId);
    ui->toolButton->hide();
    singletonClient::Get().sendToServer("getid " + ui->labelPrepLogin->text());
}

void prepform::slotGetId()
{
    singletonClient::Get().QDataIn();
    ui->label_id->setText(singletonClient::Get().str);
    disconnect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotGetId);
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStatLoad);
    singletonClient::Get().sendToServer("wctm " + ui->labelPrepLogin->text());
}

void prepform::slotComboBoxStatLoad()
{
    singletonClient::Get().QDataIn();
    QStringList parts = singletonClient::Get().str.left(singletonClient::Get().str.length() - 1).split(" ");
    for(int i = 0; i < parts.length(); i++)
    {
    ui->comboBoxStudents->addItem(parts[i]);
    }
    disconnect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStatLoad);
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    singletonClient::Get().sendToServer("sort_by_task_desk " + ui->labelPrepLogin->text());
}

prepform::~prepform()
{
    delete ui;
}

void prepform::closeEvent (QCloseEvent *event)
{
    singletonClient::Get().sendToServer("logout " + ui->labelPrepLogin->text());
    event->accept();
}

void prepform::getLogin(QString login)
{
    ui->labelPrepLogin->setText(login);
}

void prepform::on_pushButtonUpdateStat_clicked()
{

}

void prepform::slotComboBoxStudents()
{
    singletonClient::Get().QDataIn();
    ui->textBrowserStat->setText(singletonClient::Get().str);
    disconnect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
}


void prepform::on_pushButtonExit_clicked()
{
    this->close();
}

bool sort = false;
void prepform::on_toolButton_clicked()
{
    sort = !sort;
    qDebug() << sort;
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    singletonClient::Get().sendToServer("sort_stud_stats " + ui->comboBoxStudents->currentText() + " " + QString::number(sort));
}


bool desc_fi = true;
void prepform::on_toolButton_2_clicked()
{
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    if (desc_fi)
    {
    desc_fi = false;
    singletonClient::Get().sendToServer("sort_by_fi " + ui->labelPrepLogin->text());
    }
    else
    {
    desc_fi = true;
    singletonClient::Get().sendToServer("sort_by_fi_desc " + ui->labelPrepLogin->text());
    }
}

bool desc = true;
void prepform::on_toolButton_3_clicked()
{
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    if (desc)
    {
    desc = false;
    singletonClient::Get().sendToServer("sort_by_task " + ui->labelPrepLogin->text());
    }
    else
    {
    desc = true;
    singletonClient::Get().sendToServer("sort_by_task_desk " + ui->labelPrepLogin->text());
    }
}

void prepform::on_comboBoxStudents_currentTextChanged(const QString &arg1)
{
    connect(singletonClient::Get().socket, &QTcpSocket::readyRead, this, &prepform::slotComboBoxStudents);
    if (arg1 == "Все студенты")
    {
    desc_fi = true;
    desc = true;
    ui->toolButton->hide();
    ui->toolButton_2->show();
    ui->toolButton_3->show();
    singletonClient::Get().sendToServer("sort_by_task_desk " + ui->labelPrepLogin->text());
    }
    else
    {
    ui->toolButton_2->hide();
    ui->toolButton_3->hide();
    ui->toolButton->show();
    singletonClient::Get().sendToServer("show_stud_stats " + arg1);
    }
}

