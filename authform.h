#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    void on_pushButtonChange_clicked();

    void on_pushButtonReg_clicked();

    void on_pushButtonAuth_clicked();

private:
    Ui::AuthForm *ui;

    void change_mode(bool mode);

signals:
    void closed(QString log);
};

#endif // AUTHFORM_H
