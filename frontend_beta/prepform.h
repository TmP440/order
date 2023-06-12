#ifndef PREPFORM_H
#define PREPFORM_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>

namespace Ui {
class prepform;
}

class prepform : public QMainWindow
{
    Q_OBJECT

public:
    explicit prepform(QWidget *parent = nullptr, QString login = "null");
    ~prepform();
    void getLogin(QString login);

private slots:
    /// \brief on_pushButtonUpdateStat_clicked обновляет статистику
    /// \param
    /// \return
    ///
    void on_pushButtonUpdateStat_clicked();

    /// \brief on_comboBoxStudents_currentTextChanged при выборе студента из списка, вывод его статистики
    /// \param
    /// \return
    ///
    void on_comboBoxStudents_currentTextChanged(const QString &arg1);

    /// \brief on_pushButtonExit_clicked выход из программы
    /// \param
    /// \return
    ///
    void on_pushButtonExit_clicked();

    /// \brief on_toolButton_clicked сортировка данных по убыванию/возрастанию
    /// \param
    /// \return
    ///
    void on_toolButton_clicked();

    /// \brief on_toolButton_clicked сортировка данных по алфавиту
    /// \param
    /// \return
    ///
    void on_toolButton_2_clicked();

    /// \brief on_toolButton_clicked сортировка данных по количеству выполненных заданий
    /// \param
    /// \return
    ///
    void on_toolButton_3_clicked();

private:
    Ui::prepform *ui;
    void closeEvent(QCloseEvent *event);
public slots:
    void slotComboBoxStatLoad();
    void slotComboBoxStudents();
    void slotGetId();

};

#endif // PREPFORM_H
