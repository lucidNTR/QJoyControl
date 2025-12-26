/********************************************************************************
** Form generated from reading UI file 'inputmappanel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTMAPPANEL_H
#define UI_INPUTMAPPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputMapPanel
{
public:
    QGridLayout *gridLayoutContainer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;

    void setupUi(QWidget *InputMapPanel)
    {
        if (InputMapPanel->objectName().isEmpty())
            InputMapPanel->setObjectName("InputMapPanel");
        InputMapPanel->resize(116, 57);
        QFont font;
        font.setPointSize(10);
        InputMapPanel->setFont(font);
        gridLayoutContainer = new QGridLayout(InputMapPanel);
        gridLayoutContainer->setObjectName("gridLayoutContainer");
        groupBox = new QGroupBox(InputMapPanel);
        groupBox->setObjectName("groupBox");
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 1, 1, 1);


        gridLayoutContainer->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(InputMapPanel);

        QMetaObject::connectSlotsByName(InputMapPanel);
    } // setupUi

    void retranslateUi(QWidget *InputMapPanel)
    {
        InputMapPanel->setWindowTitle(QCoreApplication::translate("InputMapPanel", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("InputMapPanel", "groupbox", nullptr));
        label_5->setText(QCoreApplication::translate("InputMapPanel", "Button", nullptr));
        label_6->setText(QCoreApplication::translate("InputMapPanel", "Key", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InputMapPanel: public Ui_InputMapPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTMAPPANEL_H
