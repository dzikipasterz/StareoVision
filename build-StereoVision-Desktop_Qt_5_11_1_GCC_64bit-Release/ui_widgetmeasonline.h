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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMeasOnline
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayoutMain;
    QGridLayout *gridLayoutParams;
    QSpinBox *spinBoxY;
    QDoubleSpinBox *doubleSpinBoxDistance;
    QSpinBox *spinBoxX;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayoutRaw;
    QLabel *label;
    QLabel *labelLeftDisplay;
    QLabel *label_2;
    QLabel *labelRightDisplay;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxFPS;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QLabel *labelResultsPath;

    void setupUi(QWidget *widgetMeasOnline)
    {
        if (widgetMeasOnline->objectName().isEmpty())
            widgetMeasOnline->setObjectName(QStringLiteral("widgetMeasOnline"));
        widgetMeasOnline->resize(861, 681);
        widgetMeasOnline->setMinimumSize(QSize(861, 681));
        gridLayout_3 = new QGridLayout(widgetMeasOnline);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayoutMain = new QGridLayout();
        gridLayoutMain->setObjectName(QStringLiteral("gridLayoutMain"));
        gridLayoutParams = new QGridLayout();
        gridLayoutParams->setObjectName(QStringLiteral("gridLayoutParams"));
        spinBoxY = new QSpinBox(widgetMeasOnline);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        spinBoxY->setMaximumSize(QSize(10000, 26));
        spinBoxY->setMaximum(10000);

        gridLayoutParams->addWidget(spinBoxY, 1, 2, 1, 1);

        doubleSpinBoxDistance = new QDoubleSpinBox(widgetMeasOnline);
        doubleSpinBoxDistance->setObjectName(QStringLiteral("doubleSpinBoxDistance"));
        doubleSpinBoxDistance->setMaximumSize(QSize(10000, 26));
        doubleSpinBoxDistance->setReadOnly(true);
        doubleSpinBoxDistance->setMaximum(100000);

        gridLayoutParams->addWidget(doubleSpinBoxDistance, 1, 0, 1, 1);

        spinBoxX = new QSpinBox(widgetMeasOnline);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));
        spinBoxX->setMaximumSize(QSize(10000, 26));
        spinBoxX->setMaximum(10000);

        gridLayoutParams->addWidget(spinBoxX, 1, 1, 1, 1);

        label_3 = new QLabel(widgetMeasOnline);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(10000, 20));

        gridLayoutParams->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(widgetMeasOnline);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(10000, 20));

        gridLayoutParams->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(widgetMeasOnline);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 20));
        label_5->setMaximumSize(QSize(10000, 20));

        gridLayoutParams->addWidget(label_5, 0, 2, 1, 1);


        gridLayoutMain->addLayout(gridLayoutParams, 2, 0, 1, 1);

        verticalLayoutRaw = new QVBoxLayout();
        verticalLayoutRaw->setObjectName(QStringLiteral("verticalLayoutRaw"));
        label = new QLabel(widgetMeasOnline);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 17));

        verticalLayoutRaw->addWidget(label);

        labelLeftDisplay = new QLabel(widgetMeasOnline);
        labelLeftDisplay->setObjectName(QStringLiteral("labelLeftDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(24);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLeftDisplay->sizePolicy().hasHeightForWidth());
        labelLeftDisplay->setSizePolicy(sizePolicy);
        labelLeftDisplay->setMinimumSize(QSize(200, 150));
        labelLeftDisplay->setMaximumSize(QSize(200, 150));
        labelLeftDisplay->setSizeIncrement(QSize(4, 3));
        labelLeftDisplay->setBaseSize(QSize(200, 150));
        labelLeftDisplay->setFrameShape(QFrame::Box);

        verticalLayoutRaw->addWidget(labelLeftDisplay);

        label_2 = new QLabel(widgetMeasOnline);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(200, 17));

        verticalLayoutRaw->addWidget(label_2);

        labelRightDisplay = new QLabel(widgetMeasOnline);
        labelRightDisplay->setObjectName(QStringLiteral("labelRightDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(24);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelRightDisplay->sizePolicy().hasHeightForWidth());
        labelRightDisplay->setSizePolicy(sizePolicy1);
        labelRightDisplay->setMinimumSize(QSize(200, 150));
        labelRightDisplay->setMaximumSize(QSize(200, 150));
        labelRightDisplay->setSizeIncrement(QSize(4, 3));
        labelRightDisplay->setBaseSize(QSize(200, 150));
        labelRightDisplay->setFrameShape(QFrame::Box);

        verticalLayoutRaw->addWidget(labelRightDisplay);

        label_6 = new QLabel(widgetMeasOnline);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayoutRaw->addWidget(label_6);

        doubleSpinBoxFPS = new QDoubleSpinBox(widgetMeasOnline);
        doubleSpinBoxFPS->setObjectName(QStringLiteral("doubleSpinBoxFPS"));
        doubleSpinBoxFPS->setMaximumSize(QSize(200, 26));

        verticalLayoutRaw->addWidget(doubleSpinBoxFPS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutRaw->addItem(verticalSpacer);


        gridLayoutMain->addLayout(verticalLayoutRaw, 0, 1, 1, 1);

        pushButton = new QPushButton(widgetMeasOnline);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setCheckable(true);

        gridLayoutMain->addWidget(pushButton, 3, 1, 1, 1);

        labelResultsPath = new QLabel(widgetMeasOnline);
        labelResultsPath->setObjectName(QStringLiteral("labelResultsPath"));
        labelResultsPath->setMinimumSize(QSize(633, 25));
        labelResultsPath->setFrameShape(QFrame::Box);

        gridLayoutMain->addWidget(labelResultsPath, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayoutMain, 0, 0, 1, 1);


        retranslateUi(widgetMeasOnline);

        QMetaObject::connectSlotsByName(widgetMeasOnline);
    } // setupUi

    void retranslateUi(QWidget *widgetMeasOnline)
    {
        widgetMeasOnline->setWindowTitle(QApplication::translate("widgetMeasOnline", "Form", nullptr));
        label_3->setText(QApplication::translate("widgetMeasOnline", "Dystans", nullptr));
        label_4->setText(QApplication::translate("widgetMeasOnline", "x", nullptr));
        label_5->setText(QApplication::translate("widgetMeasOnline", "y", nullptr));
        label->setText(QApplication::translate("widgetMeasOnline", "Lewy obraz", nullptr));
        labelLeftDisplay->setText(QString());
        label_2->setText(QApplication::translate("widgetMeasOnline", "Prawy obraz", nullptr));
        labelRightDisplay->setText(QString());
        label_6->setText(QApplication::translate("widgetMeasOnline", "FPS", nullptr));
        pushButton->setText(QApplication::translate("widgetMeasOnline", "Zapis do pliku", nullptr));
        labelResultsPath->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widgetMeasOnline: public Ui_widgetMeasOnline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMEASONLINE_H
