/********************************************************************************
** Form generated from reading UI file 'widgetmeasoffline.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMEASOFFLINE_H
#define UI_WIDGETMEASOFFLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMeasOffline
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButtonRightSource;
    QPushButton *pushButtonWrite;
    QLabel *labelSourceRight;
    QLabel *labelSourceLeft;
    QPushButton *pushButtonLeftSource;
    QPushButton *pushButtonStart;
    QLabel *labelResultsPath;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *labelLeftDisplay;
    QLabel *label_2;
    QLabel *labelRightDisplay;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinBoxX;
    QSpinBox *spinBoxY;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxDistance;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxFPS;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *widgetMeasOffline)
    {
        if (widgetMeasOffline->objectName().isEmpty())
            widgetMeasOffline->setObjectName(QStringLiteral("widgetMeasOffline"));
        widgetMeasOffline->resize(861, 681);
        widgetMeasOffline->setMinimumSize(QSize(861, 681));
        horizontalLayout = new QHBoxLayout(widgetMeasOffline);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonRightSource = new QPushButton(widgetMeasOffline);
        pushButtonRightSource->setObjectName(QStringLiteral("pushButtonRightSource"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(24);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonRightSource->sizePolicy().hasHeightForWidth());
        pushButtonRightSource->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonRightSource, 3, 1, 1, 1);

        pushButtonWrite = new QPushButton(widgetMeasOffline);
        pushButtonWrite->setObjectName(QStringLiteral("pushButtonWrite"));
        pushButtonWrite->setCheckable(true);

        gridLayout->addWidget(pushButtonWrite, 4, 1, 1, 1);

        labelSourceRight = new QLabel(widgetMeasOffline);
        labelSourceRight->setObjectName(QStringLiteral("labelSourceRight"));
        labelSourceRight->setMinimumSize(QSize(0, 25));
        labelSourceRight->setMaximumSize(QSize(16777215, 25));
        labelSourceRight->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelSourceRight, 3, 0, 1, 1);

        labelSourceLeft = new QLabel(widgetMeasOffline);
        labelSourceLeft->setObjectName(QStringLiteral("labelSourceLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(76);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelSourceLeft->sizePolicy().hasHeightForWidth());
        labelSourceLeft->setSizePolicy(sizePolicy1);
        labelSourceLeft->setMinimumSize(QSize(0, 25));
        labelSourceLeft->setMaximumSize(QSize(16777215, 25));
        labelSourceLeft->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelSourceLeft, 2, 0, 1, 1);

        pushButtonLeftSource = new QPushButton(widgetMeasOffline);
        pushButtonLeftSource->setObjectName(QStringLiteral("pushButtonLeftSource"));
        sizePolicy.setHeightForWidth(pushButtonLeftSource->sizePolicy().hasHeightForWidth());
        pushButtonLeftSource->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonLeftSource, 2, 1, 1, 1);

        pushButtonStart = new QPushButton(widgetMeasOffline);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        sizePolicy.setHeightForWidth(pushButtonStart->sizePolicy().hasHeightForWidth());
        pushButtonStart->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonStart, 5, 1, 1, 1);

        labelResultsPath = new QLabel(widgetMeasOffline);
        labelResultsPath->setObjectName(QStringLiteral("labelResultsPath"));
        labelResultsPath->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelResultsPath, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(widgetMeasOffline);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 17));

        verticalLayout_3->addWidget(label);

        labelLeftDisplay = new QLabel(widgetMeasOffline);
        labelLeftDisplay->setObjectName(QStringLiteral("labelLeftDisplay"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(24);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelLeftDisplay->sizePolicy().hasHeightForWidth());
        labelLeftDisplay->setSizePolicy(sizePolicy2);
        labelLeftDisplay->setMinimumSize(QSize(200, 150));
        labelLeftDisplay->setMaximumSize(QSize(200, 150));
        labelLeftDisplay->setSizeIncrement(QSize(4, 3));
        labelLeftDisplay->setBaseSize(QSize(200, 150));
        labelLeftDisplay->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(labelLeftDisplay);

        label_2 = new QLabel(widgetMeasOffline);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(200, 17));

        verticalLayout_3->addWidget(label_2);

        labelRightDisplay = new QLabel(widgetMeasOffline);
        labelRightDisplay->setObjectName(QStringLiteral("labelRightDisplay"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(24);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelRightDisplay->sizePolicy().hasHeightForWidth());
        labelRightDisplay->setSizePolicy(sizePolicy3);
        labelRightDisplay->setMinimumSize(QSize(200, 150));
        labelRightDisplay->setMaximumSize(QSize(200, 150));
        labelRightDisplay->setSizeIncrement(QSize(4, 3));
        labelRightDisplay->setBaseSize(QSize(200, 150));
        labelRightDisplay->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(labelRightDisplay);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widgetMeasOffline);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(38, 17));

        horizontalLayout_3->addWidget(label_4);

        spinBoxX = new QSpinBox(widgetMeasOffline);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));
        spinBoxX->setMaximumSize(QSize(74, 26));
        spinBoxX->setMaximum(10000);

        horizontalLayout_3->addWidget(spinBoxX);

        spinBoxY = new QSpinBox(widgetMeasOffline);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        spinBoxY->setMaximumSize(QSize(74, 26));
        spinBoxY->setMaximum(10000);

        horizontalLayout_3->addWidget(spinBoxY);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_3 = new QLabel(widgetMeasOffline);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(200, 17));

        verticalLayout_3->addWidget(label_3);

        doubleSpinBoxDistance = new QDoubleSpinBox(widgetMeasOffline);
        doubleSpinBoxDistance->setObjectName(QStringLiteral("doubleSpinBoxDistance"));
        doubleSpinBoxDistance->setMaximumSize(QSize(200, 26));
        doubleSpinBoxDistance->setReadOnly(true);
        doubleSpinBoxDistance->setMaximum(100000);

        verticalLayout_3->addWidget(doubleSpinBoxDistance);

        label_6 = new QLabel(widgetMeasOffline);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(200, 17));

        verticalLayout_3->addWidget(label_6);

        doubleSpinBoxFPS = new QDoubleSpinBox(widgetMeasOffline);
        doubleSpinBoxFPS->setObjectName(QStringLiteral("doubleSpinBoxFPS"));
        doubleSpinBoxFPS->setMaximumSize(QSize(200, 26));
        doubleSpinBoxFPS->setReadOnly(true);

        verticalLayout_3->addWidget(doubleSpinBoxFPS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(widgetMeasOffline);

        QMetaObject::connectSlotsByName(widgetMeasOffline);
    } // setupUi

    void retranslateUi(QWidget *widgetMeasOffline)
    {
        widgetMeasOffline->setWindowTitle(QApplication::translate("widgetMeasOffline", "Form", nullptr));
        pushButtonRightSource->setText(QApplication::translate("widgetMeasOffline", "Prawy Obraz", nullptr));
        pushButtonWrite->setText(QApplication::translate("widgetMeasOffline", "Zapis do pliku", nullptr));
        labelSourceRight->setText(QString());
        labelSourceLeft->setText(QString());
        pushButtonLeftSource->setText(QApplication::translate("widgetMeasOffline", "Lewy obraz", nullptr));
        pushButtonStart->setText(QApplication::translate("widgetMeasOffline", "Start", nullptr));
        labelResultsPath->setText(QString());
        label->setText(QApplication::translate("widgetMeasOffline", "Lewy obraz", nullptr));
        labelLeftDisplay->setText(QString());
        label_2->setText(QApplication::translate("widgetMeasOffline", "Prawy obraz", nullptr));
        labelRightDisplay->setText(QString());
        label_4->setText(QApplication::translate("widgetMeasOffline", "(x, y)", nullptr));
        label_3->setText(QApplication::translate("widgetMeasOffline", "Dystans", nullptr));
        label_6->setText(QApplication::translate("widgetMeasOffline", "FPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetMeasOffline: public Ui_widgetMeasOffline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMEASOFFLINE_H
