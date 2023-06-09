/********************************************************************************
** Form generated from reading UI file 'prepform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPFORM_H
#define UI_PREPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prepform
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowserStat;
    QLabel *label;
    QLabel *labelPrepLogin;
    QComboBox *comboBoxStudents;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonExit;
    QLabel *label_4;
    QLabel *label_id;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *prepform)
    {
        if (prepform->objectName().isEmpty())
            prepform->setObjectName("prepform");
        prepform->resize(800, 473);
        centralwidget = new QWidget(prepform);
        centralwidget->setObjectName("centralwidget");
        textBrowserStat = new QTextBrowser(centralwidget);
        textBrowserStat->setObjectName("textBrowserStat");
        textBrowserStat->setGeometry(QRect(40, 60, 256, 281));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 30, 101, 16));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        labelPrepLogin = new QLabel(centralwidget);
        labelPrepLogin->setObjectName("labelPrepLogin");
        labelPrepLogin->setGeometry(QRect(670, 10, 121, 31));
        QFont font1;
        font1.setPointSize(15);
        labelPrepLogin->setFont(font1);
        comboBoxStudents = new QComboBox(centralwidget);
        comboBoxStudents->setObjectName("comboBoxStudents");
        comboBoxStudents->setGeometry(QRect(130, 350, 151, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 350, 71, 21));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(560, 10, 111, 31));
        label_3->setFont(font1);
        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName("pushButtonExit");
        pushButtonExit->setGeometry(QRect(660, 90, 101, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 40, 71, 31));
        label_4->setFont(font1);
        label_id = new QLabel(centralwidget);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(630, 40, 61, 31));
        label_id->setFont(font1);
        prepform->setCentralWidget(centralwidget);
        menubar = new QMenuBar(prepform);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        prepform->setMenuBar(menubar);
        statusbar = new QStatusBar(prepform);
        statusbar->setObjectName("statusbar");
        prepform->setStatusBar(statusbar);

        retranslateUi(prepform);

        QMetaObject::connectSlotsByName(prepform);
    } // setupUi

    void retranslateUi(QMainWindow *prepform)
    {
        prepform->setWindowTitle(QCoreApplication::translate("prepform", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("prepform", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        labelPrepLogin->setText(QCoreApplication::translate("prepform", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("prepform", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("prepform", "\320\222\320\260\321\210 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("prepform", "\320\262\321\213\321\205\320\276\320\264", nullptr));
        label_4->setText(QCoreApplication::translate("prepform", "\320\222\320\260\321\210 ID:", nullptr));
        label_id->setText(QCoreApplication::translate("prepform", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prepform: public Ui_prepform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPFORM_H
