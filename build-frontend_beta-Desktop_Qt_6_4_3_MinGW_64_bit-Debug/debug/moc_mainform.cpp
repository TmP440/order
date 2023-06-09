/****************************************************************************
** Meta object code from reading C++ file 'mainform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend_beta/mainform.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainForm_t {
    uint offsetsAndSizes[24];
    char stringdata0[9];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[24];
    char stringdata5[24];
    char stringdata6[27];
    char stringdata7[27];
    char stringdata8[28];
    char stringdata9[21];
    char stringdata10[10];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainForm_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainForm_t qt_meta_stringdata_MainForm = {
    {
        QT_MOC_LITERAL(0, 8),  // "MainForm"
        QT_MOC_LITERAL(9, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 31),  // "on_pushButtonUpdateStat_clicked"
        QT_MOC_LITERAL(64, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(88, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(112, 26),  // "on_pushButtonTask4_clicked"
        QT_MOC_LITERAL(139, 26),  // "on_pushButtonTask5_clicked"
        QT_MOC_LITERAL(166, 27),  // "on_pushButtonAnswer_clicked"
        QT_MOC_LITERAL(194, 20),  // "slotButtonUpdateStat"
        QT_MOC_LITERAL(215, 9),  // "slotGetId"
        QT_MOC_LITERAL(225, 13)   // "slotCheckTask"
    },
    "MainForm",
    "on_pushButton_clicked",
    "",
    "on_pushButtonUpdateStat_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_3_clicked",
    "on_pushButtonTask4_clicked",
    "on_pushButtonTask5_clicked",
    "on_pushButtonAnswer_clicked",
    "slotButtonUpdateStat",
    "slotGetId",
    "slotCheckTask"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x0a,    8 /* Public */,
      10,    0,   82,    2, 0x0a,    9 /* Public */,
      11,    0,   83,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainForm.offsetsAndSizes,
    qt_meta_data_MainForm,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainForm_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainForm, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUpdateStat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonTask4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonTask5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAnswer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotButtonUpdateStat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotGetId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotCheckTask'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButtonUpdateStat_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButtonTask4_clicked(); break;
        case 5: _t->on_pushButtonTask5_clicked(); break;
        case 6: _t->on_pushButtonAnswer_clicked(); break;
        case 7: _t->slotButtonUpdateStat(); break;
        case 8: _t->slotGetId(); break;
        case 9: _t->slotCheckTask(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
