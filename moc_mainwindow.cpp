/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "connectHID",
        "",
        "vendor_id",
        "product_id",
        "const wchar_t*",
        "serial_number",
        "disconnectHID",
        "enableInputStreaming",
        "updateIrConfig",
        "ir_image_config",
        "captureImage",
        "onShow",
        "onHide",
        "onCameraImageData",
        "img",
        "hideAndClose",
        "onNewInputData",
        "QList<int>",
        "button_data",
        "QList<double>",
        "analog_data",
        "onDeviceConnectionChanged",
        "sn",
        "pid",
        "onJoyConStatusMessage",
        "message",
        "onDeviceInfoData",
        "QList<uchar>",
        "device_info",
        "joycon_type",
        "onTemperatureData",
        "temp_c",
        "onBatteryData",
        "volt",
        "percent",
        "status",
        "on_pushButtonCapture_clicked",
        "on_pushButtonStream_clicked",
        "on_checkBoxDiagnostics_toggled",
        "checked",
        "on_checkBoxAppNap_toggled",
        "on_checkBoxIdleSleep_toggled",
        "on_toolButtonRefresh_clicked",
        "on_toolButtonConnect_clicked",
        "on_toolButtonDisconnect_clicked",
        "on_checkBoxInvertIcon_toggled",
        "on_pushButtonSaveImage_clicked",
        "on_comboBoxColorMap_currentIndexChanged",
        "index",
        "showAbout",
        "on_checkBoxLeftClick_toggled",
        "on_checkBoxRightClick_toggled",
        "on_checkBoxRequireZR_toggled",
        "on_checkBoxInvertZR_toggled",
        "on_checkBoxOnlyNintendo_toggled",
        "on_checkBoxAutoConnectDevices_toggled",
        "onAutoConnectTimer"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connectHID'
        QtMocHelpers::SignalData<void(unsigned short, unsigned short, const wchar_t *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UShort, 3 }, { QMetaType::UShort, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'disconnectHID'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'enableInputStreaming'
        QtMocHelpers::SignalData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'updateIrConfig'
        QtMocHelpers::SignalData<void(ir_image_config)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 2 },
        }}),
        // Signal 'captureImage'
        QtMocHelpers::SignalData<void(unsigned char)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UChar, 2 },
        }}),
        // Slot 'onShow'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onHide'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onCameraImageData'
        QtMocHelpers::SlotData<void(QImage)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QImage, 15 },
        }}),
        // Slot 'hideAndClose'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onNewInputData'
        QtMocHelpers::SlotData<void(QList<int>, QList<double>)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 19 }, { 0x80000000 | 20, 21 },
        }}),
        // Slot 'onDeviceConnectionChanged'
        QtMocHelpers::SlotData<void(QString, const unsigned short)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 23 }, { QMetaType::UShort, 24 },
        }}),
        // Slot 'onJoyConStatusMessage'
        QtMocHelpers::SlotData<void(QString)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 26 },
        }}),
        // Slot 'onDeviceInfoData'
        QtMocHelpers::SlotData<void(QList<unsigned char>, int)>(27, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 28, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'onTemperatureData'
        QtMocHelpers::SlotData<void(float)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 32 },
        }}),
        // Slot 'onBatteryData'
        QtMocHelpers::SlotData<void(int, int, int)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 34 }, { QMetaType::Int, 35 }, { QMetaType::Int, 36 },
        }}),
        // Slot 'on_pushButtonCapture_clicked'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonStream_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBoxDiagnostics_toggled'
        QtMocHelpers::SlotData<void(bool)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxAppNap_toggled'
        QtMocHelpers::SlotData<void(bool)>(41, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxIdleSleep_toggled'
        QtMocHelpers::SlotData<void(bool)>(42, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_toolButtonRefresh_clicked'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonConnect_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_toolButtonDisconnect_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBoxInvertIcon_toggled'
        QtMocHelpers::SlotData<void(bool)>(46, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_pushButtonSaveImage_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_comboBoxColorMap_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(48, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 49 },
        }}),
        // Slot 'showAbout'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBoxLeftClick_toggled'
        QtMocHelpers::SlotData<void(bool)>(51, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxRightClick_toggled'
        QtMocHelpers::SlotData<void(bool)>(52, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxRequireZR_toggled'
        QtMocHelpers::SlotData<void(bool)>(53, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxInvertZR_toggled'
        QtMocHelpers::SlotData<void(bool)>(54, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxOnlyNintendo_toggled'
        QtMocHelpers::SlotData<void(bool)>(55, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'on_checkBoxAutoConnectDevices_toggled'
        QtMocHelpers::SlotData<void(bool)>(56, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 40 },
        }}),
        // Slot 'onAutoConnectTimer'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connectHID((*reinterpret_cast< std::add_pointer_t<ushort>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<const wchar_t*>>(_a[3]))); break;
        case 1: _t->disconnectHID(); break;
        case 2: _t->enableInputStreaming((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->updateIrConfig((*reinterpret_cast< std::add_pointer_t<ir_image_config>>(_a[1]))); break;
        case 4: _t->captureImage((*reinterpret_cast< std::add_pointer_t<uchar>>(_a[1]))); break;
        case 5: _t->onShow(); break;
        case 6: _t->onHide(); break;
        case 7: _t->onCameraImageData((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 8: _t->hideAndClose(); break;
        case 9: _t->onNewInputData((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<double>>>(_a[2]))); break;
        case 10: _t->onDeviceConnectionChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2]))); break;
        case 11: _t->onJoyConStatusMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->onDeviceInfoData((*reinterpret_cast< std::add_pointer_t<QList<uchar>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->onTemperatureData((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 14: _t->onBatteryData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->on_pushButtonCapture_clicked(); break;
        case 16: _t->on_pushButtonStream_clicked(); break;
        case 17: _t->on_checkBoxDiagnostics_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->on_checkBoxAppNap_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_checkBoxIdleSleep_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_toolButtonRefresh_clicked(); break;
        case 21: _t->on_toolButtonConnect_clicked(); break;
        case 22: _t->on_toolButtonDisconnect_clicked(); break;
        case 23: _t->on_checkBoxInvertIcon_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->on_pushButtonSaveImage_clicked(); break;
        case 25: _t->on_comboBoxColorMap_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->showAbout(); break;
        case 27: _t->on_checkBoxLeftClick_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->on_checkBoxRightClick_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 29: _t->on_checkBoxRequireZR_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->on_checkBoxInvertZR_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 31: _t->on_checkBoxOnlyNintendo_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: _t->on_checkBoxAutoConnectDevices_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 33: _t->onAutoConnectTimer(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ir_image_config >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<double> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<uchar> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(unsigned short , unsigned short , const wchar_t * )>(_a, &MainWindow::connectHID, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::disconnectHID, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool )>(_a, &MainWindow::enableInputStreaming, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(ir_image_config )>(_a, &MainWindow::updateIrConfig, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(unsigned char )>(_a, &MainWindow::captureImage, 4))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::connectHID(unsigned short _t1, unsigned short _t2, const wchar_t * _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void MainWindow::disconnectHID()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::enableInputStreaming(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void MainWindow::updateIrConfig(ir_image_config _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MainWindow::captureImage(unsigned char _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
