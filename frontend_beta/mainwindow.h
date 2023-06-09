#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainform.h"
#include "prepform.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_AuthButton_clicked();

    void on_RegButton_clicked();

    void on_toAuthButton_clicked();

    void on_toRegButton_clicked();

    void on_comboBoxRegStatus_currentTextChanged(const QString &arg1);

    void on_comboBoxStatus_currentTextChanged(const QString &arg1);

    void on_pushButtonEye_clicked();

private:
    Ui::MainWindow *ui;
    MainForm *m;
    prepform *p;
    QByteArray data;
    quint16 nextBlockSize;
    QTcpSocket *socket;
    void sendToServer(QString str);
public slots:
    void slotAuth();
    void slotReadyRead();
    void slotReg();
    void slotRegFio();
};
#endif // MAINWINDOW_H
