/********************************************************************************
** Form generated from reading UI file 'widgetsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSETTINGS_H
#define UI_WIDGETSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelRightCameraStatus;
    QLabel *leftCamera;
    QLabel *labelLeftCameraStatus;
    QLabel *rightCamera;
    QSpinBox *leftCameraId;
    QSpinBox *rightCameraId;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_5;
    QLabel *labelCalibFileLabel;
    QPushButton *pushButtonSelectPicDir;
    QComboBox *comboBoxAlgorithm;
    QPushButton *pushButtonSelectCalibFile;
    QLabel *labelSavePictDirLabel;
    QLabel *labelCalibFile;
    QPushButton *pushButtonSelectCalibDir;
    QLabel *labelCalibFilesLabel;
    QLabel *labelSaveMovDir;
    QLabel *labelCalibFilesDir;
    QLabel *labelAlgorithmLabel;
    QLabel *labelSavePictDir;
    QLabel *labelSaveMovDirLabel;
    QPushButton *pushButtonSelectMovDir;

    void setupUi(QWidget *widgetSettings)
    {
        if (widgetSettings->objectName().isEmpty())
            widgetSettings->setObjectName(QStringLiteral("widgetSettings"));
        widgetSettings->resize(861, 681);
        widgetSettings->setMinimumSize(QSize(861, 681));
        verticalLayout = new QVBoxLayout(widgetSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelRightCameraStatus = new QLabel(widgetSettings);
        labelRightCameraStatus->setObjectName(QStringLiteral("labelRightCameraStatus"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelRightCameraStatus->sizePolicy().hasHeightForWidth());
        labelRightCameraStatus->setSizePolicy(sizePolicy);
        labelRightCameraStatus->setMinimumSize(QSize(411, 21));
        labelRightCameraStatus->setMaximumSize(QSize(2000, 21));
        labelRightCameraStatus->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelRightCameraStatus, 2, 1, 1, 1);

        leftCamera = new QLabel(widgetSettings);
        leftCamera->setObjectName(QStringLiteral("leftCamera"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftCamera->sizePolicy().hasHeightForWidth());
        leftCamera->setSizePolicy(sizePolicy1);
        leftCamera->setMinimumSize(QSize(412, 303));
        leftCamera->setSizeIncrement(QSize(4, 3));
        leftCamera->setBaseSize(QSize(412, 303));
        leftCamera->setFrameShape(QFrame::Box);

        gridLayout->addWidget(leftCamera, 0, 0, 1, 1);

        labelLeftCameraStatus = new QLabel(widgetSettings);
        labelLeftCameraStatus->setObjectName(QStringLiteral("labelLeftCameraStatus"));
        sizePolicy.setHeightForWidth(labelLeftCameraStatus->sizePolicy().hasHeightForWidth());
        labelLeftCameraStatus->setSizePolicy(sizePolicy);
        labelLeftCameraStatus->setMinimumSize(QSize(411, 21));
        labelLeftCameraStatus->setMaximumSize(QSize(2000, 21));
        labelLeftCameraStatus->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelLeftCameraStatus, 2, 0, 1, 1);

        rightCamera = new QLabel(widgetSettings);
        rightCamera->setObjectName(QStringLiteral("rightCamera"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightCamera->sizePolicy().hasHeightForWidth());
        rightCamera->setSizePolicy(sizePolicy2);
        rightCamera->setMinimumSize(QSize(412, 303));
        rightCamera->setSizeIncrement(QSize(4, 3));
        rightCamera->setBaseSize(QSize(412, 303));
        rightCamera->setFrameShape(QFrame::Box);

        gridLayout->addWidget(rightCamera, 0, 1, 1, 1);

        leftCameraId = new QSpinBox(widgetSettings);
        leftCameraId->setObjectName(QStringLiteral("leftCameraId"));
        leftCameraId->setMaximum(5);

        gridLayout->addWidget(leftCameraId, 1, 0, 1, 1);

        rightCameraId = new QSpinBox(widgetSettings);
        rightCameraId->setObjectName(QStringLiteral("rightCameraId"));

        gridLayout->addWidget(rightCameraId, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        labelCalibFileLabel = new QLabel(widgetSettings);
        labelCalibFileLabel->setObjectName(QStringLiteral("labelCalibFileLabel"));
        labelCalibFileLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_5->addWidget(labelCalibFileLabel, 8, 0, 1, 1);

        pushButtonSelectPicDir = new QPushButton(widgetSettings);
        pushButtonSelectPicDir->setObjectName(QStringLiteral("pushButtonSelectPicDir"));
        pushButtonSelectPicDir->setMinimumSize(QSize(0, 25));
        pushButtonSelectPicDir->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(pushButtonSelectPicDir, 3, 1, 1, 1);

        comboBoxAlgorithm = new QComboBox(widgetSettings);
        comboBoxAlgorithm->setObjectName(QStringLiteral("comboBoxAlgorithm"));
        comboBoxAlgorithm->setEditable(false);

        gridLayout_5->addWidget(comboBoxAlgorithm, 11, 0, 1, 1);

        pushButtonSelectCalibFile = new QPushButton(widgetSettings);
        pushButtonSelectCalibFile->setObjectName(QStringLiteral("pushButtonSelectCalibFile"));
        pushButtonSelectCalibFile->setMinimumSize(QSize(0, 25));
        pushButtonSelectCalibFile->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(pushButtonSelectCalibFile, 9, 1, 1, 1);

        labelSavePictDirLabel = new QLabel(widgetSettings);
        labelSavePictDirLabel->setObjectName(QStringLiteral("labelSavePictDirLabel"));
        labelSavePictDirLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_5->addWidget(labelSavePictDirLabel, 2, 0, 1, 1);

        labelCalibFile = new QLabel(widgetSettings);
        labelCalibFile->setObjectName(QStringLiteral("labelCalibFile"));
        labelCalibFile->setMinimumSize(QSize(735, 25));
        labelCalibFile->setMaximumSize(QSize(12000, 25));
        labelCalibFile->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(labelCalibFile, 9, 0, 1, 1);

        pushButtonSelectCalibDir = new QPushButton(widgetSettings);
        pushButtonSelectCalibDir->setObjectName(QStringLiteral("pushButtonSelectCalibDir"));
        pushButtonSelectCalibDir->setMinimumSize(QSize(0, 25));
        pushButtonSelectCalibDir->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(pushButtonSelectCalibDir, 7, 1, 1, 1);

        labelCalibFilesLabel = new QLabel(widgetSettings);
        labelCalibFilesLabel->setObjectName(QStringLiteral("labelCalibFilesLabel"));
        labelCalibFilesLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_5->addWidget(labelCalibFilesLabel, 6, 0, 1, 1);

        labelSaveMovDir = new QLabel(widgetSettings);
        labelSaveMovDir->setObjectName(QStringLiteral("labelSaveMovDir"));
        labelSaveMovDir->setMinimumSize(QSize(735, 25));
        labelSaveMovDir->setMaximumSize(QSize(12000, 25));
        labelSaveMovDir->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(labelSaveMovDir, 5, 0, 1, 1);

        labelCalibFilesDir = new QLabel(widgetSettings);
        labelCalibFilesDir->setObjectName(QStringLiteral("labelCalibFilesDir"));
        labelCalibFilesDir->setMinimumSize(QSize(735, 25));
        labelCalibFilesDir->setMaximumSize(QSize(12000, 25));
        labelCalibFilesDir->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(labelCalibFilesDir, 7, 0, 1, 1);

        labelAlgorithmLabel = new QLabel(widgetSettings);
        labelAlgorithmLabel->setObjectName(QStringLiteral("labelAlgorithmLabel"));
        labelAlgorithmLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_5->addWidget(labelAlgorithmLabel, 10, 0, 1, 1);

        labelSavePictDir = new QLabel(widgetSettings);
        labelSavePictDir->setObjectName(QStringLiteral("labelSavePictDir"));
        labelSavePictDir->setMinimumSize(QSize(735, 25));
        labelSavePictDir->setMaximumSize(QSize(12000, 25));
        labelSavePictDir->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(labelSavePictDir, 3, 0, 1, 1);

        labelSaveMovDirLabel = new QLabel(widgetSettings);
        labelSaveMovDirLabel->setObjectName(QStringLiteral("labelSaveMovDirLabel"));
        labelSaveMovDirLabel->setMaximumSize(QSize(16777215, 25));

        gridLayout_5->addWidget(labelSaveMovDirLabel, 4, 0, 1, 1);

        pushButtonSelectMovDir = new QPushButton(widgetSettings);
        pushButtonSelectMovDir->setObjectName(QStringLiteral("pushButtonSelectMovDir"));
        pushButtonSelectMovDir->setMinimumSize(QSize(0, 25));
        pushButtonSelectMovDir->setMaximumSize(QSize(100, 25));

        gridLayout_5->addWidget(pushButtonSelectMovDir, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);


        retranslateUi(widgetSettings);

        QMetaObject::connectSlotsByName(widgetSettings);
    } // setupUi

    void retranslateUi(QWidget *widgetSettings)
    {
        widgetSettings->setWindowTitle(QApplication::translate("widgetSettings", "Form", nullptr));
        labelRightCameraStatus->setText(QString());
        leftCamera->setText(QString());
        labelLeftCameraStatus->setText(QString());
        rightCamera->setText(QString());
        labelCalibFileLabel->setText(QApplication::translate("widgetSettings", "Plik kalibracyjny", nullptr));
        pushButtonSelectPicDir->setText(QApplication::translate("widgetSettings", "Wybierz...", nullptr));
        comboBoxAlgorithm->setCurrentText(QString());
        pushButtonSelectCalibFile->setText(QApplication::translate("widgetSettings", "Wybierz...", nullptr));
        labelSavePictDirLabel->setText(QApplication::translate("widgetSettings", "Zdj\304\231cia", nullptr));
        labelCalibFile->setText(QString());
        pushButtonSelectCalibDir->setText(QApplication::translate("widgetSettings", "Wybierz...", nullptr));
        labelCalibFilesLabel->setText(QApplication::translate("widgetSettings", "Pliki kalibracyjne", nullptr));
        labelSaveMovDir->setText(QString());
        labelCalibFilesDir->setText(QString());
        labelAlgorithmLabel->setText(QApplication::translate("widgetSettings", "Algorytm estymacji odleg\305\202o\305\233ci", nullptr));
        labelSavePictDir->setText(QString());
        labelSaveMovDirLabel->setText(QApplication::translate("widgetSettings", "Filmy", nullptr));
        pushButtonSelectMovDir->setText(QApplication::translate("widgetSettings", "Wybierz...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetSettings: public Ui_widgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSETTINGS_H
