/****************************************************************************
** Meta object code from reading C++ file 'question.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SurLesPasDeMontfortAndroid/question.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'question.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Question_t {
    QByteArrayData data[20];
    char stringdata[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Question_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Question_t qt_meta_stringdata_Question = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Question"
QT_MOC_LITERAL(1, 9, 15), // "questionChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "bonneReponseChanged"
QT_MOC_LITERAL(4, 46, 23), // "mauvaiseReponse1Changed"
QT_MOC_LITERAL(5, 70, 23), // "mauvaiseReponse2Changed"
QT_MOC_LITERAL(6, 94, 23), // "mauvaiseReponse3Changed"
QT_MOC_LITERAL(7, 118, 15), // "nomBorneChanged"
QT_MOC_LITERAL(8, 134, 11), // "setQuestion"
QT_MOC_LITERAL(9, 146, 8), // "question"
QT_MOC_LITERAL(10, 155, 15), // "setBonneReponse"
QT_MOC_LITERAL(11, 171, 12), // "bonneReponse"
QT_MOC_LITERAL(12, 184, 19), // "setMauvaiseReponse1"
QT_MOC_LITERAL(13, 204, 16), // "mauvaiseReponse1"
QT_MOC_LITERAL(14, 221, 19), // "setMauvaiseReponse2"
QT_MOC_LITERAL(15, 241, 16), // "mauvaiseReponse2"
QT_MOC_LITERAL(16, 258, 19), // "setMauvaiseReponse3"
QT_MOC_LITERAL(17, 278, 16), // "mauvaiseReponse3"
QT_MOC_LITERAL(18, 295, 11), // "setNomBorne"
QT_MOC_LITERAL(19, 307, 8) // "nomBorne"

    },
    "Question\0questionChanged\0\0bonneReponseChanged\0"
    "mauvaiseReponse1Changed\0mauvaiseReponse2Changed\0"
    "mauvaiseReponse3Changed\0nomBorneChanged\0"
    "setQuestion\0question\0setBonneReponse\0"
    "bonneReponse\0setMauvaiseReponse1\0"
    "mauvaiseReponse1\0setMauvaiseReponse2\0"
    "mauvaiseReponse2\0setMauvaiseReponse3\0"
    "mauvaiseReponse3\0setNomBorne\0nomBorne"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Question[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       6,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   80,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      16,    1,   92,    2, 0x0a /* Public */,
      18,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void Question::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Question *_t = static_cast<Question *>(_o);
        switch (_id) {
        case 0: _t->questionChanged(); break;
        case 1: _t->bonneReponseChanged(); break;
        case 2: _t->mauvaiseReponse1Changed(); break;
        case 3: _t->mauvaiseReponse2Changed(); break;
        case 4: _t->mauvaiseReponse3Changed(); break;
        case 5: _t->nomBorneChanged(); break;
        case 6: _t->setQuestion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setBonneReponse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setMauvaiseReponse1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setMauvaiseReponse2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setMauvaiseReponse3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setNomBorne((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::questionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::bonneReponseChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::mauvaiseReponse1Changed)) {
                *result = 2;
            }
        }
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::mauvaiseReponse2Changed)) {
                *result = 3;
            }
        }
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::mauvaiseReponse3Changed)) {
                *result = 4;
            }
        }
        {
            typedef void (Question::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Question::nomBorneChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Question::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Question.data,
      qt_meta_data_Question,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Question::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Question::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Question.stringdata))
        return static_cast<void*>(const_cast< Question*>(this));
    return QObject::qt_metacast(_clname);
}

int Question::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = question(); break;
        case 1: *reinterpret_cast< QString*>(_v) = bonneReponse(); break;
        case 2: *reinterpret_cast< QString*>(_v) = mauvaiseReponse1(); break;
        case 3: *reinterpret_cast< QString*>(_v) = mauvaiseReponse2(); break;
        case 4: *reinterpret_cast< QString*>(_v) = mauvaiseReponse3(); break;
        case 5: *reinterpret_cast< QString*>(_v) = nomBorne(); break;
        default: break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setQuestion(*reinterpret_cast< QString*>(_v)); break;
        case 1: setBonneReponse(*reinterpret_cast< QString*>(_v)); break;
        case 2: setMauvaiseReponse1(*reinterpret_cast< QString*>(_v)); break;
        case 3: setMauvaiseReponse2(*reinterpret_cast< QString*>(_v)); break;
        case 4: setMauvaiseReponse3(*reinterpret_cast< QString*>(_v)); break;
        case 5: setNomBorne(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Question::questionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Question::bonneReponseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Question::mauvaiseReponse1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Question::mauvaiseReponse2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Question::mauvaiseReponse3Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Question::nomBorneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
