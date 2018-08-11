/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:

    void setupUi(QDialog *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QStringLiteral("info"));
        info->resize(400, 300);

        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QDialog *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
