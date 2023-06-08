#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>

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
    void on_pushButton_clicked();

    void on_pushButtonUpdateStat_clicked();

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
};

#endif // MAINFORM_H
