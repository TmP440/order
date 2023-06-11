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
    /// \brief on_AuthButton_clicked отвечает за авторизацию
    /// \param
    /// \return
    ///
    void on_AuthButton_clicked();

    /// \brief on_RegButton_clicked отвечает за регистрацию
    /// \param
    /// \return
    ///
    void on_RegButton_clicked();

    /// \brief on_toAuthButton_clicked отвечает переход к форме авторизации
    /// \param
    /// \return
    ///
    void on_toAuthButton_clicked();

    /// \brief on_toRegButton_clicked отвечает переход к форме регистрации
    /// \param
    /// \return
    ///
    void on_toRegButton_clicked();

    /// \brief on_comboBoxStatus_currentTextChanged отвечает за ввод ID-преподавателя
    /// \param
    /// \return
    ///
    void on_comboBoxStatus_currentTextChanged(const QString &arg1);

    /// \brief on_pushButtonEye_clicked отвечает за просмотр вводимого пароля
    /// \param
    /// \return
    ///
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
