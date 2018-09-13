/********************************************************************************
** Form generated from reading UI file 'widgetcalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCALIBRATION_H
#define UI_WIDGETCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetCalibration
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *leftCamera;
    QLabel *rightCamera;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBoxRows;
    QSpinBox *spinBoxCols;
    QDoubleSpinBox *doubleSpinBoxSquareSize;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLastPictStatus;
    QSpinBox *spinBoxCollectedSets;
    QPushButton *pushButtonTakePicture;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonChooseDirToLoad;
    QLabel *labelPicsDir;
    QLabel *label_4;
    QPushButton *pushButtonLoad;
    QLabel *labelCalibrationStatus;
    QPushButton *pushButtonCalibrate;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *widgetCalibration)
    {
        if (widgetCalibration->objectName().isEmpty())
            widgetCalibration->setObjectName(QStringLiteral("widgetCalibration"));
        widgetCalibration->resize(861, 681);
        widgetCalibration->setMinimumSize(QSize(861, 681));
        verticalLayout = new QVBoxLayout(widgetCalibration);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        leftCamera = new QLabel(widgetCalibration);
        leftCamera->setObjectName(QStringLiteral("leftCamera"));
        leftCamera->setMinimumSize(QSize(412, 303));
        leftCamera->setSizeIncrement(QSize(1, 1));
        leftCamera->setFrameShape(QFrame::Box);

        gridLayout->addWidget(leftCamera, 0, 0, 1, 1);

        rightCamera = new QLabel(widgetCalibration);
        rightCamera->setObjectName(QStringLiteral("rightCamera"));
        rightCamera->setMinimumSize(QSize(412, 303));
        rightCamera->setSizeIncrement(QSize(1, 1));
        rightCamera->setFrameShape(QFrame::Box);

        gridLayout->addWidget(rightCamera, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        spinBoxRows = new QSpinBox(widgetCalibration);
        spinBoxRows->setObjectName(QStringLiteral("spinBoxRows"));
        spinBoxRows->setMinimumSize(QSize(276, 26));

        gridLayout_2->addWidget(spinBoxRows, 1, 0, 1, 1);

        spinBoxCols = new QSpinBox(widgetCalibration);
        spinBoxCols->setObjectName(QStringLiteral("spinBoxCols"));
        spinBoxCols->setMinimumSize(QSize(277, 26));

        gridLayout_2->addWidget(spinBoxCols, 1, 1, 1, 1);

        doubleSpinBoxSquareSize = new QDoubleSpinBox(widgetCalibration);
        doubleSpinBoxSquareSize->setObjectName(QStringLiteral("doubleSpinBoxSquareSize"));
        doubleSpinBoxSquareSize->setMinimumSize(QSize(276, 26));

        gridLayout_2->addWidget(doubleSpinBoxSquareSize, 1, 2, 1, 1);

        label = new QLabel(widgetCalibration);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(276, 17));
        label->setMaximumSize(QSize(16777215, 17));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widgetCalibration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(277, 17));
        label_2->setMaximumSize(QSize(16777215, 17));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(widgetCalibration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(276, 17));
        label_3->setMaximumSize(QSize(16777215, 17));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        radioButton = new QRadioButton(widgetCalibration);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLastPictStatus = new QLabel(widgetCalibration);
        labelLastPictStatus->setObjectName(QStringLiteral("labelLastPictStatus"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(11);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLastPictStatus->sizePolicy().hasHeightForWidth());
        labelLastPictStatus->setSizePolicy(sizePolicy);
        labelLastPictStatus->setMaximumSize(QSize(16777215, 26));
        labelLastPictStatus->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(labelLastPictStatus);

        spinBoxCollectedSets = new QSpinBox(widgetCalibration);
        spinBoxCollectedSets->setObjectName(QStringLiteral("spinBoxCollectedSets"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxCollectedSets->sizePolicy().hasHeightForWidth());
        spinBoxCollectedSets->setSizePolicy(sizePolicy1);
        spinBoxCollectedSets->setMaximumSize(QSize(16777215, 26));
        spinBoxCollectedSets->setReadOnly(true);
        spinBoxCollectedSets->setMaximum(1024);

        horizontalLayout->addWidget(spinBoxCollectedSets);

        pushButtonTakePicture = new QPushButton(widgetCalibration);
        pushButtonTakePicture->setObjectName(QStringLiteral("pushButtonTakePicture"));
        sizePolicy1.setHeightForWidth(pushButtonTakePicture->sizePolicy().hasHeightForWidth());
        pushButtonTakePicture->setSizePolicy(sizePolicy1);
        pushButtonTakePicture->setMaximumSize(QSize(16777215, 26));

        horizontalLayout->addWidget(pushButtonTakePicture);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonChooseDirToLoad = new QPushButton(widgetCalibration);
        pushButtonChooseDirToLoad->setObjectName(QStringLiteral("pushButtonChooseDirToLoad"));
        pushButtonChooseDirToLoad->setMinimumSize(QSize(0, 25));
        pushButtonChooseDirToLoad->setMaximumSize(QSize(207, 25));

        gridLayout_3->addWidget(pushButtonChooseDirToLoad, 1, 1, 1, 1);

        labelPicsDir = new QLabel(widgetCalibration);
        labelPicsDir->setObjectName(QStringLiteral("labelPicsDir"));
        labelPicsDir->setMinimumSize(QSize(0, 25));
        labelPicsDir->setMaximumSize(QSize(16777215, 25));
        labelPicsDir->setFrameShape(QFrame::Box);

        gridLayout_3->addWidget(labelPicsDir, 1, 0, 1, 1);

        label_4 = new QLabel(widgetCalibration);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        pushButtonLoad = new QPushButton(widgetCalibration);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setMinimumSize(QSize(0, 25));
        pushButtonLoad->setMaximumSize(QSize(16777215, 25));

        gridLayout_3->addWidget(pushButtonLoad, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        labelCalibrationStatus = new QLabel(widgetCalibration);
        labelCalibrationStatus->setObjectName(QStringLiteral("labelCalibrationStatus"));
        labelCalibrationStatus->setMinimumSize(QSize(0, 25));
        labelCalibrationStatus->setMaximumSize(QSize(16777215, 25));
        labelCalibrationStatus->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(labelCalibrationStatus);

        pushButtonCalibrate = new QPushButton(widgetCalibration);
        pushButtonCalibrate->setObjectName(QStringLiteral("pushButtonCalibrate"));

        verticalLayout->addWidget(pushButtonCalibrate);

        verticalSpacer_2 = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(widgetCalibration);

        QMetaObject::connectSlotsByName(widgetCalibration);
    } // setupUi

    void retranslateUi(QWidget *widgetCalibration)
    {
        widgetCalibration->setWindowTitle(QApplication::translate("widgetCalibration", "Form", nullptr));
        leftCamera->setText(QString());
        rightCamera->setText(QString());
        label->setText(QApplication::translate("widgetCalibration", "Liczba wierszy szachownicy", nullptr));
        label_2->setText(QApplication::translate("widgetCalibration", "Liczba kolumn szachownicy", nullptr));
        label_3->setText(QApplication::translate("widgetCalibration", "Rozmiar pola szachownicy (mm)", nullptr));
        radioButton->setText(QApplication::translate("widgetCalibration", "Poka\305\274 znalezione punkty", nullptr));
        labelLastPictStatus->setText(QString());
        pushButtonTakePicture->setText(QApplication::translate("widgetCalibration", "Zr\303\263b zdj\304\231cie", nullptr));
        pushButtonChooseDirToLoad->setText(QApplication::translate("widgetCalibration", "Wybierz folder do wczytania", nullptr));
        labelPicsDir->setText(QString());
        label_4->setText(QApplication::translate("widgetCalibration", "Wczytaj zdj\304\231cia", nullptr));
        pushButtonLoad->setText(QApplication::translate("widgetCalibration", "Wczytaj", nullptr));
        labelCalibrationStatus->setText(QString());
        pushButtonCalibrate->setText(QApplication::translate("widgetCalibration", "Kalibruj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetCalibration: public Ui_widgetCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCALIBRATION_H
