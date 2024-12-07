/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../OS_Lab9_Server/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_createRoomButton_clicked",
    "",
    "on_startSessionPushButton_clicked",
    "on_EndSessionButton_clicked",
    "on_homeButton_clicked",
    "AddUserInTable",
    "QWidget*",
    "page",
    "std::string",
    "sUserName",
    "AddIdea",
    "sIdea",
    "on_topicLineEdit_textChanged",
    "arg1",
    "on_stackedWidget_currentChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[34];
    char stringdata4[28];
    char stringdata5[22];
    char stringdata6[15];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[12];
    char stringdata10[10];
    char stringdata11[8];
    char stringdata12[6];
    char stringdata13[29];
    char stringdata14[5];
    char stringdata15[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 27),  // "on_createRoomButton_clicked"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 33),  // "on_startSessionPushButton_cli..."
        QT_MOC_LITERAL(74, 27),  // "on_EndSessionButton_clicked"
        QT_MOC_LITERAL(102, 21),  // "on_homeButton_clicked"
        QT_MOC_LITERAL(124, 14),  // "AddUserInTable"
        QT_MOC_LITERAL(139, 8),  // "QWidget*"
        QT_MOC_LITERAL(148, 4),  // "page"
        QT_MOC_LITERAL(153, 11),  // "std::string"
        QT_MOC_LITERAL(165, 9),  // "sUserName"
        QT_MOC_LITERAL(175, 7),  // "AddIdea"
        QT_MOC_LITERAL(183, 5),  // "sIdea"
        QT_MOC_LITERAL(189, 28),  // "on_topicLineEdit_textChanged"
        QT_MOC_LITERAL(218, 4),  // "arg1"
        QT_MOC_LITERAL(223, 31)   // "on_stackedWidget_currentChanged"
    },
    "MainWindow",
    "on_createRoomButton_clicked",
    "",
    "on_startSessionPushButton_clicked",
    "on_EndSessionButton_clicked",
    "on_homeButton_clicked",
    "AddUserInTable",
    "QWidget*",
    "page",
    "std::string",
    "sUserName",
    "AddIdea",
    "sIdea",
    "on_topicLineEdit_textChanged",
    "arg1",
    "on_stackedWidget_currentChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    2,   66,    2, 0x08,    5 /* Private */,
      11,    1,   71,    2, 0x08,    8 /* Private */,
      13,    1,   74,    2, 0x08,   10 /* Private */,
      15,    1,   77,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 7, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 9,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_createRoomButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startSessionPushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EndSessionButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_homeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddUserInTable'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'AddIdea'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'on_topicLineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_stackedWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_createRoomButton_clicked(); break;
        case 1: _t->on_startSessionPushButton_clicked(); break;
        case 2: _t->on_EndSessionButton_clicked(); break;
        case 3: _t->on_homeButton_clicked(); break;
        case 4: { bool _r = _t->AddUserInTable((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->AddIdea((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 6: _t->on_topicLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_stackedWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
