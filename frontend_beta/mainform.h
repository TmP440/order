#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>
#include <queue>
#include <limits>
#include <vector>
#include <QRandomGenerator>
#include <QString>

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr, QString login = "null");
    ~MainForm();
    void getLogin(QString login);

private slots:
    /// \brief on_pushButton_clicked отвечает переход к первому заданию
    /// \param
    /// \return
    ///
    void on_pushButton_clicked();

    /// \brief on_pushButtonUpdateStat_clicked отвечает за обновление статистики
    /// \param
    /// \return
    ///
    void on_pushButtonUpdateStat_clicked();

    /// \brief on_pushButton_2_clicked отвечает переход ко второму заданию
    /// \param
    /// \return
    ///
    void on_pushButton_2_clicked();

    /// \brief on_pushButton_3_clicked отвечает переход к третьему заданию
    /// \param
    /// \return
    ///
    void on_pushButton_3_clicked();

    /// \brief on_pushButtonTask4_clicked отвечает переход к четвертому заданию
    /// \param
    /// \return
    ///
    void on_pushButtonTask4_clicked();

    /// \brief on_pushButtonTask5_clicked отвечает переход к пятому заданию
    /// \param
    /// \return
    ///
    void on_pushButtonTask5_clicked();

    /// \brief on_pushButtonAnswer_clicked отвечает за передачу серверу ответа
    /// \param
    /// \return
    ///
    void on_pushButtonAnswer_clicked();

private:
    Ui::MainForm *ui;
    QTcpSocket *socket;
    QByteArray data;
    void sendToServer(QString str);
    quint16 nextBlockSize;
    void closeEvent(QCloseEvent *event);
public slots:
    void slotButtonUpdateStat();
    void slotGetId();
    void slotCheckTask();
};

#endif // MAINFORM_H
