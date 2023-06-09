/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButtonTask4;
    QPushButton *pushButtonTask5;
    QLabel *labelStudLogin;
    QTextBrowser *textBrowserStudStat;
    QLabel *labelStat;
    QPushButton *pushButtonUpdateStat;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_id;
    QTextBrowser *textBrowserTask;
    QLabel *labelTaskNum;
    QLineEdit *lineEditAnswer;
    QPushButton *pushButtonAnswer;
    QLabel *labelTaskName;
    QComboBox *comboBoxAnswer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(695, 578);
        centralwidget = new QWidget(MainForm);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 90, 661, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        pushButtonTask4 = new QPushButton(layoutWidget);
        pushButtonTask4->setObjectName("pushButtonTask4");

        horizontalLayout->addWidget(pushButtonTask4);

        pushButtonTask5 = new QPushButton(layoutWidget);
        pushButtonTask5->setObjectName("pushButtonTask5");

        horizontalLayout->addWidget(pushButtonTask5);

        labelStudLogin = new QLabel(centralwidget);
        labelStudLogin->setObjectName("labelStudLogin");
        labelStudLogin->setGeometry(QRect(550, 10, 131, 31));
        QFont font;
        font.setPointSize(15);
        labelStudLogin->setFont(font);
        textBrowserStudStat = new QTextBrowser(centralwidget);
        textBrowserStudStat->setObjectName("textBrowserStudStat");
        textBrowserStudStat->setGeometry(QRect(30, 180, 256, 311));
        labelStat = new QLabel(centralwidget);
        labelStat->setObjectName("labelStat");
        labelStat->setGeometry(QRect(110, 140, 101, 31));
        QFont font1;
        font1.setPointSize(14);
        labelStat->setFont(font1);
        pushButtonUpdateStat = new QPushButton(centralwidget);
        pushButtonUpdateStat->setObjectName("pushButtonUpdateStat");
        pushButtonUpdateStat->setGeometry(QRect(80, 500, 161, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(440, 10, 111, 31));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 40, 71, 31));
        label_2->setFont(font);
        label_id = new QLabel(centralwidget);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(510, 40, 81, 31));
        label_id->setFont(font);
        textBrowserTask = new QTextBrowser(centralwidget);
        textBrowserTask->setObjectName("textBrowserTask");
        textBrowserTask->setGeometry(QRect(330, 180, 331, 311));
        QFont font2;
        font2.setPointSize(12);
        textBrowserTask->setFont(font2);
        labelTaskNum = new QLabel(centralwidget);
        labelTaskNum->setObjectName("labelTaskNum");
        labelTaskNum->setGeometry(QRect(330, 160, 91, 16));
        lineEditAnswer = new QLineEdit(centralwidget);
        lineEditAnswer->setObjectName("lineEditAnswer");
        lineEditAnswer->setGeometry(QRect(330, 500, 231, 22));
        pushButtonAnswer = new QPushButton(centralwidget);
        pushButtonAnswer->setObjectName("pushButtonAnswer");
        pushButtonAnswer->setGeometry(QRect(570, 500, 91, 24));
        labelTaskName = new QLabel(centralwidget);
        labelTaskName->setObjectName("labelTaskName");
        labelTaskName->setGeometry(QRect(450, 140, 121, 31));
        QFont font3;
        font3.setPointSize(16);
        font3.setKerning(false);
        labelTaskName->setFont(font3);
        comboBoxAnswer = new QComboBox(centralwidget);
        comboBoxAnswer->addItem(QString());
        comboBoxAnswer->addItem(QString());
        comboBoxAnswer->setObjectName("comboBoxAnswer");
        comboBoxAnswer->setGeometry(QRect(330, 500, 231, 22));
        MainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainForm);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 695, 22));
        MainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(MainForm);
        statusbar->setObjectName("statusbar");
        MainForm->setStatusBar(statusbar);

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 3", nullptr));
        pushButtonTask4->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 4", nullptr));
        pushButtonTask5->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 5", nullptr));
        labelStudLogin->setText(QCoreApplication::translate("MainForm", "TextLabel", nullptr));
        labelStat->setText(QCoreApplication::translate("MainForm", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        pushButtonUpdateStat->setText(QCoreApplication::translate("MainForm", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainForm", "\320\222\320\260\321\210 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QCoreApplication::translate("MainForm", "\320\222\320\260\321\210 ID:", nullptr));
        label_id->setText(QCoreApplication::translate("MainForm", "TextLabel", nullptr));
        labelTaskNum->setText(QCoreApplication::translate("MainForm", "TextLabel", nullptr));
        pushButtonAnswer->setText(QCoreApplication::translate("MainForm", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        labelTaskName->setText(QCoreApplication::translate("MainForm", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        comboBoxAnswer->setItemText(0, QCoreApplication::translate("MainForm", "\320\224\320\260", nullptr));
        comboBoxAnswer->setItemText(1, QCoreApplication::translate("MainForm", "\320\235\320\265\321\202", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
