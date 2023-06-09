/****************************************************************************
** Meta object code from reading C++ file 'prepform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend_beta/prepform.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prepform.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_prepform_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[39];
    char stringdata4[5];
    char stringdata5[26];
    char stringdata6[21];
    char stringdata7[21];
    char stringdata8[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_prepform_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_prepform_t qt_meta_stringdata_prepform = {
    {
        QT_MOC_LITERAL(0, 8),  // "prepform"
        QT_MOC_LITERAL(9, 31),  // "on_pushButtonUpdateStat_clicked"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 38),  // "on_comboBoxStudents_currentTe..."
        QT_MOC_LITERAL(81, 4),  // "arg1"
        QT_MOC_LITERAL(86, 25),  // "on_pushButtonExit_clicked"
        QT_MOC_LITERAL(112, 20),  // "slotComboBoxStatLoad"
        QT_MOC_LITERAL(133, 20),  // "slotComboBoxStudents"
        QT_MOC_LITERAL(154, 9)   // "slotGetId"
    },
    "prepform",
    "on_pushButtonUpdateStat_clicked",
    "",
    "on_comboBoxStudents_currentTextChanged",
    "arg1",
    "on_pushButtonExit_clicked",
    "slotComboBoxStatLoad",
    "slotComboBoxStudents",
    "slotGetId"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_prepform[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    1,   51,    2, 0x08,    2 /* Private */,
       5,    0,   54,    2, 0x08,    4 /* Private */,
       6,    0,   55,    2, 0x0a,    5 /* Public */,
       7,    0,   56,    2, 0x0a,    6 /* Public */,
       8,    0,   57,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject prepform::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_prepform.offsetsAndSizes,
    qt_meta_data_prepform,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_prepform_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<prepform, std::true_type>,
        // method 'on_pushButtonUpdateStat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxStudents_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonExit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotComboBoxStatLoad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotComboBoxStudents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotGetId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void prepform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<prepform *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonUpdateStat_clicked(); break;
        case 1: _t->on_comboBoxStudents_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_pushButtonExit_clicked(); break;
        case 3: _t->slotComboBoxStatLoad(); break;
        case 4: _t->slotComboBoxStudents(); break;
        case 5: _t->slotGetId(); break;
        default: ;
        }
    }
}

const QMetaObject *prepform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *prepform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_prepform.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int prepform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
