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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetMeasOffline
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *labelSourceRight;
    QLabel *labelSourceLeft;
    QPushButton *pushButtonRightSource;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelLeftDisplay;
    QLabel *labelRightDisplay;
    QDoubleSpinBox *doubleSpinBoxDistance;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonLeftSource;
    QPushButton *pushButtonStart;

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
        labelSourceRight = new QLabel(widgetMeasOffline);
        labelSourceRight->setObjectName(QStringLiteral("labelSourceRight"));
        labelSourceRight->setMinimumSize(QSize(0, 25));
        labelSourceRight->setMaximumSize(QSize(16777215, 25));
        labelSourceRight->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelSourceRight, 3, 0, 1, 1);

        labelSourceLeft = new QLabel(widgetMeasOffline);
        labelSourceLeft->setObjectName(QStringLiteral("labelSourceLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(76);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSourceLeft->sizePolicy().hasHeightForWidth());
        labelSourceLeft->setSizePolicy(sizePolicy);
        labelSourceLeft->setMinimumSize(QSize(0, 25));
        labelSourceLeft->setMaximumSize(QSize(16777215, 25));
        labelSourceLeft->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelSourceLeft, 2, 0, 1, 1);

        pushButtonRightSource = new QPushButton(widgetMeasOffline);
        pushButtonRightSource->setObjectName(QStringLiteral("pushButtonRightSource"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(24);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonRightSource->sizePolicy().hasHeightForWidth());
        pushButtonRightSource->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonRightSource, 3, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelLeftDisplay = new QLabel(widgetMeasOffline);
        labelLeftDisplay->setObjectName(QStringLiteral("labelLeftDisplay"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(24);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelLeftDisplay->sizePolicy().hasHeightForWidth());
        labelLeftDisplay->setSizePolicy(sizePolicy2);
        labelLeftDisplay->setMinimumSize(QSize(200, 150));
        labelLeftDisplay->setSizeIncrement(QSize(4, 3));
        labelLeftDisplay->setBaseSize(QSize(200, 150));
        labelLeftDisplay->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(labelLeftDisplay);

        labelRightDisplay = new QLabel(widgetMeasOffline);
        labelRightDisplay->setObjectName(QStringLiteral("labelRightDisplay"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(24);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelRightDisplay->sizePolicy().hasHeightForWidth());
        labelRightDisplay->setSizePolicy(sizePolicy3);
        labelRightDisplay->setMinimumSize(QSize(200, 150));
        labelRightDisplay->setSizeIncrement(QSize(4, 3));
        labelRightDisplay->setBaseSize(QSize(200, 150));
        labelRightDisplay->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(labelRightDisplay);

        doubleSpinBoxDistance = new QDoubleSpinBox(widgetMeasOffline);
        doubleSpinBoxDistance->setObjectName(QStringLiteral("doubleSpinBoxDistance"));
        doubleSpinBoxDistance->setMaximum(1000);

        verticalLayout_3->addWidget(doubleSpinBoxDistance);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        pushButtonLeftSource = new QPushButton(widgetMeasOffline);
        pushButtonLeftSource->setObjectName(QStringLiteral("pushButtonLeftSource"));
        sizePolicy1.setHeightForWidth(pushButtonLeftSource->sizePolicy().hasHeightForWidth());
        pushButtonLeftSource->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonLeftSource, 2, 1, 1, 1);

        pushButtonStart = new QPushButton(widgetMeasOffline);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        sizePolicy1.setHeightForWidth(pushButtonStart->sizePolicy().hasHeightForWidth());
        pushButtonStart->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonStart, 4, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(widgetMeasOffline);

        QMetaObject::connectSlotsByName(widgetMeasOffline);
    } // setupUi

    void retranslateUi(QWidget *widgetMeasOffline)
    {
        widgetMeasOffline->setWindowTitle(QApplication::translate("widgetMeasOffline", "Form", nullptr));
        labelSourceRight->setText(QString());
        labelSourceLeft->setText(QString());
        pushButtonRightSource->setText(QApplication::translate("widgetMeasOffline", "Select right source", nullptr));
        labelLeftDisplay->setText(QString());
        labelRightDisplay->setText(QString());
        pushButtonLeftSource->setText(QApplication::translate("widgetMeasOffline", "Select left source", nullptr));
        pushButtonStart->setText(QApplication::translate("widgetMeasOffline", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetMeasOffline: public Ui_widgetMeasOffline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMEASOFFLINE_H
