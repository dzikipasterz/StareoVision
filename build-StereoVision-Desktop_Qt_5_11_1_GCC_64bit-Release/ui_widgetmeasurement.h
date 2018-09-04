/********************************************************************************
** Form generated from reading UI file 'widgetmeasurement.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMEASUREMENT_H
#define UI_WIDGETMEASUREMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMeasurement
{
public:
    QLabel *label;

    void setupUi(QWidget *widgetMeasurement)
    {
        if (widgetMeasurement->objectName().isEmpty())
            widgetMeasurement->setObjectName(QStringLiteral("widgetMeasurement"));
        widgetMeasurement->resize(861, 681);
        widgetMeasurement->setMinimumSize(QSize(861, 681));
        label = new QLabel(widgetMeasurement);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(326, 300, 121, 20));

        retranslateUi(widgetMeasurement);

        QMetaObject::connectSlotsByName(widgetMeasurement);
    } // setupUi

    void retranslateUi(QWidget *widgetMeasurement)
    {
        widgetMeasurement->setWindowTitle(QApplication::translate("widgetMeasurement", "Form", nullptr));
        label->setText(QApplication::translate("widgetMeasurement", "Measurement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetMeasurement: public Ui_widgetMeasurement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMEASUREMENT_H
