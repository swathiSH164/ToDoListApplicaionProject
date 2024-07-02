/****************************************************************************
** Meta object code from reading C++ file 'TaskModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TaskModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskModel_t {
    QByteArrayData data[22];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskModel_t qt_meta_stringdata_TaskModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TaskModel"
QT_MOC_LITERAL(1, 10, 11), // "datachanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "showdatachange"
QT_MOC_LITERAL(4, 38, 8), // "senddate"
QT_MOC_LITERAL(5, 47, 4), // "data"
QT_MOC_LITERAL(6, 52, 7), // "addTask"
QT_MOC_LITERAL(7, 60, 4), // "a_id"
QT_MOC_LITERAL(8, 65, 6), // "a_name"
QT_MOC_LITERAL(9, 72, 6), // "a_time"
QT_MOC_LITERAL(10, 79, 6), // "a_date"
QT_MOC_LITERAL(11, 86, 8), // "viewTask"
QT_MOC_LITERAL(12, 95, 17), // "showcompletedtask"
QT_MOC_LITERAL(13, 113, 18), // "onDeleteSuccessful"
QT_MOC_LITERAL(14, 132, 15), // "onAddSuccessful"
QT_MOC_LITERAL(15, 148, 12), // "completeTask"
QT_MOC_LITERAL(16, 161, 6), // "taskid"
QT_MOC_LITERAL(17, 168, 8), // "taskname"
QT_MOC_LITERAL(18, 177, 4), // "time"
QT_MOC_LITERAL(19, 182, 7), // "duedate"
QT_MOC_LITERAL(20, 190, 24), // "oncompletetasksuccessful"
QT_MOC_LITERAL(21, 215, 2) // "id"

    },
    "TaskModel\0datachanged\0\0showdatachange\0"
    "senddate\0data\0addTask\0a_id\0a_name\0"
    "a_time\0a_date\0viewTask\0showcompletedtask\0"
    "onDeleteSuccessful\0onAddSuccessful\0"
    "completeTask\0taskid\0taskname\0time\0"
    "duedate\0oncompletetasksuccessful\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    4,   73,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      14,    5,   87,    2, 0x0a /* Public */,
      15,    4,   98,    2, 0x0a /* Public */,
      20,    4,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   17,   18,   19,

       0        // eod
};

void TaskModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->datachanged(); break;
        case 1: _t->showdatachange(); break;
        case 2: _t->senddate(); break;
        case 3: _t->data(); break;
        case 4: _t->addTask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 5: _t->viewTask(); break;
        case 6: _t->showcompletedtask(); break;
        case 7: _t->onDeleteSuccessful((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onAddSuccessful((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 9: _t->completeTask((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 10: _t->oncompletetasksuccessful((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TaskModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskModel::datachanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TaskModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskModel::showdatachange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TaskModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskModel::senddate)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TaskModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TaskModel::data)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TaskModel.data,
    qt_meta_data_TaskModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TaskModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TaskModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TaskModel::datachanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TaskModel::showdatachange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TaskModel::senddate()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TaskModel::data()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
