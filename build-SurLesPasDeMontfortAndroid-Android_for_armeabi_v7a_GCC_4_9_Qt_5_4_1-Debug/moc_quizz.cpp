/****************************************************************************
** Meta object code from reading C++ file 'quizz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SurLesPasDeMontfortAndroid/quizz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quizz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Quizz_t {
    QByteArrayData data[14];
    char stringdata[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Quizz_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Quizz_t qt_meta_stringdata_Quizz = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Quizz"
QT_MOC_LITERAL(1, 6, 12), // "listeChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "listeCleared"
QT_MOC_LITERAL(4, 33, 12), // "countChanged"
QT_MOC_LITERAL(5, 46, 22), // "questionEnCoursChanged"
QT_MOC_LITERAL(6, 69, 5), // "clear"
QT_MOC_LITERAL(7, 75, 16), // "questionSuivante"
QT_MOC_LITERAL(8, 92, 10), // "debutQuizz"
QT_MOC_LITERAL(9, 103, 5), // "liste"
QT_MOC_LITERAL(10, 109, 15), // "QList<QObject*>"
QT_MOC_LITERAL(11, 125, 5), // "count"
QT_MOC_LITERAL(12, 131, 15), // "questionEnCours"
QT_MOC_LITERAL(13, 147, 9) // "Question*"

    },
    "Quizz\0listeChanged\0\0listeCleared\0"
    "countChanged\0questionEnCoursChanged\0"
    "clear\0questionSuivante\0debutQuizz\0"
    "liste\0QList<QObject*>\0count\0questionEnCours\0"
    "Question*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Quizz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
       9, 0x80000000 | 10, 0x00495009,
      11, QMetaType::Int, 0x00495001,
      12, 0x80000000 | 13, 0x00495009,

 // properties: notify_signal_id
       0,
       2,
       3,

       0        // eod
};

void Quizz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Quizz *_t = static_cast<Quizz *>(_o);
        switch (_id) {
        case 0: _t->listeChanged(); break;
        case 1: _t->listeCleared(); break;
        case 2: _t->countChanged(); break;
        case 3: _t->questionEnCoursChanged(); break;
        case 4: _t->clear(); break;
        case 5: { bool _r = _t->questionSuivante();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->debutQuizz(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Quizz::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Quizz::listeChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Quizz::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Quizz::listeCleared)) {
                *result = 1;
            }
        }
        {
            typedef void (Quizz::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Quizz::countChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Quizz::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Quizz::questionEnCoursChanged)) {
                *result = 3;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Question* >(); break;
        }
    }

}

const QMetaObject Quizz::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Quizz.data,
      qt_meta_data_Quizz,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Quizz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Quizz::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Quizz.stringdata))
        return static_cast<void*>(const_cast< Quizz*>(this));
    return QObject::qt_metacast(_clname);
}

int Quizz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QObject*>*>(_v) = liste(); break;
        case 1: *reinterpret_cast< int*>(_v) = count(); break;
        case 2: *reinterpret_cast< Question**>(_v) = questionEnCours(); break;
        default: break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Quizz::listeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Quizz::listeCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Quizz::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Quizz::questionEnCoursChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
