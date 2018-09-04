/********************************************************************************
** Form generated from reading UI file 'widgetrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETRECORD_H
#define UI_WIDGETRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetRecord
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLeftCamera;
    QLabel *labelRightCamera;
    QGridLayout *gridLayout;
    QPushButton *pushButtonTakePicture;
    QLabel *labelLeftMovPath;
    QLabel *labelLeftPicPath;
    QLabel *labelRightPicPath;
    QPushButton *pushButtonMakeMovie;
    QLabel *labelRightMovPath;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *widgetRecord)
    {
        if (widgetRecord->objectName().isEmpty())
            widgetRecord->setObjectName(QStringLiteral("widgetRecord"));
        widgetRecord->resize(861, 681);
        widgetRecord->setMinimumSize(QSize(861, 681));
        verticalLayout = new QVBoxLayout(widgetRecord);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLeftCamera = new QLabel(widgetRecord);
        labelLeftCamera->setObjectName(QStringLiteral("labelLeftCamera"));
        labelLeftCamera->setMinimumSize(QSize(412, 303));
        labelLeftCamera->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelLeftCamera);

        labelRightCamera = new QLabel(widgetRecord);
        labelRightCamera->setObjectName(QStringLiteral("labelRightCamera"));
        labelRightCamera->setMinimumSize(QSize(412, 303));
        labelRightCamera->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelRightCamera);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonTakePicture = new QPushButton(widgetRecord);
        pushButtonTakePicture->setObjectName(QStringLiteral("pushButtonTakePicture"));
        pushButtonTakePicture->setMaximumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonTakePicture, 3, 1, 1, 1);

        labelLeftMovPath = new QLabel(widgetRecord);
        labelLeftMovPath->setObjectName(QStringLiteral("labelLeftMovPath"));
        labelLeftMovPath->setMaximumSize(QSize(16777215, 25));
        labelLeftMovPath->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelLeftMovPath, 0, 0, 1, 1);

        labelLeftPicPath = new QLabel(widgetRecord);
        labelLeftPicPath->setObjectName(QStringLiteral("labelLeftPicPath"));
        labelLeftPicPath->setMinimumSize(QSize(735, 25));
        labelLeftPicPath->setMaximumSize(QSize(16777215, 25));
        labelLeftPicPath->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelLeftPicPath, 3, 0, 1, 1);

        labelRightPicPath = new QLabel(widgetRecord);
        labelRightPicPath->setObjectName(QStringLiteral("labelRightPicPath"));
        labelRightPicPath->setMinimumSize(QSize(735, 25));
        labelRightPicPath->setMaximumSize(QSize(16777215, 25));
        labelRightPicPath->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelRightPicPath, 4, 0, 1, 1);

        pushButtonMakeMovie = new QPushButton(widgetRecord);
        pushButtonMakeMovie->setObjectName(QStringLiteral("pushButtonMakeMovie"));
        pushButtonMakeMovie->setMaximumSize(QSize(100, 25));
        pushButtonMakeMovie->setCheckable(true);

        gridLayout->addWidget(pushButtonMakeMovie, 0, 1, 1, 1);

        labelRightMovPath = new QLabel(widgetRecord);
        labelRightMovPath->setObjectName(QStringLiteral("labelRightMovPath"));
        labelRightMovPath->setMinimumSize(QSize(0, 25));
        labelRightMovPath->setMaximumSize(QSize(16777215, 25));
        labelRightMovPath->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelRightMovPath, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(0, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(widgetRecord);

        QMetaObject::connectSlotsByName(widgetRecord);
    } // setupUi

    void retranslateUi(QWidget *widgetRecord)
    {
        widgetRecord->setWindowTitle(QApplication::translate("widgetRecord", "Form", nullptr));
        labelLeftCamera->setText(QString());
        labelRightCamera->setText(QString());
        pushButtonTakePicture->setText(QApplication::translate("widgetRecord", "Zr\303\263b zdj\304\231cie", nullptr));
        labelLeftMovPath->setText(QString());
        labelLeftPicPath->setText(QString());
        labelRightPicPath->setText(QString());
        pushButtonMakeMovie->setText(QApplication::translate("widgetRecord", "Nagrywaj", nullptr));
        labelRightMovPath->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widgetRecord: public Ui_widgetRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETRECORD_H
