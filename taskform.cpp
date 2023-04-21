#include "taskform.h"
#include "ui_taskform.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
}

TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::on_pushButton_clicked()
{
    emit on_check(ui->line_task->text());
    qDebug()<<"check";
}

void TaskForm::set_mode(QChar num)
{
    ui->labelTask->setText(QString::fromStdString("task").append(num));
}
