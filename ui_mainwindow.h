/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "inputmappanel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShow;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabConnect;
    QGridLayout *gridLayout_2;
    QToolButton *toolButtonConnect;
    QListWidget *listWidgetDevices;
    QToolButton *toolButtonDisconnect;
    QToolButton *toolButtonRefresh;
    QLabel *labelDeviceInfo;
    QCheckBox *checkBoxOnlyNintendo;
    QWidget *tabSettings;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBoxMouseSettings;
    QGridLayout *gridLayout_7;
    QCheckBox *checkBoxInvertMouse;
    QSpacerItem *verticalSpacer_2;
    QSlider *horizontalSliderGyroSensitivity;
    QLabel *label_2;
    QSlider *horizontalSliderAnalogSensitivity;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *doubleSpinBoxGyroDeadzone;
    QLabel *label_4;
    QLabel *label_gyro_accel;
    QSlider *horizontalSliderGyroAccel;
    QSpinBox *spinBoxGyroAccel;
    QGroupBox *groupBoxApplicationSettings;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBoxDiagnostics;
    QCheckBox *checkBoxAppNap;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxIdleSleep;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBoxInvertIcon;
    QCheckBox *checkBoxWarnClose;
    QCheckBox *checkBoxAutoConnect;
    QGroupBox *groupBoxJoyConSettings;
    QGridLayout *gridLayout_9;
    QLabel *label;
    QSpinBox *spinBoxPlayerLED;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *tabControls;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBoxLeftClick;
    QCheckBox *checkBoxGyroMouse;
    QCheckBox *checkBoxRequireZR;
    QCheckBox *checkBoxRightAnalogMouse;
    QCheckBox *checkBoxRightClick;
    QCheckBox *checkBoxLeftAnalogMouse;
    InputMapPanel *inputMapL;
    InputMapPanel *inputMapR;
    QWidget *tabCamera;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxExposure;
    QGridLayout *gridLayout_10;
    QSpinBox *spinBoxExposure;
    QGroupBox *groupBoxResolution;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton240;
    QRadioButton *radioButton120;
    QRadioButton *radioButton60;
    QRadioButton *radioButton30;
    QPushButton *pushButtonStream;
    QPushButton *pushButtonCapture;
    QPushButton *pushButtonSaveImage;
    QLabel *labelCameraPreview;
    QComboBox *comboBoxColorMap;
    QWidget *tabDiagnostics;
    QGridLayout *gridLayout_4;
    QLabel *labelRate;
    QLabel *labelButtons;
    QLabel *labelAccel;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelGyro;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelAnalogL;
    QLabel *labelAnalogR;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuExit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(512, 573);
        actionShow = new QAction(MainWindow);
        actionShow->setObjectName("actionShow");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabConnect = new QWidget();
        tabConnect->setObjectName("tabConnect");
        tabConnect->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(tabConnect);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        toolButtonConnect = new QToolButton(tabConnect);
        toolButtonConnect->setObjectName("toolButtonConnect");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonConnect->sizePolicy().hasHeightForWidth());
        toolButtonConnect->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(toolButtonConnect, 3, 1, 1, 1);

        listWidgetDevices = new QListWidget(tabConnect);
        listWidgetDevices->setObjectName("listWidgetDevices");

        gridLayout_2->addWidget(listWidgetDevices, 0, 0, 5, 1);

        toolButtonDisconnect = new QToolButton(tabConnect);
        toolButtonDisconnect->setObjectName("toolButtonDisconnect");
        sizePolicy.setHeightForWidth(toolButtonDisconnect->sizePolicy().hasHeightForWidth());
        toolButtonDisconnect->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(toolButtonDisconnect, 4, 1, 1, 1);

        toolButtonRefresh = new QToolButton(tabConnect);
        toolButtonRefresh->setObjectName("toolButtonRefresh");
        sizePolicy.setHeightForWidth(toolButtonRefresh->sizePolicy().hasHeightForWidth());
        toolButtonRefresh->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(toolButtonRefresh, 0, 1, 1, 1);

        labelDeviceInfo = new QLabel(tabConnect);
        labelDeviceInfo->setObjectName("labelDeviceInfo");
        QFont font;
        font.setPointSize(10);
        labelDeviceInfo->setFont(font);
        labelDeviceInfo->setWordWrap(true);

        gridLayout_2->addWidget(labelDeviceInfo, 2, 1, 1, 1);

        checkBoxOnlyNintendo = new QCheckBox(tabConnect);
        checkBoxOnlyNintendo->setObjectName("checkBoxOnlyNintendo");
        checkBoxOnlyNintendo->setFont(font);
        checkBoxOnlyNintendo->setChecked(true);

        gridLayout_2->addWidget(checkBoxOnlyNintendo, 1, 1, 1, 1);

        tabWidget->addTab(tabConnect, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName("tabSettings");
        gridLayout_5 = new QGridLayout(tabSettings);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName("gridLayout_5");
        groupBoxMouseSettings = new QGroupBox(tabSettings);
        groupBoxMouseSettings->setObjectName("groupBoxMouseSettings");
        gridLayout_7 = new QGridLayout(groupBoxMouseSettings);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName("gridLayout_7");
        checkBoxInvertMouse = new QCheckBox(groupBoxMouseSettings);
        checkBoxInvertMouse->setObjectName("checkBoxInvertMouse");
        checkBoxInvertMouse->setLayoutDirection(Qt::LeftToRight);
        checkBoxInvertMouse->setTristate(false);

        gridLayout_7->addWidget(checkBoxInvertMouse, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 5, 1, 1, 1);

        horizontalSliderGyroSensitivity = new QSlider(groupBoxMouseSettings);
        horizontalSliderGyroSensitivity->setObjectName("horizontalSliderGyroSensitivity");
        horizontalSliderGyroSensitivity->setMinimum(1);
        horizontalSliderGyroSensitivity->setMaximum(30);
        horizontalSliderGyroSensitivity->setValue(8);
        horizontalSliderGyroSensitivity->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(horizontalSliderGyroSensitivity, 1, 1, 1, 1);

        label_2 = new QLabel(groupBoxMouseSettings);
        label_2->setObjectName("label_2");

        gridLayout_7->addWidget(label_2, 0, 0, 1, 1);

        horizontalSliderAnalogSensitivity = new QSlider(groupBoxMouseSettings);
        horizontalSliderAnalogSensitivity->setObjectName("horizontalSliderAnalogSensitivity");
        horizontalSliderAnalogSensitivity->setMinimum(1);
        horizontalSliderAnalogSensitivity->setMaximum(10);
        horizontalSliderAnalogSensitivity->setValue(4);
        horizontalSliderAnalogSensitivity->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(horizontalSliderAnalogSensitivity, 0, 1, 1, 1);

        spinBox = new QSpinBox(groupBoxMouseSettings);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximum(10);
        spinBox->setValue(4);

        gridLayout_7->addWidget(spinBox, 0, 2, 1, 1);

        label_3 = new QLabel(groupBoxMouseSettings);
        label_3->setObjectName("label_3");

        gridLayout_7->addWidget(label_3, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(groupBoxMouseSettings);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMaximum(30);
        spinBox_2->setValue(8);

        gridLayout_7->addWidget(spinBox_2, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        doubleSpinBoxGyroDeadzone = new QDoubleSpinBox(groupBoxMouseSettings);
        doubleSpinBoxGyroDeadzone->setObjectName("doubleSpinBoxGyroDeadzone");
        doubleSpinBoxGyroDeadzone->setMaximum(10.000000000000000);
        doubleSpinBoxGyroDeadzone->setSingleStep(0.010000000000000);
        doubleSpinBoxGyroDeadzone->setValue(0.030000000000000);

        gridLayout_7->addWidget(doubleSpinBoxGyroDeadzone, 2, 1, 1, 1);

        label_4 = new QLabel(groupBoxMouseSettings);
        label_4->setObjectName("label_4");

        gridLayout_7->addWidget(label_4, 2, 0, 1, 1);

        label_gyro_accel = new QLabel(groupBoxMouseSettings);
        label_gyro_accel->setObjectName("label_gyro_accel");

        gridLayout_7->addWidget(label_gyro_accel, 4, 0, 1, 1);

        horizontalSliderGyroAccel = new QSlider(groupBoxMouseSettings);
        horizontalSliderGyroAccel->setObjectName("horizontalSliderGyroAccel");
        horizontalSliderGyroAccel->setMinimum(0);
        horizontalSliderGyroAccel->setMaximum(100);
        horizontalSliderGyroAccel->setValue(50);
        horizontalSliderGyroAccel->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(horizontalSliderGyroAccel, 4, 1, 1, 1);

        spinBoxGyroAccel = new QSpinBox(groupBoxMouseSettings);
        spinBoxGyroAccel->setObjectName("spinBoxGyroAccel");
        spinBoxGyroAccel->setMaximum(100);
        spinBoxGyroAccel->setValue(50);

        gridLayout_7->addWidget(spinBoxGyroAccel, 4, 2, 1, 1);


        gridLayout_5->addWidget(groupBoxMouseSettings, 2, 0, 1, 2);

        groupBoxApplicationSettings = new QGroupBox(tabSettings);
        groupBoxApplicationSettings->setObjectName("groupBoxApplicationSettings");
        gridLayout_6 = new QGridLayout(groupBoxApplicationSettings);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName("gridLayout_6");
        checkBoxDiagnostics = new QCheckBox(groupBoxApplicationSettings);
        checkBoxDiagnostics->setObjectName("checkBoxDiagnostics");
        checkBoxDiagnostics->setChecked(true);

        gridLayout_6->addWidget(checkBoxDiagnostics, 2, 0, 1, 1);

        checkBoxAppNap = new QCheckBox(groupBoxApplicationSettings);
        checkBoxAppNap->setObjectName("checkBoxAppNap");
        checkBoxAppNap->setChecked(true);

        gridLayout_6->addWidget(checkBoxAppNap, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 1, 1, 1);

        checkBoxIdleSleep = new QCheckBox(groupBoxApplicationSettings);
        checkBoxIdleSleep->setObjectName("checkBoxIdleSleep");

        gridLayout_6->addWidget(checkBoxIdleSleep, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 6, 0, 1, 1);

        checkBoxInvertIcon = new QCheckBox(groupBoxApplicationSettings);
        checkBoxInvertIcon->setObjectName("checkBoxInvertIcon");
        checkBoxInvertIcon->setChecked(true);

        gridLayout_6->addWidget(checkBoxInvertIcon, 1, 0, 1, 1);

        checkBoxWarnClose = new QCheckBox(groupBoxApplicationSettings);
        checkBoxWarnClose->setObjectName("checkBoxWarnClose");
        checkBoxWarnClose->setChecked(true);

        gridLayout_6->addWidget(checkBoxWarnClose, 3, 0, 1, 1);

        checkBoxAutoConnect = new QCheckBox(groupBoxApplicationSettings);
        checkBoxAutoConnect->setObjectName("checkBoxAutoConnect");
        checkBoxAutoConnect->setChecked(true);

        gridLayout_6->addWidget(checkBoxAutoConnect, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxApplicationSettings, 1, 0, 1, 1);

        groupBoxJoyConSettings = new QGroupBox(tabSettings);
        groupBoxJoyConSettings->setObjectName("groupBoxJoyConSettings");
        gridLayout_9 = new QGridLayout(groupBoxJoyConSettings);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName("gridLayout_9");
        label = new QLabel(groupBoxJoyConSettings);
        label->setObjectName("label");

        gridLayout_9->addWidget(label, 0, 0, 1, 1);

        spinBoxPlayerLED = new QSpinBox(groupBoxJoyConSettings);
        spinBoxPlayerLED->setObjectName("spinBoxPlayerLED");
        spinBoxPlayerLED->setMaximum(255);
        spinBoxPlayerLED->setValue(144);
        spinBoxPlayerLED->setDisplayIntegerBase(2);

        gridLayout_9->addWidget(spinBoxPlayerLED, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_9->addItem(verticalSpacer_4, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxJoyConSettings, 3, 0, 1, 1);

        tabWidget->addTab(tabSettings, QString());
        tabControls = new QWidget();
        tabControls->setObjectName("tabControls");
        gridLayout_8 = new QGridLayout(tabControls);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName("gridLayout_8");
        checkBoxLeftClick = new QCheckBox(tabControls);
        checkBoxLeftClick->setObjectName("checkBoxLeftClick");
        checkBoxLeftClick->setChecked(true);

        gridLayout_8->addWidget(checkBoxLeftClick, 2, 0, 1, 1);

        checkBoxGyroMouse = new QCheckBox(tabControls);
        checkBoxGyroMouse->setObjectName("checkBoxGyroMouse");
        checkBoxGyroMouse->setChecked(true);

        gridLayout_8->addWidget(checkBoxGyroMouse, 3, 1, 1, 1);

        checkBoxRequireZR = new QCheckBox(tabControls);
        checkBoxRequireZR->setObjectName("checkBoxRequireZR");
        checkBoxRequireZR->setChecked(false);

        gridLayout_8->addWidget(checkBoxRequireZR, 4, 0, 1, 2);

        checkBoxRightAnalogMouse = new QCheckBox(tabControls);
        checkBoxRightAnalogMouse->setObjectName("checkBoxRightAnalogMouse");
        checkBoxRightAnalogMouse->setChecked(true);

        gridLayout_8->addWidget(checkBoxRightAnalogMouse, 1, 1, 1, 1);

        checkBoxRightClick = new QCheckBox(tabControls);
        checkBoxRightClick->setObjectName("checkBoxRightClick");
        checkBoxRightClick->setChecked(true);

        gridLayout_8->addWidget(checkBoxRightClick, 2, 1, 1, 1);

        checkBoxLeftAnalogMouse = new QCheckBox(tabControls);
        checkBoxLeftAnalogMouse->setObjectName("checkBoxLeftAnalogMouse");
        checkBoxLeftAnalogMouse->setChecked(true);

        gridLayout_8->addWidget(checkBoxLeftAnalogMouse, 1, 0, 1, 1);

        inputMapL = new InputMapPanel(tabControls);
        inputMapL->setObjectName("inputMapL");
        inputMapL->setFont(font);

        gridLayout_8->addWidget(inputMapL, 0, 0, 1, 1);

        inputMapR = new InputMapPanel(tabControls);
        inputMapR->setObjectName("inputMapR");

        gridLayout_8->addWidget(inputMapR, 0, 1, 1, 1);

        tabWidget->addTab(tabControls, QString());
        checkBoxLeftClick->raise();
        checkBoxGyroMouse->raise();
        checkBoxLeftAnalogMouse->raise();
        checkBoxRightAnalogMouse->raise();
        checkBoxRightClick->raise();
        inputMapL->raise();
        inputMapR->raise();
        tabCamera = new QWidget();
        tabCamera->setObjectName("tabCamera");
        gridLayout_3 = new QGridLayout(tabCamera);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBoxExposure = new QGroupBox(tabCamera);
        groupBoxExposure->setObjectName("groupBoxExposure");
        gridLayout_10 = new QGridLayout(groupBoxExposure);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName("gridLayout_10");
        spinBoxExposure = new QSpinBox(groupBoxExposure);
        spinBoxExposure->setObjectName("spinBoxExposure");
        spinBoxExposure->setMaximum(600);
        spinBoxExposure->setValue(600);

        gridLayout_10->addWidget(spinBoxExposure, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxExposure, 3, 0, 1, 1);

        groupBoxResolution = new QGroupBox(tabCamera);
        groupBoxResolution->setObjectName("groupBoxResolution");
        verticalLayout = new QVBoxLayout(groupBoxResolution);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        radioButton240 = new QRadioButton(groupBoxResolution);
        radioButton240->setObjectName("radioButton240");
        radioButton240->setChecked(false);

        verticalLayout->addWidget(radioButton240);

        radioButton120 = new QRadioButton(groupBoxResolution);
        radioButton120->setObjectName("radioButton120");
        radioButton120->setChecked(true);

        verticalLayout->addWidget(radioButton120);

        radioButton60 = new QRadioButton(groupBoxResolution);
        radioButton60->setObjectName("radioButton60");
        radioButton60->setChecked(false);

        verticalLayout->addWidget(radioButton60);

        radioButton30 = new QRadioButton(groupBoxResolution);
        radioButton30->setObjectName("radioButton30");

        verticalLayout->addWidget(radioButton30);


        gridLayout_3->addWidget(groupBoxResolution, 2, 0, 1, 1);

        pushButtonStream = new QPushButton(tabCamera);
        pushButtonStream->setObjectName("pushButtonStream");
        pushButtonStream->setEnabled(false);

        gridLayout_3->addWidget(pushButtonStream, 1, 0, 1, 1);

        pushButtonCapture = new QPushButton(tabCamera);
        pushButtonCapture->setObjectName("pushButtonCapture");

        gridLayout_3->addWidget(pushButtonCapture, 0, 0, 1, 1);

        pushButtonSaveImage = new QPushButton(tabCamera);
        pushButtonSaveImage->setObjectName("pushButtonSaveImage");

        gridLayout_3->addWidget(pushButtonSaveImage, 4, 1, 1, 1);

        labelCameraPreview = new QLabel(tabCamera);
        labelCameraPreview->setObjectName("labelCameraPreview");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCameraPreview->sizePolicy().hasHeightForWidth());
        labelCameraPreview->setSizePolicy(sizePolicy1);
        labelCameraPreview->setScaledContents(false);

        gridLayout_3->addWidget(labelCameraPreview, 0, 1, 4, 1);

        comboBoxColorMap = new QComboBox(tabCamera);
        comboBoxColorMap->setObjectName("comboBoxColorMap");

        gridLayout_3->addWidget(comboBoxColorMap, 4, 0, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 10);
        tabWidget->addTab(tabCamera, QString());
        tabDiagnostics = new QWidget();
        tabDiagnostics->setObjectName("tabDiagnostics");
        gridLayout_4 = new QGridLayout(tabDiagnostics);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        labelRate = new QLabel(tabDiagnostics);
        labelRate->setObjectName("labelRate");

        gridLayout_4->addWidget(labelRate, 5, 0, 1, 1);

        labelButtons = new QLabel(tabDiagnostics);
        labelButtons->setObjectName("labelButtons");

        gridLayout_4->addWidget(labelButtons, 0, 0, 1, 1);

        labelAccel = new QLabel(tabDiagnostics);
        labelAccel->setObjectName("labelAccel");

        gridLayout_4->addWidget(labelAccel, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 6, 0, 1, 1);

        labelGyro = new QLabel(tabDiagnostics);
        labelGyro->setObjectName("labelGyro");

        gridLayout_4->addWidget(labelGyro, 4, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        labelAnalogL = new QLabel(tabDiagnostics);
        labelAnalogL->setObjectName("labelAnalogL");

        gridLayout_4->addWidget(labelAnalogL, 1, 0, 1, 1);

        labelAnalogR = new QLabel(tabDiagnostics);
        labelAnalogR->setObjectName("labelAnalogR");

        gridLayout_4->addWidget(labelAnalogR, 2, 0, 1, 1);

        tabWidget->addTab(tabDiagnostics, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 512, 22));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName("menuExit");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuExit->menuAction());
        menuExit->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderAnalogSensitivity, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
        QObject::connect(horizontalSliderGyroSensitivity, &QSlider::valueChanged, spinBox_2, &QSpinBox::setValue);
        QObject::connect(spinBox, &QSpinBox::valueChanged, horizontalSliderAnalogSensitivity, &QSlider::setValue);
        QObject::connect(spinBox_2, &QSpinBox::valueChanged, horizontalSliderGyroSensitivity, &QSlider::setValue);
        QObject::connect(actionQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(horizontalSliderGyroAccel, &QSlider::valueChanged, spinBoxGyroAccel, &QSpinBox::setValue);
        QObject::connect(spinBoxGyroAccel, &QSpinBox::valueChanged, horizontalSliderGyroAccel, &QSlider::setValue);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QJoyControl", nullptr));
        actionShow->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        toolButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        toolButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        toolButtonRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        labelDeviceInfo->setText(QCoreApplication::translate("MainWindow", "No device connected", nullptr));
        checkBoxOnlyNintendo->setText(QCoreApplication::translate("MainWindow", "Only show Nintendo devices", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConnect), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBoxMouseSettings->setTitle(QCoreApplication::translate("MainWindow", "Mouse pointer settings", nullptr));
        checkBoxInvertMouse->setText(QCoreApplication::translate("MainWindow", "Invert Y-Axis", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Analog sensitivity", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Gyro sensitivity", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Gyro deadzone", nullptr));
        label_gyro_accel->setText(QCoreApplication::translate("MainWindow", "Gyro acceleration", nullptr));
        groupBoxApplicationSettings->setTitle(QCoreApplication::translate("MainWindow", "Application settings", nullptr));
        checkBoxDiagnostics->setText(QCoreApplication::translate("MainWindow", "Show diagnostics tab", nullptr));
        checkBoxAppNap->setText(QCoreApplication::translate("MainWindow", "Prevent App Nap", nullptr));
        checkBoxIdleSleep->setText(QCoreApplication::translate("MainWindow", "Prevent idle sleep", nullptr));
        checkBoxInvertIcon->setText(QCoreApplication::translate("MainWindow", "Use Dark Mode icon", nullptr));
        checkBoxWarnClose->setText(QCoreApplication::translate("MainWindow", "Warn on application close", nullptr));
        checkBoxAutoConnect->setText(QCoreApplication::translate("MainWindow", "Automatically reconnect", nullptr));
        groupBoxJoyConSettings->setTitle(QCoreApplication::translate("MainWindow", "JoyCon Settings", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Player LED", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSettings), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        checkBoxLeftClick->setText(QCoreApplication::translate("MainWindow", "Left click with Y", nullptr));
        checkBoxGyroMouse->setText(QCoreApplication::translate("MainWindow", "Move mouse with gyro data", nullptr));
        checkBoxRequireZR->setText(QCoreApplication::translate("MainWindow", "Require ZR to be held for mouse tracking", nullptr));
        checkBoxRightAnalogMouse->setText(QCoreApplication::translate("MainWindow", "Scroll with right analog data", nullptr));
        checkBoxRightClick->setText(QCoreApplication::translate("MainWindow", "Right click with X", nullptr));
        checkBoxLeftAnalogMouse->setText(QCoreApplication::translate("MainWindow", "Move mouse with left analog data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabControls), QCoreApplication::translate("MainWindow", "Controls", nullptr));
        groupBoxExposure->setTitle(QCoreApplication::translate("MainWindow", "Exposure", nullptr));
        spinBoxExposure->setSuffix(QCoreApplication::translate("MainWindow", " us", nullptr));
        groupBoxResolution->setTitle(QCoreApplication::translate("MainWindow", "Resolution", nullptr));
        radioButton240->setText(QCoreApplication::translate("MainWindow", "240 x 320", nullptr));
        radioButton120->setText(QCoreApplication::translate("MainWindow", "120 x 160", nullptr));
        radioButton60->setText(QCoreApplication::translate("MainWindow", "60 x 80", nullptr));
        radioButton30->setText(QCoreApplication::translate("MainWindow", "30 x 40", nullptr));
        pushButtonStream->setText(QCoreApplication::translate("MainWindow", "Stream", nullptr));
        pushButtonCapture->setText(QCoreApplication::translate("MainWindow", "Capture", nullptr));
        pushButtonSaveImage->setText(QCoreApplication::translate("MainWindow", "Save...", nullptr));
        labelCameraPreview->setText(QCoreApplication::translate("MainWindow", "IR Preview", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCamera), QCoreApplication::translate("MainWindow", "Camera", nullptr));
        labelRate->setText(QCoreApplication::translate("MainWindow", "Rate: ", nullptr));
        labelButtons->setText(QCoreApplication::translate("MainWindow", "Buttons:", nullptr));
        labelAccel->setText(QCoreApplication::translate("MainWindow", "Accel:", nullptr));
        labelGyro->setText(QCoreApplication::translate("MainWindow", "Gyro:", nullptr));
        labelAnalogL->setText(QCoreApplication::translate("MainWindow", "Analog L:", nullptr));
        labelAnalogR->setText(QCoreApplication::translate("MainWindow", "Analog R:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDiagnostics), QCoreApplication::translate("MainWindow", "Diagnostics", nullptr));
        menuExit->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
