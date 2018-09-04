/********************************************************************************
** Form generated from reading UI file 'closeconfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSECONFIRM_H
#define UI_CLOSECONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_closeConfirm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *closeConfirm)
    {
        if (closeConfirm->objectName().isEmpty())
            closeConfirm->setObjectName(QStringLiteral("closeConfirm"));
        closeConfirm->resize(396, 135);
        buttonBox = new QDialogButtonBox(closeConfirm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 90, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(closeConfirm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 361, 81));

        retranslateUi(closeConfirm);
        QObject::connect(buttonBox, SIGNAL(accepted()), closeConfirm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), closeConfirm, SLOT(reject()));

        QMetaObject::connectSlotsByName(closeConfirm);
    } // setupUi

    void retranslateUi(QDialog *closeConfirm)
    {
        closeConfirm->setWindowTitle(QApplication::translate("closeConfirm", "Dialog", nullptr));
        label->setText(QApplication::translate("closeConfirm", "Czy na pewno chcesz zako\305\204czy\304\207 dzia\305\202anie programu?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class closeConfirm: public Ui_closeConfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSECONFIRM_H
