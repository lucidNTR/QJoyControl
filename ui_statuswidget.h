/********************************************************************************
** Form generated from reading UI file 'statuswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSWIDGET_H
#define UI_STATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelTempText;
    QLabel *labelBatteryText;
    QLabel *labelBatteryGraphic;

    void setupUi(QWidget *StatusWidget)
    {
        if (StatusWidget->objectName().isEmpty())
            StatusWidget->setObjectName("StatusWidget");
        StatusWidget->resize(439, 38);
        StatusWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(StatusWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        labelTempText = new QLabel(StatusWidget);
        labelTempText->setObjectName("labelTempText");

        horizontalLayout->addWidget(labelTempText);

        labelBatteryText = new QLabel(StatusWidget);
        labelBatteryText->setObjectName("labelBatteryText");

        horizontalLayout->addWidget(labelBatteryText);

        labelBatteryGraphic = new QLabel(StatusWidget);
        labelBatteryGraphic->setObjectName("labelBatteryGraphic");
        labelBatteryGraphic->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(labelBatteryGraphic);


        retranslateUi(StatusWidget);

        QMetaObject::connectSlotsByName(StatusWidget);
    } // setupUi

    void retranslateUi(QWidget *StatusWidget)
    {
        StatusWidget->setWindowTitle(QCoreApplication::translate("StatusWidget", "Form", nullptr));
        labelTempText->setText(QString());
        labelBatteryText->setText(QString());
        labelBatteryGraphic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StatusWidget: public Ui_StatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSWIDGET_H
