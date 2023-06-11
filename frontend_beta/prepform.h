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
    void on_pushButtonUpdateStat_clicked();

    void on_comboBoxStudents_currentTextChanged(const QString &arg1);

    void on_pushButtonExit_clicked();

    void on_pushButtonSort_clicked();

    void on_toolButton_clicked();

private:
    Ui::prepform *ui;
    QTcpSocket *socket;
    QByteArray data;
    void sendToServer(QString str);
    quint16 nextBlockSize;
    void closeEvent(QCloseEvent *event);
public slots:
    void slotComboBoxStatLoad();
    void slotComboBoxStudents();
    void slotGetId();

};

#endif // PREPFORM_H
