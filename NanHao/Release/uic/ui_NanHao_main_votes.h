/********************************************************************************
** Form generated from reading UI file 'NanHao_main_votes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANHAO_MAIN_VOTES_H
#define UI_NANHAO_MAIN_VOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_NanHao_main_votes
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exitBt_2;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QPushButton *exitBt;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_10;
    QTableView *listTv;

    void setupUi(QDialog *NanHao_main_votes)
    {
        if (NanHao_main_votes->objectName().isEmpty())
            NanHao_main_votes->setObjectName(QStringLiteral("NanHao_main_votes"));
        NanHao_main_votes->resize(800, 450);
        NanHao_main_votes->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(NanHao_main_votes);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(23, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(502, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 2, 1);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 4, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 6, 2, 1);

        pushButton = new QPushButton(NanHao_main_votes);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(24);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 2, 3, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 6, 1, 1);

        exitBt_2 = new QPushButton(NanHao_main_votes);
        exitBt_2->setObjectName(QStringLiteral("exitBt_2"));
        sizePolicy.setHeightForWidth(exitBt_2->sizePolicy().hasHeightForWidth());
        exitBt_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(28);
        exitBt_2->setFont(font1);

        gridLayout->addWidget(exitBt_2, 6, 3, 1, 3);

        verticalSpacer_6 = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 9, 6, 1, 1);

        pushButton_2 = new QPushButton(NanHao_main_votes);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 4, 3, 1, 3);

        verticalSpacer_8 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 5, 6, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 7, 6, 1, 1);

        exitBt = new QPushButton(NanHao_main_votes);
        exitBt->setObjectName(QStringLiteral("exitBt"));
        sizePolicy.setHeightForWidth(exitBt->sizePolicy().hasHeightForWidth());
        exitBt->setSizePolicy(sizePolicy);
        exitBt->setFont(font1);

        gridLayout->addWidget(exitBt, 8, 3, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 6, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 6, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 6, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 3, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_10, 9, 1, 1, 1);

        listTv = new QTableView(NanHao_main_votes);
        listTv->setObjectName(QStringLiteral("listTv"));

        gridLayout->addWidget(listTv, 2, 1, 7, 1);


        retranslateUi(NanHao_main_votes);
        QObject::connect(exitBt, SIGNAL(clicked()), NanHao_main_votes, SLOT(returns()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), NanHao_main_votes, SLOT(scan()));
        QObject::connect(pushButton, SIGNAL(clicked()), NanHao_main_votes, SLOT(setting_scanner()));
        QObject::connect(exitBt_2, SIGNAL(clicked()), NanHao_main_votes, SLOT(clear()));

        QMetaObject::connectSlotsByName(NanHao_main_votes);
    } // setupUi

    void retranslateUi(QDialog *NanHao_main_votes)
    {
        NanHao_main_votes->setWindowTitle(QApplication::translate("NanHao_main_votes", "NanHao_main_votes", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NanHao_main_votes", "\350\256\276\347\275\256\346\211\253\346\217\217\344\273\252", Q_NULLPTR));
        exitBt_2->setText(QApplication::translate("NanHao_main_votes", "\346\270\205\347\251\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NanHao_main_votes", "\345\274\200\345\247\213\350\256\241\347\245\250", Q_NULLPTR));
        exitBt->setText(QApplication::translate("NanHao_main_votes", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NanHao_main_votes: public Ui_NanHao_main_votes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANHAO_MAIN_VOTES_H
