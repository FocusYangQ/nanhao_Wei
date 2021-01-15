/********************************************************************************
** Form generated from reading UI file 'NanHao_main_statistics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANHAO_MAIN_STATISTICS_H
#define UI_NANHAO_MAIN_STATISTICS_H

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

class Ui_NanHao_main_statistics
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QTableView *votesTv;
    QSpacerItem *horizontalSpacer_2;
    QTableView *sortTv;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QPushButton *exitBt;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *NanHao_main_statistics)
    {
        if (NanHao_main_statistics->objectName().isEmpty())
            NanHao_main_statistics->setObjectName(QStringLiteral("NanHao_main_statistics"));
        NanHao_main_statistics->resize(822, 450);
        NanHao_main_statistics->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(NanHao_main_statistics);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        votesTv = new QTableView(NanHao_main_statistics);
        votesTv->setObjectName(QStringLiteral("votesTv"));

        gridLayout->addWidget(votesTv, 1, 1, 5, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        sortTv = new QTableView(NanHao_main_statistics);
        sortTv->setObjectName(QStringLiteral("sortTv"));

        gridLayout->addWidget(sortTv, 1, 3, 5, 1);

        verticalSpacer_5 = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 1, 4, 1, 1);

        pushButton_2 = new QPushButton(NanHao_main_statistics);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(22);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 1, 5, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 5, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 3, 4, 1, 1);

        pushButton_3 = new QPushButton(NanHao_main_statistics);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 3, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 5, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 4, 1, 1);

        exitBt = new QPushButton(NanHao_main_statistics);
        exitBt->setObjectName(QStringLiteral("exitBt"));
        sizePolicy.setHeightForWidth(exitBt->sizePolicy().hasHeightForWidth());
        exitBt->setSizePolicy(sizePolicy);
        exitBt->setFont(font);

        gridLayout->addWidget(exitBt, 5, 5, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 6, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(11, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 7, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(249, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 7, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(9, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 7, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(249, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 7, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(23, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 7, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(213, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 7, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(12, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 7, 6, 1, 1);


        retranslateUi(NanHao_main_statistics);
        QObject::connect(pushButton_2, SIGNAL(clicked()), NanHao_main_statistics, SLOT(result()));
        QObject::connect(exitBt, SIGNAL(clicked()), NanHao_main_statistics, SLOT(back()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), NanHao_main_statistics, SLOT(txt_export()));

        QMetaObject::connectSlotsByName(NanHao_main_statistics);
    } // setupUi

    void retranslateUi(QDialog *NanHao_main_statistics)
    {
        NanHao_main_statistics->setWindowTitle(QApplication::translate("NanHao_main_statistics", "NanHao_main_statistics", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NanHao_main_statistics", "\347\273\237\350\256\241\347\273\223\346\236\234", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("NanHao_main_statistics", "\345\257\274\345\207\272\347\273\223\346\236\234", Q_NULLPTR));
        exitBt->setText(QApplication::translate("NanHao_main_statistics", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NanHao_main_statistics: public Ui_NanHao_main_statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANHAO_MAIN_STATISTICS_H
