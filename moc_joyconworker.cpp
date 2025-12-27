/****************************************************************************
** Meta object code from reading C++ file 'joyconworker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "joyconworker.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joyconworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
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
struct qt_meta_tag_ZN12JoyConWorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto JoyConWorker::qt_create_metaobjectdata<qt_meta_tag_ZN12JoyConWorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "JoyConWorker",
        "deviceConnectionChanged",
        "",
        "deviceStatusMessage",
        "newDeviceInfo",
        "QList<uchar>",
        "newTemperatureData",
        "newBatteryData",
        "newCameraImage",
        "newInputData",
        "QList<int>",
        "QList<double>",
        "silentDisconnectDetected",
        "finished",
        "setup",
        "onConnectHID",
        "vendor_id",
        "product_id",
        "const wchar_t*",
        "serial_number",
        "onDisconnectHID",
        "requestDeviceInfo",
        "requestTemperature",
        "requestBattery",
        "requestJoyConInputs",
        "onInputStreamingEnabled",
        "enabled",
        "onIrConfigUpdated",
        "ir_image_config",
        "ir_new_config",
        "get_raw_ir_image",
        "show_status",
        "onInputPollTimerTimeout",
        "onDeviceStatusTimerTimeout",
        "onIrCaptureTimerTimeout"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'deviceConnectionChanged'
        QtMocHelpers::SignalData<void(QString, const unsigned short)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::UShort, 2 },
        }}),
        // Signal 'deviceStatusMessage'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'newDeviceInfo'
        QtMocHelpers::SignalData<void(QList<unsigned char>, int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 },
        }}),
        // Signal 'newTemperatureData'
        QtMocHelpers::SignalData<void(float)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 2 },
        }}),
        // Signal 'newBatteryData'
        QtMocHelpers::SignalData<void(int, int, int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Signal 'newCameraImage'
        QtMocHelpers::SignalData<void(QImage)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QImage, 2 },
        }}),
        // Signal 'newInputData'
        QtMocHelpers::SignalData<void(QList<int>, QList<double>)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 },
        }}),
        // Signal 'silentDisconnectDetected'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setup'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onConnectHID'
        QtMocHelpers::SlotData<void(unsigned short, unsigned short, const wchar_t *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UShort, 16 }, { QMetaType::UShort, 17 }, { 0x80000000 | 18, 19 },
        }}),
        // Slot 'onDisconnectHID'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestDeviceInfo'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestTemperature'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestBattery'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'requestJoyConInputs'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onInputStreamingEnabled'
        QtMocHelpers::SlotData<void(bool)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 26 },
        }}),
        // Slot 'onIrConfigUpdated'
        QtMocHelpers::SlotData<void(ir_image_config)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 },
        }}),
        // Slot 'get_raw_ir_image'
        QtMocHelpers::SlotData<int(unsigned char)>(30, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::UChar, 31 },
        }}),
        // Slot 'get_raw_ir_image'
        QtMocHelpers::SlotData<int()>(30, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Int),
        // Slot 'onInputPollTimerTimeout'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onDeviceStatusTimerTimeout'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onIrCaptureTimerTimeout'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<JoyConWorker, qt_meta_tag_ZN12JoyConWorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject JoyConWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12JoyConWorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12JoyConWorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12JoyConWorkerE_t>.metaTypes,
    nullptr
} };

void JoyConWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<JoyConWorker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->deviceConnectionChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2]))); break;
        case 1: _t->deviceStatusMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->newDeviceInfo((*reinterpret_cast< std::add_pointer_t<QList<uchar>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->newTemperatureData((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->newBatteryData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->newCameraImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 6: _t->newInputData((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2]))); break;
        case 7: _t->silentDisconnectDetected(); break;
        case 8: _t->finished(); break;
        case 9: _t->setup(); break;
        case 10: _t->onConnectHID((*reinterpret_cast< std::add_pointer_t<ushort>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<const wchar_t*>>(_a[3]))); break;
        case 11: _t->onDisconnectHID(); break;
        case 12: _t->requestDeviceInfo(); break;
        case 13: _t->requestTemperature(); break;
        case 14: _t->requestBattery(); break;
        case 15: _t->requestJoyConInputs(); break;
        case 16: _t->onInputStreamingEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->onIrConfigUpdated((*reinterpret_cast< std::add_pointer_t<ir_image_config>>(_a[1]))); break;
        case 18: { int _r = _t->get_raw_ir_image((*reinterpret_cast< std::add_pointer_t<uchar>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: { int _r = _t->get_raw_ir_image();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->onInputPollTimerTimeout(); break;
        case 21: _t->onDeviceStatusTimerTimeout(); break;
        case 22: _t->onIrCaptureTimerTimeout(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<uchar> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<double> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ir_image_config >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(QString , const unsigned short )>(_a, &JoyConWorker::deviceConnectionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(QString )>(_a, &JoyConWorker::deviceStatusMessage, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(QList<unsigned char> , int )>(_a, &JoyConWorker::newDeviceInfo, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(float )>(_a, &JoyConWorker::newTemperatureData, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(int , int , int )>(_a, &JoyConWorker::newBatteryData, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(QImage )>(_a, &JoyConWorker::newCameraImage, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)(QList<int> , QList<double> )>(_a, &JoyConWorker::newInputData, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)()>(_a, &JoyConWorker::silentDisconnectDetected, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (JoyConWorker::*)()>(_a, &JoyConWorker::finished, 8))
            return;
    }
}

const QMetaObject *JoyConWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JoyConWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12JoyConWorkerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JoyConWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void JoyConWorker::deviceConnectionChanged(QString _t1, const unsigned short _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void JoyConWorker::deviceStatusMessage(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void JoyConWorker::newDeviceInfo(QList<unsigned char> _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void JoyConWorker::newTemperatureData(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void JoyConWorker::newBatteryData(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2, _t3);
}

// SIGNAL 5
void JoyConWorker::newCameraImage(QImage _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void JoyConWorker::newInputData(QList<int> _t1, QList<double> _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void JoyConWorker::silentDisconnectDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void JoyConWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
