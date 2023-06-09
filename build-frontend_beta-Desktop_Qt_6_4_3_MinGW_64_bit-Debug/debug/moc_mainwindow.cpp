/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend_beta/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[24];
    char stringdata5[23];
    char stringdata6[40];
    char stringdata7[5];
    char stringdata8[37];
    char stringdata9[25];
    char stringdata10[9];
    char stringdata11[14];
    char stringdata12[8];
    char stringdata13[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "on_AuthButton_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 20),  // "on_RegButton_clicked"
        QT_MOC_LITERAL(55, 23),  // "on_toAuthButton_clicked"
        QT_MOC_LITERAL(79, 22),  // "on_toRegButton_clicked"
        QT_MOC_LITERAL(102, 39),  // "on_comboBoxRegStatus_currentT..."
        QT_MOC_LITERAL(142, 4),  // "arg1"
        QT_MOC_LITERAL(147, 36),  // "on_comboBoxStatus_currentText..."
        QT_MOC_LITERAL(184, 24),  // "on_pushButtonEye_clicked"
        QT_MOC_LITERAL(209, 8),  // "slotAuth"
        QT_MOC_LITERAL(218, 13),  // "slotReadyRead"
        QT_MOC_LITERAL(232, 7),  // "slotReg"
        QT_MOC_LITERAL(240, 10)   // "slotRegFio"
    },
    "MainWindow",
    "on_AuthButton_clicked",
    "",
    "on_RegButton_clicked",
    "on_toAuthButton_clicked",
    "on_toRegButton_clicked",
    "on_comboBoxRegStatus_currentTextChanged",
    "arg1",
    "on_comboBoxStatus_currentTextChanged",
    "on_pushButtonEye_clicked",
    "slotAuth",
    "slotReadyRead",
    "slotReg",
    "slotRegFio"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    1,   84,    2, 0x08,    5 /* Private */,
       8,    1,   87,    2, 0x08,    7 /* Private */,
       9,    0,   90,    2, 0x08,    9 /* Private */,
      10,    0,   91,    2, 0x0a,   10 /* Public */,
      11,    0,   92,    2, 0x0a,   11 /* Public */,
      12,    0,   93,    2, 0x0a,   12 /* Public */,
      13,    0,   94,    2, 0x0a,   13 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_AuthButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RegButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toAuthButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toRegButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxRegStatus_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBoxStatus_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonEye_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotAuth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRegFio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_AuthButton_clicked(); break;
        case 1: _t->on_RegButton_clicked(); break;
        case 2: _t->on_toAuthButton_clicked(); break;
        case 3: _t->on_toRegButton_clicked(); break;
        case 5: _t->on_comboBoxStatus_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_pushButtonEye_clicked(); break;
        case 7: _t->slotAuth(); break;
        case 8: _t->slotReadyRead(); break;
        case 9: _t->slotReg(); break;
        case 10: _t->slotRegFio(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
