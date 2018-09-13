/********************************************************************************
** Form generated from reading UI file 'widgetdisparity.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETDISPARITY_H
#define UI_WIDGETDISPARITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetDisparity
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonSource;
    QPushButton *pushButtonResults;
    QLabel *label_2;
    QLabel *labelSourcesDir;
    QLabel *label_3;
    QLabel *labelResultsDir;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *WidgetDisparity)
    {
        if (WidgetDisparity->objectName().isEmpty())
            WidgetDisparity->setObjectName(QStringLiteral("WidgetDisparity"));
        WidgetDisparity->resize(861, 681);
        WidgetDisparity->setMinimumSize(QSize(861, 681));
        verticalLayout = new QVBoxLayout(WidgetDisparity);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButtonSource = new QPushButton(WidgetDisparity);
        pushButtonSource->setObjectName(QStringLiteral("pushButtonSource"));
        pushButtonSource->setMaximumSize(QSize(120, 25));

        gridLayout_2->addWidget(pushButtonSource, 1, 1, 1, 1);

        pushButtonResults = new QPushButton(WidgetDisparity);
        pushButtonResults->setObjectName(QStringLiteral("pushButtonResults"));

        gridLayout_2->addWidget(pushButtonResults, 3, 1, 1, 1);

        label_2 = new QLabel(WidgetDisparity);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        labelSourcesDir = new QLabel(WidgetDisparity);
        labelSourcesDir->setObjectName(QStringLiteral("labelSourcesDir"));
        sizePolicy.setHeightForWidth(labelSourcesDir->sizePolicy().hasHeightForWidth());
        labelSourcesDir->setSizePolicy(sizePolicy);
        labelSourcesDir->setMaximumSize(QSize(16777215, 25));
        labelSourcesDir->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(labelSourcesDir, 1, 0, 1, 1);

        label_3 = new QLabel(WidgetDisparity);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        labelResultsDir = new QLabel(WidgetDisparity);
        labelResultsDir->setObjectName(QStringLiteral("labelResultsDir"));
        sizePolicy.setHeightForWidth(labelResultsDir->sizePolicy().hasHeightForWidth());
        labelResultsDir->setSizePolicy(sizePolicy);
        labelResultsDir->setMaximumSize(QSize(16777215, 25));
        labelResultsDir->setFrameShape(QFrame::Box);

        gridLayout_2->addWidget(labelResultsDir, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        pushButton = new QPushButton(WidgetDisparity);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        label_5 = new QLabel(WidgetDisparity);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(WidgetDisparity);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(label_6);


        retranslateUi(WidgetDisparity);

        QMetaObject::connectSlotsByName(WidgetDisparity);
    } // setupUi

    void retranslateUi(QWidget *WidgetDisparity)
    {
        WidgetDisparity->setWindowTitle(QApplication::translate("WidgetDisparity", "Form", nullptr));
        pushButtonSource->setText(QApplication::translate("WidgetDisparity", "Wybierz", nullptr));
        pushButtonResults->setText(QApplication::translate("WidgetDisparity", "Wybierz", nullptr));
        label_2->setText(QApplication::translate("WidgetDisparity", "Katalog z obrazami / wideo", nullptr));
        labelSourcesDir->setText(QString());
        label_3->setText(QApplication::translate("WidgetDisparity", "Katalog z obrazami wynikowymi", nullptr));
        labelResultsDir->setText(QString());
        pushButton->setText(QApplication::translate("WidgetDisparity", "Rozpocznij", nullptr));
        label_5->setText(QApplication::translate("WidgetDisparity", "Status", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetDisparity: public Ui_WidgetDisparity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETDISPARITY_H
