/********************************************************************************
** Form generated from reading UI file 'inputmapwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTMAPWIDGET_H
#define UI_INPUTMAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputMapWidget
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButtonSet;
    QLabel *labelKeyCode;
    QLabel *labelButton;

    void setupUi(QWidget *InputMapWidget)
    {
        if (InputMapWidget->objectName().isEmpty())
            InputMapWidget->setObjectName("InputMapWidget");
        InputMapWidget->resize(103, 19);
        QFont font;
        font.setPointSize(10);
        InputMapWidget->setFont(font);
        InputMapWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(InputMapWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        toolButtonSet = new QToolButton(InputMapWidget);
        toolButtonSet->setObjectName("toolButtonSet");

        gridLayout->addWidget(toolButtonSet, 0, 1, 1, 1);

        labelKeyCode = new QLabel(InputMapWidget);
        labelKeyCode->setObjectName("labelKeyCode");
        labelKeyCode->setFont(font);

        gridLayout->addWidget(labelKeyCode, 0, 2, 1, 1);

        labelButton = new QLabel(InputMapWidget);
        labelButton->setObjectName("labelButton");
        labelButton->setFont(font);
        labelButton->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelButton, 0, 0, 1, 1);


        retranslateUi(InputMapWidget);

        QMetaObject::connectSlotsByName(InputMapWidget);
    } // setupUi

    void retranslateUi(QWidget *InputMapWidget)
    {
        InputMapWidget->setWindowTitle(QCoreApplication::translate("InputMapWidget", "Form", nullptr));
        toolButtonSet->setText(QCoreApplication::translate("InputMapWidget", "Set", nullptr));
        labelKeyCode->setText(QCoreApplication::translate("InputMapWidget", "Value", nullptr));
        labelButton->setText(QCoreApplication::translate("InputMapWidget", "Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputMapWidget: public Ui_InputMapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTMAPWIDGET_H
