#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();

private:
    Ui::TaskForm *ui;
signals:
    void on_check(QString);
};

#endif // TASKFORM_H
