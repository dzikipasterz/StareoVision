/********************************************************************************
** Form generated from reading UI file 'widgetmeasonline.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMEASONLINE_H
#define UI_WIDGETMEASONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMeasOnline
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxDistance;

    void setupUi(QWidget *widgetMeasOnline)
    {
        if (widgetMeasOnline->objectName().isEmpty())
            widgetMeasOnline->setObjectName(QStringLiteral("widgetMeasOnline"));
        widgetMeasOnline->resize(861, 681);
        widgetMeasOnline->setMinimumSize(QSize(861, 681));
        verticalLayout = new QVBoxLayout(widgetMeasOnline);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        doubleSpinBoxDistance = new QDoubleSpinBox(widgetMeasOnline);
        doubleSpinBoxDistance->setObjectName(QStringLiteral("doubleSpinBoxDistance"));
        doubleSpinBoxDistance->setReadOnly(true);
        doubleSpinBoxDistance->setMaximum(100000);

        verticalLayout->addWidget(doubleSpinBoxDistance);


        retranslateUi(widgetMeasOnline);

        QMetaObject::connectSlotsByName(widgetMeasOnline);
    } // setupUi

    void retranslateUi(QWidget *widgetMeasOnline)
    {
        widgetMeasOnline->setWindowTitle(QApplication::translate("widgetMeasOnline", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetMeasOnline: public Ui_widgetMeasOnline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMEASONLINE_H
