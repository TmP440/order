#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    this->change_mode(true);
}

void AuthForm::change_mode(bool mode)//mode = true for auth
{
    ui->label_email->setVisible(!mode);
    ui->line_email->setVisible(!mode);
    ui->pushButtonAuth->setVisible(!mode);
    ui->pushButtonReg->setVisible(!mode);

    if (mode){
        ui->pushButtonChange->setText("to reg");
    }
    else{
        ui->pushButtonChange->setText("to auth");
    }
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_pushButtonChange_clicked()
{
    this->change_mode(ui->pushButtonReg->isVisible());
}


void AuthForm::on_pushButtonReg_clicked()
{
    qDebug() << "reg" << ui->line_log->text() << " "
             << ui->line_pas->text() << " "
             << ui->line_email->text();
    this->on_pushButtonAuth_clicked();
}


void AuthForm::on_pushButtonAuth_clicked()
{
    qDebug() << "auth" << ui->line_log->text() << " "
             << ui->line_pas->text();
    emit closed(ui->line_log->text());
    this->close();
}

