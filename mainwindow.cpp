
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthForm;
    connect(ui_auth, &AuthForm::closed, this, &MainWindow::slot_show);
    ui_auth->show();
}

void MainWindow::slot_show(QString log)
{
    this->show();
    ui->label_log->setText(log);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "task1";
}


void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "task2";
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "task3";
}


void MainWindow::on_action_1_triggered()
{
    this->on_pushButton_clicked();
}


void MainWindow::on_action_2_triggered()
{
    this->on_pushButton_2_clicked();
}


void MainWindow::on_action_3_triggered()
{
    this->on_pushButton_3_clicked();
}

