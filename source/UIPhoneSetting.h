/********************************************************************************
** Form generated from reading UI file 'phonesettingp18048.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PHONESETTINGP18048_H
#define PHONESETTINGP18048_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneSetting
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *tab_2;
    QGroupBox *ScaleGroupBox;
    QSlider *ScaleSlider;
    QLabel *label_3;
    QSlider *PositionY;
    QLabel *label_4;
    QSlider *PositionX;
    QLabel *label_5;
    QPushButton *OK;
    QPushButton *Cancel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Height;
    QLineEdit *Width;

    void setupUi(QWidget *PhoneSetting)
    {
        if (PhoneSetting->objectName().isEmpty())
            PhoneSetting->setObjectName(QStringLiteral("PhoneSetting"));
        PhoneSetting->setWindowModality(Qt::ApplicationModal);
        PhoneSetting->resize(544, 353);
        tabWidget = new QTabWidget(PhoneSetting);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 531, 341));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 120, 80));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 91, 21));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 89, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ScaleGroupBox = new QGroupBox(tab_2);
        ScaleGroupBox->setObjectName(QStringLiteral("ScaleGroupBox"));
        ScaleGroupBox->setGeometry(QRect(10, 10, 501, 301));
        ScaleSlider = new QSlider(ScaleGroupBox);
        ScaleSlider->setObjectName(QStringLiteral("ScaleSlider"));
        ScaleSlider->setGeometry(QRect(50, 30, 241, 20));
        ScaleSlider->setMaximum(10000);
        ScaleSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(ScaleGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 41, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        label_3->setFont(font);
        PositionY = new QSlider(ScaleGroupBox);
        PositionY->setObjectName(QStringLiteral("PositionY"));
        PositionY->setGeometry(QRect(50, 90, 241, 20));
        PositionY->setMaximum(5000);
        PositionY->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(ScaleGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 21, 20));
        label_4->setFont(font);
        PositionX = new QSlider(ScaleGroupBox);
        PositionX->setObjectName(QStringLiteral("PositionX"));
        PositionX->setGeometry(QRect(50, 60, 241, 19));
        PositionX->setMaximum(5000);
        PositionX->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(ScaleGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 21, 16));
        label_5->setFont(font);
        OK = new QPushButton(ScaleGroupBox);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(310, 120, 75, 23));
        Cancel = new QPushButton(ScaleGroupBox);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(410, 120, 75, 23));
        label = new QLabel(ScaleGroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 60, 41, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label_2 = new QLabel(ScaleGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 90, 41, 16));
        label_2->setFont(font);
        Height = new QLineEdit(ScaleGroupBox);
        Height->setObjectName(QStringLiteral("Height"));
        Height->setGeometry(QRect(370, 90, 113, 20));
        Width = new QLineEdit(ScaleGroupBox);
        Width->setObjectName(QStringLiteral("Width"));
        Width->setGeometry(QRect(370, 60, 113, 20));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(PhoneSetting);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PhoneSetting);
    } // setupUi

    void retranslateUi(QWidget *PhoneSetting)
    {
        PhoneSetting->setWindowTitle(QApplication::translate("PhoneSetting", "\346\211\213\346\234\272\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("PhoneSetting", "\346\211\213\346\234\272\346\226\271\345\220\221", 0));
        radioButton->setText(QApplication::translate("PhoneSetting", "\346\250\252\345\220\221", 0));
        radioButton_2->setText(QApplication::translate("PhoneSetting", "\347\272\265\345\220\221", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PhoneSetting", "\346\270\262\346\237\223\344\275\215\347\275\256", 0));
        ScaleGroupBox->setTitle(QApplication::translate("PhoneSetting", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("PhoneSetting", "Scale", 0));
        label_4->setText(QApplication::translate("PhoneSetting", "Y", 0));
        label_5->setText(QApplication::translate("PhoneSetting", "X", 0));
        OK->setText(QApplication::translate("PhoneSetting", "\347\241\256\345\256\232", 0));
        Cancel->setText(QApplication::translate("PhoneSetting", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("PhoneSetting", "Width", 0));
        label_2->setText(QApplication::translate("PhoneSetting", "Height", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PhoneSetting", "\345\210\206\350\276\250\347\216\207", 0));
    } // retranslateUi

};

namespace Ui {
    class PhoneSetting: public Ui_PhoneSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PHONESETTINGP18048_H
