#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hidapi.h"
#include "statuswidget.h"
#include "eventhandler.h"

#include <QVariant>
#include <QApplication>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSettings>

#include <cmath>

#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _status_widget(new StatusWidget(this)),
    _event_handler(new EventHandler())
{
    // set application info for settings
    QApplication::setApplicationDisplayName(APP_PRODUCT);
    QApplication::setApplicationVersion(APP_VERSION);
    QApplication::setOrganizationName(APP_COMPANY);
    QApplication::setOrganizationDomain(APP_COMPANY);
    ui->setupUi(this);

    // start with an empty pixmap on the label
    ui->labelCameraPreview->setPixmap(QPixmap::fromImage(_current_image));
    // prevent label size from overriding mainwindow size (lets the pixmap shrink)
    ui->labelCameraPreview->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    // add a StatusWidget displays battery and temperature info
    ui->statusBar->addPermanentWidget(_status_widget);

    //
    ui->inputMapL->setName("Left");
    ui->inputMapL->addMapper(new InputMapWidget("Up" ,L_BUT_UP | 512, Qt::Key_Up, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("Down",L_BUT_DOWN | 512, Qt::Key_Down, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("Left", L_BUT_LEFT | 512, Qt::Key_Left, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("Right", L_BUT_RIGHT | 512, Qt::Key_Right, _event_handler));
    _l_mapper = ui->inputMapL->addMapper(new InputMapWidget("L", L_BUT_L | 512, Qt::Key_H, _event_handler));
    _zl_mapper = ui->inputMapL->addMapper(new InputMapWidget("ZL", L_BUT_ZL | 512, Qt::Key_J, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("SL", L_BUT_SL | 512, Qt::Key_K, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("SR", L_BUT_SR | 512, Qt::Key_L, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("Minus", L_BUT_MINUS | 256, Qt::Key_Enter, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("Capture", L_BUT_CAP | 256, Qt::Key_Escape, _event_handler));
    ui->inputMapL->addMapper(new InputMapWidget("L Stick Click", L_BUT_STICK | 256, Qt::Key_Enter, _event_handler));
    ui->inputMapR->setName("Right");
    _x_mapper = ui->inputMapR->addMapper(new InputMapWidget("X", R_BUT_X, Qt::Key_Up, _event_handler));
    _y_mapper = ui->inputMapR->addMapper(new InputMapWidget("Y", R_BUT_Y, Qt::Key_Left, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("A",R_BUT_A, Qt::Key_Right, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("B",R_BUT_B, Qt::Key_Down, _event_handler));
    _r_mapper = ui->inputMapR->addMapper(new InputMapWidget("R", R_BUT_R, Qt::Key_A, _event_handler));
    _zr_mapper = ui->inputMapR->addMapper(new InputMapWidget("ZR", R_BUT_ZR, Qt::Key_S, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("SL", R_BUT_SL, Qt::Key_D, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("SR", R_BUT_SR, Qt::Key_F, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("Plus", R_BUT_PLUS | 256, Qt::Key_Enter, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("Home", R_BUT_HOME | 256, Qt::Key_Escape, _event_handler));
    ui->inputMapR->addMapper(new InputMapWidget("R Stick Click", R_BUT_STICK | 256, Qt::Key_Enter, _event_handler));

    // add color map options
    ui->comboBoxColorMap->addItem("Grayscale", 0);
    ui->comboBoxColorMap->addItem("Heatmap", 1);
    ui->comboBoxColorMap->addItem("Patriotic", 2);
    ui->comboBoxColorMap->addItem("VR", 3);

    // disable system power controls until it gets moved from main.cpp
    ui->checkBoxAppNap->setEnabled(false);
    ui->checkBoxIdleSleep->setEnabled(false);

    on_toolButtonRefresh_clicked();

    // setup auto-connect timer
    _auto_connect_timer = new QTimer(this);
    _auto_connect_timer->setInterval(3000);
    connect(_auto_connect_timer, &QTimer::timeout, this, &MainWindow::onAutoConnectTimer);

    // put all HID communication stuff in its own thread
    setupThread();

    // check for and load settings
    loadSettings();

    // connect click threshold slider to event handler
    connect(ui->horizontalSliderClickThreshold, &QSlider::valueChanged, [this](int value) {
        _event_handler->setClickThreshold(static_cast<double>(value));
    });
    _event_handler->setClickThreshold(ui->horizontalSliderClickThreshold->value());

    // the tray icon (color-inversion depends on settings)
    createTrayIcon(ui->checkBoxInvertIcon->isChecked());

    // start auto-connect timer if enabled and only nintendo is checked
    on_checkBoxOnlyNintendo_toggled(ui->checkBoxOnlyNintendo->isChecked());
    if(ui->checkBoxAutoConnectDevices->isChecked() && ui->checkBoxOnlyNintendo->isChecked()) {
        _auto_connect_timer->start();
    }

    this->thread()->setPriority(QThread::TimeCriticalPriority);
    _time_last_update = QDateTime::currentMSecsSinceEpoch();
}

MainWindow::~MainWindow()
{
    saveSettings();

    // Clean up worker in its own thread context, then stop thread
    if(_thread != nullptr && _thread->isRunning()) {
        // Stop timers and disconnect HID in worker's thread
        QMetaObject::invokeMethod(_worker, "cleanup", Qt::BlockingQueuedConnection);
        _thread->quit();
        _thread->wait();
    }
    delete _worker;
    delete _thread;
    delete _event_handler;
    delete ui;
}

/*!
 * \brief MainWindow::setupThread creates connections to a worker
 * object and moves it into its own thread
 */
void MainWindow::setupThread()
{
    _thread = new QThread(nullptr);
    _worker = new JoyConWorker();

    // setup a thread to handle streaming data from the joycon
    connect(_thread,SIGNAL(started()),
            _worker,SLOT(setup()));
    connect(this,SIGNAL(destroyed()),
            _thread,SLOT(quit()));

    connect(_worker,SIGNAL(finished()),
            _thread,SLOT(quit()));

    // signals/slots for connecting and disconnecting from JoyCons
    connect(this, SIGNAL(connectHID(unsigned short, unsigned short, const wchar_t*)),
            _worker, SLOT(onConnectHID(unsigned short, unsigned short, const wchar_t*)));
    connect(this, SIGNAL(disconnectHID()),
            _worker, SLOT(onDisconnectHID()));
    connect(_worker, SIGNAL(deviceConnectionChanged(QString, const unsigned short)),
            this, SLOT(onDeviceConnectionChanged(QString, const unsigned short)));
    connect(_worker, SIGNAL(deviceStatusMessage(QString)),
            this, SLOT(onJoyConStatusMessage(QString)));

    // signals/slots for data
    connect(this,SIGNAL(enableInputStreaming(bool)),
            _worker,SLOT(onInputStreamingEnabled(bool)));
    connect(_worker,SIGNAL(newInputData(QList<int>,QList<double>)),
            this,SLOT(onNewInputData(QList<int>,QList<double>)));
    connect(this,SIGNAL(updateIrConfig(ir_image_config)),
            _worker,SLOT(onIrConfigUpdated(ir_image_config)));
    connect(this,SIGNAL(captureImage(unsigned char)),
            _worker,SLOT(get_raw_ir_image(unsigned char)));
    connect(_worker,SIGNAL(newCameraImage(QImage)),
            this,SLOT(onCameraImageData(QImage)));

    connect(_worker, SIGNAL(newDeviceInfo(QList<unsigned char>, int)),
            this, SLOT(onDeviceInfoData(QList<unsigned char>, int)));
    connect(_worker, SIGNAL(newTemperatureData(float)),
            this, SLOT(onTemperatureData(float)));
    connect(_worker, SIGNAL(newBatteryData(int, int, int)),
            this, SLOT(onBatteryData(int, int, int)));

    connect(_worker, SIGNAL(silentDisconnectDetected()),
            this, SLOT(onSilentDisconnectDetected()));

    // move to thread and start
    _worker->moveToThread(_thread);
    _thread->start(QThread::NormalPriority);
}

/*!
 * \brief MainWindow::closeEvent intercepts the normal QMainWindow close signal
 * to keep the application alive in the system tray. The
 * MainWindow gets hidden instead of closing it.
 * \param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
#ifdef Q_OS_OSX
    if (!event->spontaneous() || !isVisible() || _force_close) {
        event->accept();
        hideAndClose();
        return;
    }
#endif
    if (_tray_icon->isVisible()) {
        if (ui->checkBoxWarnClose->isChecked()) {
            QCheckBox *check_box = new QCheckBox("Don't show this warning");
            QMessageBox message_box;
            message_box.setWindowTitle(tr("QJoyControl"));
            message_box.setText("QJoyControl will continue to run after"
                                " this window is closed. To exit the program,"
                                " select <b>Quit</b> from the menu bar");
            message_box.setIcon(QMessageBox::Icon::Information);
            message_box.addButton(QMessageBox::Ok);
            message_box.setCheckBox(check_box);

            QObject::connect(check_box, &QCheckBox::stateChanged, [this](int state){
                if (static_cast<Qt::CheckState>(state) == Qt::CheckState::Checked) {
                    ui->checkBoxWarnClose->setChecked(false);
                }
            });

            message_box.exec();
        }

        onHide();
        event->ignore();
    }
}

/*!
 * \brief MainWindow::hideAndClose is called when the user
 * selects quit from the tray icon menu
 */
void MainWindow::hideAndClose()
{
    _force_close = true;
    saveSettings();
    
    // Clean up worker in its own thread context, then stop thread
    if(_thread != nullptr && _thread->isRunning()) {
        // Stop timers and disconnect HID in worker's thread
        QMetaObject::invokeMethod(_worker, "cleanup", Qt::BlockingQueuedConnection);
        _thread->quit();
        _thread->wait();
    }
    delete _worker;
    _worker = nullptr;
    delete _thread;
    _thread = nullptr;
    QCoreApplication::quit();
}


/*!
 * \brief MainWindow::onShow is called by the tray menu
 */
void MainWindow::onShow()
{
    setVisible(true);
    _hide_action->setEnabled(true);
    _show_action->setEnabled(false);
    raise();
}

/*!
 * \brief MainWindow::onHide is called by the tray menu
 * or the MainWindow on a close event
 */
void MainWindow::onHide()
{
    setVisible(false);
    _hide_action->setEnabled(false);
    _show_action->setEnabled(true);
}

void MainWindow::showAbout()
{
    QString title(tr("About QJoyControl"));
    QString text(tr("QJoyControl version "));
    text += APP_VERSION;
    QString info_text(tr("Written 2019 by Erik Werner "));
    info_text += tr("using Qt and HIDAPI. ");
    info_text += tr("Based on work from: ");
    info_text += tr("<a href=\"https://github.com/CTCaer/jc_toolkit\">");
    info_text += tr("<span style=\" text-decoration: underline;\">Joy-Con Toolkit</span></a>");
    info_text += tr(" and <a href=\"https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering\">");
    info_text += tr("<span style=\" text-decoration: underline;\">Nintendo Switch Reverse Engineering</span></a>.");


    //QMessageBox::about(this, title, text);

    QMessageBox message_box;
    message_box.setWindowTitle(title);
    message_box.setText(text);
    message_box.setInformativeText(info_text);
    message_box.setIconPixmap(_tray_icon->icon().pixmap(64,64));
            message_box.addButton(QMessageBox::Ok);

    message_box.exec();
}
/*!
 * \brief MainWindow::createTrayIcon
 * \param is_inverted a flag loaded from the QSettings. If true, inverts the
 * icon so it looks better with the MacOS dark mode Ui
 */
void MainWindow::createTrayIcon(bool is_inverted)
{
    if(_tray_icon == nullptr) {
        _hide_action = new QAction(tr("&Hide QJoyControl"), this);
        connect(_hide_action, &QAction::triggered, this, &MainWindow::onHide);

        _show_action = new QAction(tr("&Show QJoyControl"), this);
        connect(_show_action, &QAction::triggered, this, &MainWindow::onShow);

        _about_action = new QAction(tr("&About"), this);
        connect(_about_action, &QAction::triggered, this, &MainWindow::showAbout);

        _quit_action = new QAction(tr("&Quit"), this);
        _quit_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
        connect(_quit_action, &QAction::triggered, this, &MainWindow::hideAndClose);



        _tray_icon_menu = new QMenu(this);
        _tray_icon_menu->addAction(_hide_action);
        _tray_icon_menu->addAction(_show_action);
        _tray_icon_menu->addSeparator();
        _tray_icon_menu->addAction(_about_action);
        _tray_icon_menu->addSeparator();
        _tray_icon_menu->addAction(_quit_action);

        _tray_icon = new QSystemTrayIcon(this);
        _tray_icon->setContextMenu(_tray_icon_menu);
        _tray_icon->setToolTip("QJoyControl");
    }
    QImage img(":/img/Logo.png");
    if(is_inverted) {
        img.invertPixels();
    }
    QIcon icon(QPixmap::fromImage(img));
    _tray_icon->setIcon(icon);
    _tray_icon->setVisible(true);
    setWindowIcon(icon);
}

/*!
 * \brief MainWindow::loadSettings
 */
void MainWindow::loadSettings(){
    QSettings settings;
    if(settings.contains("dark-mode")) {
        ui->checkBoxInvertIcon->setChecked(settings.value("dark-mode").toBool());
    }
    if(settings.contains("diagnostics")) {
        ui->checkBoxDiagnostics->setChecked(settings.value("diagnostics").toBool());
    }
    if(settings.contains("show-window-close-warning")) {
        ui->checkBoxWarnClose->setChecked(settings.value("show-window-close-warning").toBool());
    }

    if(settings.contains("prevent-appnap")) {
        ui->checkBoxAppNap->setChecked(settings.value("prevent-appnap").toBool());
    }
    if(settings.contains("prevent-sleep")) {
        ui->checkBoxIdleSleep->setChecked(settings.value("prevent-sleep").toBool());
    }
    if(settings.contains("analog-sensitivity")) {
        ui->horizontalSliderAnalogSensitivity->setValue(settings.value("analog-sensitivity").toInt());
    }
    if(settings.contains("gyro-sensitivity")) {
        ui->horizontalSliderGyroSensitivity->setValue(settings.value("gyro-sensitivity").toInt());
    }
    if(settings.contains("invert-mouse-y")) {
        ui->checkBoxInvertMouse->setChecked(settings.value("invert-mouse-y").toBool());
    }

    if(settings.contains("left-analog-mouse")) {
        ui->checkBoxLeftAnalogMouse->setChecked(settings.value("left-analog-mouse").toBool());
    }
    if(settings.contains("right-analog-mouse")) {
        ui->checkBoxRightAnalogMouse->setChecked(settings.value("right-analog-mouse").toBool());
    }
    if(settings.contains("left-click")) {
        ui->checkBoxLeftClick->setChecked(settings.value("left-click").toBool());
    }
    on_checkBoxLeftClick_toggled(ui->checkBoxLeftClick->isChecked());
    if(settings.contains("right-click")) {
        ui->checkBoxRightClick->setChecked(settings.value("right-click").toBool());
    }
    on_checkBoxRightClick_toggled(ui->checkBoxRightClick->isChecked());
    if(settings.contains("gyro-mouse")) {
        ui->checkBoxGyroMouse->setChecked(settings.value("gyro-mouse").toBool());
    }
    if(settings.contains("gyro-dead-zone")) {
        ui->doubleSpinBoxGyroDeadzone->setValue(settings.value("gyro-dead-zone").toDouble());
    }
    if(settings.contains("gyro-acceleration")) {
        int accel = settings.value("gyro-acceleration").toInt();
        ui->horizontalSliderGyroAccel->setValue(accel);
        ui->spinBoxGyroAccel->setValue(accel);
    }
    if(settings.contains("click-threshold")) {
        int threshold = settings.value("click-threshold").toInt();
        ui->horizontalSliderClickThreshold->setValue(threshold);
        ui->spinBoxClickThreshold->setValue(threshold);
    }
    if(settings.contains("require-zr-for-mouse")) {
        ui->checkBoxRequireZR->setChecked(settings.value("require-zr-for-mouse").toBool());
    }
    on_checkBoxRequireZR_toggled(ui->checkBoxRequireZR->isChecked());
    if(settings.contains("invert-zr-for-mouse")) {
        ui->checkBoxInvertZR->setChecked(settings.value("invert-zr-for-mouse").toBool());
    }
    if(settings.contains("invert-scroll")) {
        ui->checkBoxInvertScroll->setChecked(settings.value("invert-scroll").toBool());
    }
    if(settings.contains("last-connection")) {
        QString last_sn = settings.value("last-connection").toString();
        if(settings.contains("auto-connect")){
            bool auto_connect = settings.value("auto-connect").toBool();
            if(auto_connect) {
                for(int i = 0; i< ui->listWidgetDevices->count(); ++i) {
                    QListWidgetItem* item = ui->listWidgetDevices->item(i);
                    QString serial_string = item->data(Qt::UserRole + 3).toString();
                    if(serial_string == last_sn) {
                        unsigned short vendor_id = item->data(Qt::UserRole + 1).toUInt();
                        unsigned short product_id = item->data(Qt::UserRole + 2).toUInt();
                        wchar_t * serial_char = new wchar_t[serial_string.length() + 1];
                        serial_string.toWCharArray(serial_char);
                        serial_char[serial_string.length()] = 0; // ensure null terminated
                        emit connectHID(vendor_id, product_id, serial_char);
                        ui->statusBar->showMessage("Reconnecting to: " + serial_string, 5000);
                    }
                }
            }
            else {
                // auto connected disabled
            }
            ui->statusBar->showMessage("Pair and connect JoyCon to begin...", 5000);
        }
    }
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.setValue( "auto-connect", ui->checkBoxAutoConnect->isChecked());
    settings.setValue( "dark-mode", ui->checkBoxInvertIcon->isChecked() );
    settings.setValue( "diagnostics", ui->checkBoxDiagnostics->isChecked() );
    settings.setValue( "show-window-close-warning", ui->checkBoxWarnClose->isChecked() );

    settings.setValue( "prevent-appnap", ui->checkBoxAppNap->isChecked() );
    settings.setValue( "prevent-sleep", ui->checkBoxIdleSleep->isChecked() );

    settings.setValue("analog-sensitivity", ui->horizontalSliderAnalogSensitivity->value() );
    settings.setValue("gyro-sensitivity", ui->horizontalSliderGyroSensitivity->value() );
    settings.setValue( "invert-mouse-y", ui->checkBoxInvertMouse->isChecked() );

    settings.setValue("left-analog-mouse", ui->checkBoxLeftAnalogMouse->isChecked());
    settings.setValue("right-analog-mouse", ui->checkBoxRightAnalogMouse->isChecked());
    settings.setValue("left-click", ui->checkBoxLeftClick->isChecked());
    settings.setValue("right-click", ui->checkBoxRightClick->isChecked());
    settings.setValue("gyro-mouse", ui->checkBoxGyroMouse->isChecked());
    settings.setValue("gyro-dead-zone", ui->doubleSpinBoxGyroDeadzone->value());
    settings.setValue("gyro-acceleration", ui->horizontalSliderGyroAccel->value());
    settings.setValue("click-threshold", ui->horizontalSliderClickThreshold->value());
    settings.setValue("require-zr-for-mouse", ui->checkBoxRequireZR->isChecked());
    settings.setValue("invert-zr-for-mouse", ui->checkBoxInvertZR->isChecked());
    settings.setValue("invert-scroll", ui->checkBoxInvertScroll->isChecked());

    if(!_joycon_sn.isEmpty()) {
        settings.setValue("last-connection", _joycon_sn);
    }
    settings.sync();
}

void MainWindow::onDeviceConnectionChanged(QString sn, const unsigned short pid)
{
    _joycon_pid = pid;
    _joycon_sn = sn;
    if(!sn.isEmpty()) {
        emit enableInputStreaming(true);
        ui->toolButtonConnect->setEnabled(false);
        ui->toolButtonDisconnect->setEnabled(true);
        if(pid == JOYCON_R) {
            ui->tabCamera->setEnabled(true);
        }
        else {
            ui->tabCamera->setEnabled(false);
        }
    }
    else {
        ui->toolButtonConnect->setEnabled(true);
        ui->toolButtonDisconnect->setEnabled(false);
        if(ui->checkBoxAutoConnectDevices->isChecked() && ui->checkBoxOnlyNintendo->isChecked()) {
            _auto_connect_timer->start();
        }
    }
}

void MainWindow::onJoyConStatusMessage(QString message)
{
    ui->statusBar->showMessage(message, 5000);
}

void MainWindow::onDeviceInfoData(QList<unsigned char> device_info, int joycon_type)
{
    QString info_text("Connected to: ");

    if (joycon_type == JOYCON_L)
        info_text += "Joy-Con (L)";
    else if (joycon_type == JOYCON_R)
        info_text += "Joy-Con (R)";
    else if (joycon_type == PRO_CONTROLLER)
        info_text += "Pro Controller";
    else
        info_text += "Unknown Controller";

    info_text += "\nFirmware: ";
    float version = device_info[0] + device_info[1]/100.0;
    info_text += QString::number(version,'f',2);

    info_text += "\nMAC: ";
    for(int i = 4; i<10; ++i){
        // show the MAC address in hex
        info_text += QString::number(device_info[i], 16);
        if(i<9) {info_text += ":";}
    }
    ui->labelDeviceInfo->setText(info_text);
}

void MainWindow::onTemperatureData(float temp_c)
{
    QString text_string("\nTemp [C] :");
    text_string += QString::number(temp_c, 'f', 2);
    _status_widget->onTemperatureData(temp_c);
}

void MainWindow::onBatteryData(int volt, int percent, int status)
{
    qDebug()<<"battery info received";

    QString text_string("Battery: ");
    text_string += QString::number(percent, 'f', 2);
    text_string += "% ";
    text_string += "(";
    text_string += QString::number((volt * 2.5) / 1000, 'f', 2);
    text_string += "V)";

    _status_widget->onBatteryData(status, text_string);
}

/*!
 * \brief MainWindow::onNewInputData
 * \param button_data a list of 3 ints with button status
 * \param analog_data a list of 14 doubles containing: left stick (4), right stick (4), accel (3) and gyro (3) data
 */
void MainWindow::onNewInputData(QList<int> button_data, QList<double> analog_data)
{
    handleButtons(button_data);

    double dx = 0;
    double dy = 0;

    static int _update_count = 1;
    qint64 now = QDateTime::currentMSecsSinceEpoch();
    qint64 dt = now - _time_last_update;

    /// only update gui every 100 ms
    if(dt > 100) {
        QString b = "Buttons:";
        for(int i = 0; i<3; ++i) {
            b += QString::number(button_data.at(i));
            if(i<2) b += ',';
        }
        ui->labelButtons->setText(b);

        QString stringL("Left analog:\n  X(Raw): ");
        stringL += QString::number(analog_data[0]);
        stringL += "\n  Y(Raw): ";
        stringL += QString::number(analog_data[1]);
        stringL += "\n  X(Cal): ";
        stringL += QString::number(analog_data[2]);
        stringL += "\n  Y(Cal): ";
        stringL += QString::number(analog_data[3]);
        ui->labelAnalogL->setText(stringL);
        QString stringR("Right analog:\n  X(Raw): ");
        stringR += QString::number(analog_data[4]);
        stringR += "\n  Y(Raw): ";
        stringR += QString::number(analog_data[5]);
        stringR += "\n  X(Cal): ";
        stringR += QString::number(analog_data[6]);
        stringR += "\n  Y(Cal): ";
        stringR += QString::number(analog_data[7]);
        ui->labelAnalogR->setText(stringR);
        QString stringA("Accel [m/s\u00B2]\n  X:");
        stringA += QString::number(analog_data[8],'f',5);
        stringA += "\n  Y: ";
        stringA += QString::number(analog_data[9],'f',5);
        stringA += "\n  Z: ";
        stringA += QString::number(analog_data[10],'f',5);
        ui->labelAccel->setText(stringA);
        QString stringG("Gyro [rad/s]\n  X:");
        stringG += QString::number(analog_data[11],'f',5);
        stringG += "\n  Y: ";
        stringG += QString::number(analog_data[12],'f',5);
        stringG += "\n  Z: ";
        stringG += QString::number(analog_data[13],'f',5);
        ui->labelGyro->setText(stringG);

        ui->labelRate->setText("Rx dt: " + QString::number(dt/_update_count) + " ms");

        _time_last_update = now;
        _update_count = 1;
    }
    else {
        // do nothing
        _update_count++;
    }

    // handle scroll independently of ZR requirement
    bool scroll_active = false;
    if(ui->checkBoxRightAnalogMouse->isChecked()) {
        double scroll_dx = scaleAnalog(analog_data[6]);
        double scroll_dy = scaleAnalog(analog_data[7]);
        if(ui->checkBoxInvertScroll->isChecked()) {
            scroll_dy = -scroll_dy;
        }
        if(!qFuzzyIsNull(scroll_dx) || !qFuzzyIsNull(scroll_dy)) {
            scroll_active = true;
            _last_scroll_time = QDateTime::currentMSecsSinceEpoch();
            _event_handler->handleScroll(scroll_dx, scroll_dy);
        }
    }

    // enable mouse disable when key pressed + scrolling
    if(_any_key_pressed && scroll_active) {
        _mouse_disabled_for_scroll = true;
    }

    // disable mouse disable when all keys released OR no scroll for 1s
    if(_mouse_disabled_for_scroll) {
        qint64 now = QDateTime::currentMSecsSinceEpoch();
        if(!_any_key_pressed || (now - _last_scroll_time > 1000)) {
            _mouse_disabled_for_scroll = false;
        }
    }

    // pause mouse updates while disabled
    if(_mouse_disabled_for_scroll) {
        return;
    }

    // skip mouse tracking based on ZR state
    if(ui->checkBoxRequireZR->isChecked()) {
        bool invert = ui->checkBoxInvertZR->isChecked();
        // combine toggle state with hold state
        bool base_active = invert ? !_mouse_toggle_active : _mouse_toggle_active;
        // holding ZR temporarily inverts the current state
        bool active = _zr_held ? !base_active : base_active;
        if(!active) {
            return;
        }
    }

    if(ui->checkBoxLeftAnalogMouse->isChecked()) {
        dx += scaleAnalog(analog_data[2]);
        dy += scaleAnalog(analog_data[3]);
    }


    // for gyro gesture recognition: http://shukra.cedt.iisc.ernet.in/edwiki/Gesture_Recognition_and_Rendering_mouse_pointer_using_IMU_Sensor
    if(ui->checkBoxGyroMouse->isChecked()) {
        double base_sensitivity = ui->horizontalSliderGyroSensitivity->value();
        double dead_zone = ui->doubleSpinBoxGyroDeadzone->value();

        // acceleration: 0 = no acceleration (linear), 100 = max acceleration
        double accel_strength = ui->horizontalSliderGyroAccel->value() / 100.0;

        // acceleration function: slow movements are more precise, fast movements accelerate
        auto applyAcceleration = [base_sensitivity, accel_strength](double raw_value) -> double {
            double abs_val = std::abs(raw_value);
            if (accel_strength < 0.01) {
                // no acceleration, linear response
                return base_sensitivity * raw_value;
            }
            // normalize to roughly 0-1 range for typical gyro values
            double normalized = abs_val / 50.0;
            // acceleration curve: 0-70% scales 1x-0.2x min and 1x-5x max, 70-100% caps min at 0.2x and scales max 5x-20x
            double min_factor, max_factor;
            if (accel_strength <= 0.7) {
                min_factor = 1.0 - (0.8 / 0.7) * accel_strength;  // 1.0 down to 0.2 at 70%
                max_factor = 1.0 + (4.0 / 0.7) * accel_strength;  // 1.0 up to 5.0 at 70%
            } else {
                min_factor = 0.2 - ((accel_strength - 0.7) / 0.3) * 0.1;  // 0.2 down to 0.1 at 100%
                max_factor = 5.0 + ((accel_strength - 0.7) / 0.3) * 25.0;  // 5.0 up to 30.0 at 100%
            }
            // apply power curve so slow movements stay slow longer, but max speed unchanged
            double curved = std::pow(std::min(normalized, 1.0), 1.1);
            double accel_factor = min_factor + curved * (max_factor - min_factor);
            double effective_sensitivity = base_sensitivity * accel_factor;
            return (raw_value >= 0 ? 1.0 : -1.0) * effective_sensitivity * abs_val;
        };

        if(abs(analog_data[13]) > dead_zone) {
            double accel_value = applyAcceleration(analog_data[13]);
            if(_joycon_pid == JOYCON_R) {
                dx += accel_value;
            }
            else {
                dx -= accel_value;
            }
        }
        // mix tilt (roll) into lateral movement
        if(abs(analog_data[11]) > dead_zone) {
            double accel_value = applyAcceleration(analog_data[11]);
            if(_joycon_pid == JOYCON_R) {
                dx += accel_value;
            }
            else {
                dx -= accel_value;
            }
        }
        if(abs(analog_data[12]) > dead_zone) {
            double accel_value = applyAcceleration(analog_data[12]) * 2.0;
            if(_joycon_pid == JOYCON_R) {
                dy += accel_value;
            }
            else {
                dy -= accel_value;
            }
        }
    }

    if(qFuzzyIsNull(dx) && qFuzzyIsNull(dy)) {
        return;
    }
    else {
        // y axis is normally inverted
        if(!ui->checkBoxInvertMouse->isChecked()) {
            dy = -dy;
        }
        _event_handler->handleMouseMove(dx, dy);
    }
}

/*!
 * \brief MainWindow::sendCameraConfig
 */
void MainWindow::sendCameraConfig()
{

    // int ir_image_width;
    // int ir_image_height;
    // uint8_t ir_max_frag_no;

    QString error_msg;
    ir_image_config ir_new_config = {0};
    int res = 0;
    // The IR camera lens has a FoV of 123∞. The IR filter is a NIR 850nm wavelength pass filter.

    // Resolution config register and no of packets expected
    // The sensor supports a max of Binning [4 x 2] and max Skipping [4 x 4]
    // The maximum reduction in resolution is a combined Binning/Skipping [16 x 8]
    // The bits control the matrices used. Skipping [Bits0,1 x Bits2,3], Binning [Bits4,5 x Bit6]. Bit7 is unused.

    if (ui->radioButton240->isChecked()) {
        ir_new_config.width  = 320;
        ir_new_config.height = 240;
        ir_new_config.ir_res_reg = 0b00000000; // Full pixel array
        ir_new_config.max_fragment_no  = 0xff;
    }
    else if (ui->radioButton120->isChecked()) {
        ir_new_config.width  = 160;
        ir_new_config.height = 120;
        ir_new_config.ir_res_reg = 0b01010000; // Sensor Binning [2 X 2]
        ir_new_config.max_fragment_no  = 0x3f;
    }
    else if (ui->radioButton60->isChecked()) {
        ir_new_config.width  = 80;
        ir_new_config.height = 60;
        ir_new_config.ir_res_reg = 0b01100100; // Sensor Binning [4 x 2] and Skipping [1 x 2]
        ir_new_config.max_fragment_no  = 0x0f;
    }
    else if (ui->radioButton30->isChecked()) {
        ir_new_config.width  = 40;
        ir_new_config.height = 30;
        ir_new_config.ir_res_reg = 0b01101001; // Sensor Binning [4 x 2] and Skipping [2 x 4]
        ir_new_config.max_fragment_no  = 0x03;
    }
    else {
        qDebug()<<"error no camera config selected";
        //error//return 8;
    }


    /* ir_image_width  = 320;
    ir_image_height = 240;
    ir_new_config.ir_res_reg = 0b00000000; // Full pixel array
    ir_max_frag_no  = 0xff;*/


    // Enable IR Leds. Only the following configurations are supported.
    //if (this->chkBox_IRBrightLeds->Checked == true && this->chkBox_IRDimLeds->Checked == true)
    ir_new_config.ir_leds = 0b000000; // Both Far/Narrow 75∞ and Near/Wide 130∞ Led groups are enabled.
    //else if (this->chkBox_IRBrightLeds->Checked == true && this->chkBox_IRDimLeds->Checked == false)
    //   ir_new_config.ir_leds = 0b100000; // Only Far/Narrow 75∞ Led group is enabled.
    // else if (this->chkBox_IRBrightLeds->Checked == false && this->chkBox_IRDimLeds->Checked == true)
    //   ir_new_config.ir_leds = 0b010000; // Only Near/Wide 130∞ Led group is enabled.
    //else if (this->chkBox_IRBrightLeds->Checked == false && this->chkBox_IRDimLeds->Checked == false)
    //   ir_new_config.ir_leds = 0b110000; // Both groups disabled

    // IR Leds Intensity
    //ir_new_config.ir_leds_intensity = ((u8)this->trackBar_IRBrightLeds->Value << 8) | (u8)this->trackBar_IRDimLeds->Value;
    ir_new_config.ir_leds_intensity = 255;

    // IR Leds Effects
    //if (this->chkBox_IRFlashlight->Checked)
    //  ir_new_config.ir_leds |= 0b01;
    //if (this->chkBox_IRStrobe->Checked)
    //   ir_new_config.ir_leds |= 0b10000000;

    // External Light filter (Dark-frame subtraction). Additionally, disable if leds in flashlight mode.
    //if ((this->chkBox_IRExFilter->Checked || this->chkBox_IRStrobe->Checked) && this->chkBox_IRExFilter->Enabled)
    ir_new_config.ir_ex_light_filter = 0x03;
    // else
    //    ir_new_config.ir_ex_light_filter = 0x00;

    // Flip image. Food for tracking camera movement when taking selfies :P
    //if (this->chkBox_IRSelfie->Checked)
    //   ir_new_config.ir_flip = 0x02;
    // else
    ir_new_config.ir_flip = 0x00;

    // Exposure time (Shutter speed) is in us. Valid values are 0 to 600us or 0 - 1/1666.66s
    //ir_new_config.ir_exposure = (u16)(this->numeric_IRExposure->Value * 31200 / 1000);
    int exposure = ui->spinBoxExposure->value();
    ir_new_config.ir_exposure  =(uint16_t)(exposure* 31200 / 1000);
    //if (!this->chkBox_IRAutoExposure->Checked && enable_IRVideoPhoto) {
    //    enable_IRAutoExposure = false;
    //    ir_new_config.ir_digital_gain = (u8)this->trackBar_IRGain->Value;
    // }
    // else {
    //enable_IRAutoExposure = true;
    ir_new_config.ir_digital_gain = 1; // Disable digital gain for auto exposure
    // }


    //De-noise algorithms
    //if (this->chkBox_IRDenoise->Checked)
    //ir_new_config.ir_denoise = 0x01 << 16;
    //else
    ir_new_config.ir_denoise = 0x00 << 16;
    //ir_new_config.ir_denoise |= ((u8)this->numeric_IRDenoiseEdgeSmoothing->Value & 0xFF) << 8;
    //ir_new_config.ir_denoise |= (u8)this->numeric_IRDenoiseColorInterpolation->Value & 0xFF;

    emit updateIrConfig(ir_new_config);

}

/*!
 * \brief MainWindow::onCameraImageData receives and displays
 * an image on the camera preview label
 * \param img
 */
void MainWindow::onCameraImageData(QImage img)
{
    // don't update unless there is an image
    if(img.isNull() ) {
        return;
    }
    QLabel* l =  ui->labelCameraPreview;
    _current_image = img;
    _current_image.setColorTable(_color_table);
    _current_image.setColorCount(_color_table.length());
    l->setPixmap(QPixmap::fromImage(_current_image).scaled( l->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
}

void MainWindow::on_pushButtonCapture_clicked()
{
    //if (check_if_connected())
    //    return;
    qDebug()<<"begin ir capture";
    int res;
    //ui->pushButtonStream->setEnabled(false);
    //ui->pushButtonCapture->setEnabled(false);
    //enable_IRVideoPhoto = false;

    sendCameraConfig();
    //emit captureImage(0);
    //res = prepareSendIRConfig(true);

    if (res == 0) {
        //this->lbl_IRStatus->Text = "Status: Done! Saved to IRcamera.png";
    }

    //ui->pushButtonStream->setEnabled(true);
    //ui->pushButtonCapture->setEnabled(true);
}

void MainWindow::on_pushButtonStream_clicked()
{
    /*
    if (check_if_connected())
        return;

    int res;

    this->btn_getIRImage->Enabled = false;
    this->grpBox_IRRes->Enabled   = false;
    if (enable_IRVideoPhoto) {
        enable_IRVideoPhoto = false;
        this->btn_getIRStream->Enabled = false;
    }
    else {
        enable_IRVideoPhoto = true;
        this->btn_getIRStream->Text = L"Stop";
        this->btn_IRConfigLive->Enabled = true;
        res = prepareSendIRConfig(true);

        enable_IRVideoPhoto = false;
        if (res == 0)
            this->lbl_IRStatus->Text = L"Status: Standby";
        this->btn_getIRImage->Enabled  = true;
        this->grpBox_IRRes->Enabled    = true;
        this->btn_getIRStream->Enabled = true;
    }


    this->btn_IRConfigLive->Enabled = false;
    this->btn_getIRStream->Text = L"Stream";
    */
}

void MainWindow::on_checkBoxDiagnostics_toggled(bool checked)
{
    if(checked) {
        ui->tabWidget->addTab(ui->tabWidget->findChild<QWidget*>("tabDiagnostics"),"Diagnostics");
    }
    else {
        for(int i = 0; i < ui->tabWidget->count(); ++i) {
            if(ui->tabWidget->tabText(i) == "Diagnostics") {
                ui->tabWidget->removeTab(i);
            }
        }
    }
}

void MainWindow::on_checkBoxAppNap_toggled(bool checked)
{

}

void MainWindow::on_checkBoxIdleSleep_toggled(bool checked)
{

}


// raw (x,y) values in data[0] and data[1] (.. to ..)
// calibrated (x,y) values in data[2] and data[3] (-1 to 1)
double MainWindow::scaleAnalog(double input){

    double scaled = input;

    // exponential scaling
    double exp_scale = ui->horizontalSliderAnalogSensitivity->value();
    if( !qFuzzyIsNull(exp_scale) ) {
        scaled = exp(exp_scale * abs(input)) - 1;
        if( input< 0 ) {scaled = -scaled;}
    }
    // linear scaling
    /* double lin_scale = ui->doubleSpinBoxLinearScaling->value();
    if( !qFuzzyIsNull(lin_scale) ) {
        scaled = scaled * lin_scale;
    }*/
    return scaled;
}

void MainWindow::handleButtons(QList<int> buttons)
{
    // track ZR held state for mouse tracking
    bool zr_now = (buttons.at(0) & R_BUT_ZR) != 0;
    
    // detect ZR press/release for toggle
    if(ui->checkBoxRequireZR->isChecked()) {
        if(zr_now && !_zr_held) {
            // ZR just pressed - record time
            _zr_press_time = QDateTime::currentMSecsSinceEpoch();
            qDebug() << "ZR pressed at" << _zr_press_time;
        } else if(!zr_now && _zr_held) {
            // ZR just released - check if short press
            qint64 now = QDateTime::currentMSecsSinceEpoch();
            qint64 press_duration = now - _zr_press_time;
            qDebug() << "ZR released, press_duration=" << press_duration << "ms, last_tap=" << _zr_last_tap_time;
            if(press_duration <= ZR_SHORT_PRESS_MS) {
                // check for double-tap
                qint64 time_since_last_tap = now - _zr_last_tap_time;
                qDebug() << "Short press detected, time_since_last_tap=" << time_since_last_tap << "ms";
                if(_zr_last_tap_time > 0 && time_since_last_tap <= ZR_DOUBLE_TAP_MS) {
                    // double-tap detected - undo the toggle from first tap, fire the ZR key
                    qDebug() << "DOUBLE TAP - firing ZR key";
                    _mouse_toggle_active = !_mouse_toggle_active;
                    // temporarily enable ZR to fire the key (it's disabled for toggle mode)
                    _event_handler->enableButton(R_BUT_ZR, _zr_mapper->keyCode());
                    _event_handler->handleButtonPress(R_BUT_ZR);
                    _event_handler->handleButtonRelease(R_BUT_ZR);
                    _event_handler->disableButton(R_BUT_ZR);
                    _zr_last_tap_time = 0;
                } else {
                    // first tap - toggle mouse
                    qDebug() << "Single tap - toggling mouse to" << !_mouse_toggle_active;
                    _mouse_toggle_active = !_mouse_toggle_active;
                    _zr_last_tap_time = now;
                }
            } else {
                qDebug() << "Long press, ignoring for toggle";
            }
        }
    }
    _zr_held = zr_now;

    //face buttons on R joycon
    if(buttons.at(0) != _last_button_state[0]) {
        testButton(_last_button_state[0], buttons[0], R_BUT_Y);
        testButton(_last_button_state[0], buttons[0], R_BUT_X);
        testButton(_last_button_state[0], buttons[0], R_BUT_B);
        testButton(_last_button_state[0], buttons[0], R_BUT_A);
        testButton(_last_button_state[0], buttons[0], R_BUT_SR);
        testButton(_last_button_state[0], buttons[0], R_BUT_SL);
        testButton(_last_button_state[0], buttons[0], R_BUT_R);
        testButton(_last_button_state[0], buttons[0], R_BUT_ZR);
        _last_button_state[0] = buttons.at(0); // store the new button state reading
    }

    //shared button data (R and L)
    if(buttons.at(1) != _last_button_state[1]) {
        testButton(_last_button_state[1], buttons[1], L_BUT_MINUS | 256);
        testButton(_last_button_state[1], buttons[1], R_BUT_PLUS | 256);
        testButton(_last_button_state[1], buttons[1], R_BUT_STICK | 256);
        testButton(_last_button_state[1], buttons[1], L_BUT_STICK | 256);
        testButton(_last_button_state[1], buttons[1], R_BUT_HOME | 256);
        testButton(_last_button_state[1], buttons[1], L_BUT_CAP | 256);
        testButton(_last_button_state[1], buttons[1], CHARGE_GRIP | 256);
        _last_button_state[1] = buttons.at(1); // store the new button state reading
    }

    // L joycon buttun data
    if(buttons.at(2) != _last_button_state[2]) {
        testButton(_last_button_state[2], buttons[2], L_BUT_DOWN | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_UP | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_RIGHT | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_LEFT | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_SR | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_SL | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_L | 512);
        testButton(_last_button_state[2], buttons[2], L_BUT_ZL | 512);
        _last_button_state[2] = buttons.at(2); // store the new button state reading
    }

    // track if any key is currently pressed (any non-zero button state)
    _any_key_pressed = (buttons.at(0) != 0) || (buttons.at(1) != 0) || (buttons.at(2) != 0);
}

/*!
 * \brief MainWindow::testButton
 * \param last_button_state an integer containing the last read button state
 * \param button_state an integer containing the newly read button state
 * \param mask an integer with a 1-bit corresponding to the button
 */
void MainWindow::testButton(int last_button_state, int button_state, int mask)
{
    // button is currently pressed
    if(button_state & mask) {
        _event_handler->handleButtonPress(mask);
    }
    else if (last_button_state & mask) {
        _event_handler->handleButtonRelease(mask);
    }

    /*
    // button is currently pressed
    if(button_state & mask) {
        // button was not previously pressed
        if( (last_button_state & mask) != (button_state & mask) ){
            _event_handler->handleButtonPress(mask);
        }
        else {
            // button was already pressed, do nothing
        }
    }
    //button was previously pressed
    if(last_button_state & mask) {
        if(button_state & mask) {
            // button is still pressed, do nothing
            //_event_handler->handleButtonPress(mask);
            //qDebug()<<"hold";
        }
        else {
            _event_handler->handleButtonRelease(mask);
        }
    }*/
}

void MainWindow::on_toolButtonRefresh_clicked()
{
    ui->listWidgetDevices->clear();

    // linked list to hold enumerated HID devices
    struct hid_device_info *devs;

    // returns a pointer to a linked list of type hid_device_info
    // or NULL in the case of failure
    // Note: hid_init/hid_exit are handled by the worker thread
    devs = ui->checkBoxOnlyNintendo->isChecked() ?
                hid_enumerate(NINTENDO, 0x0) : hid_enumerate(0x0, 0x0);

    while (devs) {
        addHidItem(devs);
        devs = devs->next;
    }

    // automatically select the first item in the list
    if(ui->listWidgetDevices->count() > 0){
        ui->listWidgetDevices->setCurrentRow(0);
    }

    // free the linked list made by enumerate
    hid_free_enumeration(devs);
}

/*!
 * \brief MainWindow::addHidItem
 * \param info
 */
void MainWindow::addHidItem(struct hid_device_info* info) {

    QString label;
    label += QString::fromWCharArray(info->product_string);
    QString helpText;
    helpText += "Manufacturer: " + QString::fromWCharArray(info->manufacturer_string);
    helpText += "\nProduct: " + QString::fromWCharArray(info->product_string);
    helpText += "\nRelease: "+  QString::number(info->release_number);
    helpText += "\nInterface: "+  QString::number(info->interface_number);
    helpText += "\nPath: " + QString(info->path);
    helpText += "\nSN: " + QString(QString::fromWCharArray(info->serial_number));
    QListWidgetItem* item = new QListWidgetItem(label);
    item->setToolTip(helpText);

    item->setData(Qt::UserRole + 1, info->vendor_id);
    item->setData(Qt::UserRole + 2, info->product_id);
    item->setData(Qt::UserRole + 3, QString::fromWCharArray(info->serial_number));
    item->setData(Qt::UserRole + 4, QString(info->path));
    item->setData(Qt::UserRole + 5, QString::fromWCharArray(info->product_string));
    ui->listWidgetDevices->addItem(item);

    qDebug()<<"Added Product"<< QString::fromWCharArray(info->product_string)
           << " SN:" << QString::fromWCharArray(info->serial_number)
           << " PID:" << QString::number(info->product_id)
           << "Path: "<< info->path;
}


void MainWindow::on_toolButtonConnect_clicked()
{
    if( QListWidgetItem* item = ui->listWidgetDevices->currentItem() ) {
        unsigned short vendor_id = item->data(Qt::UserRole + 1).toUInt();
        unsigned short product_id = item->data(Qt::UserRole + 2).toUInt();
        QString serial_string = item->data(Qt::UserRole + 3).toString();
        wchar_t * serial_char = new wchar_t[serial_string.length() + 1];
        serial_string.toWCharArray(serial_char);
        serial_char[serial_string.length()] = 0; // ensure null terminated

        // hidapi always uses the path to open the device
        // the paths are the same for all joycons on a hub,
        // so you can only ahve one joycon paired at a time
        emit connectHID(vendor_id, product_id, serial_char);
    }
}

void MainWindow::on_toolButtonDisconnect_clicked()
{
    emit disconnectHID();
}

void MainWindow::on_checkBoxInvertIcon_toggled(bool checked)
{
    createTrayIcon(checked);
}

/*!
 * \brief MainWindow::on_pushButtonSaveImage_clicked prompts the user
 * to save the image captured by the ir camera. The image will be saved
 * at its native resolution and the selected directory
 * will be stored in QSettings
 */
void MainWindow::on_pushButtonSaveImage_clicked()
{
    QSettings settings;
    QString save_dir = settings.value("save-dir").toString();
    if(save_dir.isEmpty()) {
        save_dir = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    }
    QString file_name = QFileDialog::getSaveFileName(
                this, tr("Save Image"), save_dir, tr("Images (*.png *.jpg)"));

    if( !file_name.isEmpty() ) {
        if(!_current_image.isNull()) {
            _current_image.save(file_name);
        }
        settings.setValue("save-dir", QDir(file_name).dirName());
    }
}

/*!
 * \brief MainWindow::on_comboBoxColorMap_currentIndexChanged
 * updates _color_table when the user changes their selection
 * \param index
 */
void MainWindow::on_comboBoxColorMap_currentIndexChanged(int index)
{
    int value = ui->comboBoxColorMap->itemData(index,Qt::UserRole).toInt();
    _color_table.clear();
    switch(value) {
    case 0: // grayscale
    {
        for(int i = 0; i<256; ++i) {
            _color_table.append(qRgb(i, i, i));
        }
        break;
    }
    case 1: // heat map
    {
        for(int i = 0; i <64; ++i) { // from blue to cyan
            int j = i*4;
            _color_table.append(qRgb(0, j, 255-j));
        }
        for(int i = 0; i <64; ++i) { // from cyan to green
            int j = i*4;
            _color_table.append(qRgb(0, 255, 255-j));
        }
        for(int i = 0; i <64; ++i) { // from green to yellow
            int j = i*4;
            _color_table.append(qRgb(j, 255, 255-j));
        }
        for(int i = 0; i <64; ++i) { // from yellow to red
            int j = i*4;
            _color_table.append(qRgb(255, 255-j, 0));
        }
        break;
    }
    case 2: // patriotic
    {
        for(int i = 0; i<128; ++i) { // red to white...ish
            int j = i*2;
            _color_table.append(qRgb(255, j, j));
        }
        for(int i = 128; i<256; ++i) { // white to blue
            int j = i*2;
            _color_table.append(qRgb(255-j, 255-j, j));
        }
        break;
    }
    case 3: // vr
    {
        for(int i = 0; i<256; ++i) {
            _color_table.append(qRgba(255-i, 0,0, 255-i));
        }
        break;
    }
    }
    // if there is an image, update
    if(!_current_image.isNull()) {
        onCameraImageData(_current_image);
    }
}

/*!
 * \brief MainWindow::resizeEvent overrides the default QMainWindow resize event
 * to scale the ir camera image
 * \param event
 */
void MainWindow::resizeEvent(QResizeEvent *event)
{
    onCameraImageData(_current_image);
    QMainWindow::resizeEvent(event);
}

// if checked, map Y to left mouse click
void MainWindow::on_checkBoxLeftClick_toggled(bool checked)
{
    if(checked) {
        _y_mapper->setClickMap(2);
    }
    else {
        _y_mapper->setClickMap(0);
    }
}

// if checked, map X to right mouse click
void MainWindow::on_checkBoxRightClick_toggled(bool checked)
{
    if(checked) {
        _x_mapper->setClickMap(1);
    }
    else {
        _x_mapper->setClickMap(0);
    }
}

// if checked, ZR is used for mouse activation toggle - show double tap mode
void MainWindow::on_checkBoxRequireZR_toggled(bool checked)
{
    if(checked) {
        _zr_mapper->setDoubleTapMode(true);
        _event_handler->disableButton(R_BUT_ZR);
        ui->checkBoxInvertZR->setEnabled(true);
    }
    else {
        _zr_mapper->setDoubleTapMode(false);
        _event_handler->enableButton(R_BUT_ZR, Qt::Key_S);
        ui->checkBoxInvertZR->setEnabled(false);
        ui->checkBoxInvertZR->setChecked(false);
    }
}

void MainWindow::on_checkBoxInvertZR_toggled(bool checked)
{
    Q_UNUSED(checked);
}

void MainWindow::on_checkBoxOnlyNintendo_toggled(bool checked)
{
    ui->checkBoxAutoConnectDevices->setEnabled(checked);
    if(!checked) {
        ui->checkBoxAutoConnectDevices->setChecked(false);
        _auto_connect_timer->stop();
    }
    on_toolButtonRefresh_clicked();
}

void MainWindow::on_checkBoxAutoConnectDevices_toggled(bool checked)
{
    if(checked && ui->checkBoxOnlyNintendo->isChecked()) {
        _auto_connect_timer->start();
        onAutoConnectTimer();
    } else {
        _auto_connect_timer->stop();
    }
}

void MainWindow::onAutoConnectTimer()
{
    if(_joycon_sn.isEmpty() && ui->listWidgetDevices->count() == 0) {
        on_toolButtonRefresh_clicked();
    }

    if(_joycon_sn.isEmpty() && ui->listWidgetDevices->count() > 0) {
        for(int i = 0; i < ui->listWidgetDevices->count(); ++i) {
            QListWidgetItem* item = ui->listWidgetDevices->item(i);
            unsigned short vendor_id = item->data(Qt::UserRole + 1).toUInt();
            if(vendor_id == NINTENDO) {
                ui->listWidgetDevices->setCurrentRow(i);
                on_toolButtonConnect_clicked();
                break;
            }
        }
    }

    if(!_joycon_sn.isEmpty()) {
        _auto_connect_timer->stop();
    }
}

void MainWindow::onSilentDisconnectDetected()
{
    qDebug() << "Silent disconnect detected, triggering reconnection...";
    emit disconnectHID();
    
    if(ui->checkBoxAutoConnectDevices->isChecked()) {
        _auto_connect_timer->start();
    }
}
