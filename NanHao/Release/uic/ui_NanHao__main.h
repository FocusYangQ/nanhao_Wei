/********************************************************************************
** Form generated from reading UI file 'NanHao__main.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANHAO__MAIN_H
#define UI_NANHAO__MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NanHao__main
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *scanBt;
    QSpacerItem *verticalSpacer_12;
    QPushButton *exitBt;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_14;

    void setupUi(QWidget *NanHao__main)
    {
        if (NanHao__main->objectName().isEmpty())
            NanHao__main->setObjectName(QStringLiteral("NanHao__main"));
        NanHao__main->resize(800, 450);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NanHao__main->sizePolicy().hasHeightForWidth());
        NanHao__main->setSizePolicy(sizePolicy);
        NanHao__main->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(NanHao__main);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 2, 0, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 9, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 6, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 1, 2, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 1, 5, 1, 1);

        pushButton_2 = new QPushButton(NanHao__main);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(24);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 2, 7, 1, 2);

        pushButton = new QPushButton(NanHao__main);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 2, 2, 1, 2);

        scanBt = new QPushButton(NanHao__main);
        scanBt->setObjectName(QStringLiteral("scanBt"));
        sizePolicy.setHeightForWidth(scanBt->sizePolicy().hasHeightForWidth());
        scanBt->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setWeight(50);
        scanBt->setFont(font1);

        gridLayout->addWidget(scanBt, 2, 5, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_12, 4, 9, 1, 1);

        exitBt = new QPushButton(NanHao__main);
        exitBt->setObjectName(QStringLiteral("exitBt"));
        sizePolicy.setHeightForWidth(exitBt->sizePolicy().hasHeightForWidth());
        exitBt->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font2.setPointSize(22);
        exitBt->setFont(font2);

        gridLayout->addWidget(exitBt, 4, 8, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 52, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 8, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 1, 7, 1, 2);


        retranslateUi(NanHao__main);
        QObject::connect(pushButton, SIGNAL(clicked()), NanHao__main, SLOT(candidate()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), NanHao__main, SLOT(statistics()));
        QObject::connect(exitBt, SIGNAL(clicked()), NanHao__main, SLOT(exit()));
        QObject::connect(scanBt, SIGNAL(clicked()), NanHao__main, SLOT(votes()));

        QMetaObject::connectSlotsByName(NanHao__main);
    } // setupUi

    void retranslateUi(QWidget *NanHao__main)
    {
        NanHao__main->setWindowTitle(QApplication::translate("NanHao__main", "NanHao__main", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NanHao__main", "\347\273\237\350\256\241", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NanHao__main", "\345\200\231\351\200\211\344\272\272", Q_NULLPTR));
        scanBt->setText(QApplication::translate("NanHao__main", "\350\256\241\347\245\250", Q_NULLPTR));
        exitBt->setText(QApplication::translate("NanHao__main", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NanHao__main: public Ui_NanHao__main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANHAO__MAIN_H
