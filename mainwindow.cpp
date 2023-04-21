
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthForm;
    ui_task = new TaskForm;
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
    ui_task->set_mode('1');
    ui_task->show();
    qDebug() << "task1";
}


void MainWindow::on_pushButton_2_clicked()
{
    ui_task->set_mode('2');
    ui_task->show();
    qDebug() << "task2";
}


void MainWindow::on_pushButton_3_clicked()
{
    ui_task->set_mode('3');
    ui_task->show();
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


void MainWindow::on_pushButton_5_clicked()
{
    ui_task->set_mode('4');
    ui_task->show();
    qDebug() << "task4";
}


void MainWindow::on_pushButton_6_clicked()
{
    ui_task->set_mode('5');
    ui_task->show();
    qDebug() << "task5";
}

