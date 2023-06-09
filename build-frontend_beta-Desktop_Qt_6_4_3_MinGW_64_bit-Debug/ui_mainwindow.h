/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *labelLogin;
    QLabel *labelPassword;
    QPushButton *AuthButton;
    QPushButton *toRegButton;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
    QPushButton *RegButton;
    QPushButton *toAuthButton;
    QLabel *labelStatus;
    QLabel *labelPrepID;
    QLineEdit *lineEditPrepID;
    QComboBox *comboBoxStatus;
    QLabel *labelFio;
    QLineEdit *lineEditFio;
    QPushButton *pushButtonEye;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(496, 388);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 30, 391, 301));
        labelLogin = new QLabel(groupBox);
        labelLogin->setObjectName("labelLogin");
        labelLogin->setGeometry(QRect(70, 100, 51, 20));
        labelPassword = new QLabel(groupBox);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(70, 130, 51, 20));
        AuthButton = new QPushButton(groupBox);
        AuthButton->setObjectName("AuthButton");
        AuthButton->setGeometry(QRect(120, 160, 151, 24));
        toRegButton = new QPushButton(groupBox);
        toRegButton->setObjectName("toRegButton");
        toRegButton->setGeometry(QRect(120, 190, 151, 24));
        lineEditLogin = new QLineEdit(groupBox);
        lineEditLogin->setObjectName("lineEditLogin");
        lineEditLogin->setGeometry(QRect(120, 100, 151, 22));
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(120, 130, 151, 22));
        RegButton = new QPushButton(groupBox);
        RegButton->setObjectName("RegButton");
        RegButton->setEnabled(true);
        RegButton->setGeometry(QRect(120, 160, 151, 24));
        toAuthButton = new QPushButton(groupBox);
        toAuthButton->setObjectName("toAuthButton");
        toAuthButton->setGeometry(QRect(120, 190, 151, 24));
        labelStatus = new QLabel(groupBox);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(70, 70, 49, 16));
        labelPrepID = new QLabel(groupBox);
        labelPrepID->setObjectName("labelPrepID");
        labelPrepID->setGeometry(QRect(70, 40, 101, 16));
        lineEditPrepID = new QLineEdit(groupBox);
        lineEditPrepID->setObjectName("lineEditPrepID");
        lineEditPrepID->setGeometry(QRect(180, 40, 51, 22));
        comboBoxStatus = new QComboBox(groupBox);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName("comboBoxStatus");
        comboBoxStatus->setGeometry(QRect(120, 70, 151, 22));
        labelFio = new QLabel(groupBox);
        labelFio->setObjectName("labelFio");
        labelFio->setGeometry(QRect(70, 220, 51, 20));
        lineEditFio = new QLineEdit(groupBox);
        lineEditFio->setObjectName("lineEditFio");
        lineEditFio->setGeometry(QRect(120, 220, 151, 22));
        pushButtonEye = new QPushButton(groupBox);
        pushButtonEye->setObjectName("pushButtonEye");
        pushButtonEye->setGeometry(QRect(270, 130, 22, 22));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../server_beta/release/img/witness.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonEye->setIcon(icon);
        pushButtonEye->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        labelLogin->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        AuthButton->setText(QCoreApplication::translate("MainWindow", "\320\262\320\276\320\271\321\202\320\270", nullptr));
        toRegButton->setText(QCoreApplication::translate("MainWindow", "\320\272 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270", nullptr));
        RegButton->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        toAuthButton->setText(QCoreApplication::translate("MainWindow", "\320\272 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        labelPrepID->setText(QCoreApplication::translate("MainWindow", "ID \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        comboBoxStatus->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));

        labelFio->setText(QCoreApplication::translate("MainWindow", "    \320\244\320\230\320\236", nullptr));
        pushButtonEye->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
