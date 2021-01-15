/********************************************************************************
** Form generated from reading UI file 'NanHao_main_candidates.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANHAO_MAIN_CANDIDATES_H
#define UI_NANHAO_MAIN_CANDIDATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NanHao_main_candidates
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *exitBt;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *NanHao_main_candidates)
    {
        if (NanHao_main_candidates->objectName().isEmpty())
            NanHao_main_candidates->setObjectName(QStringLiteral("NanHao_main_candidates"));
        NanHao_main_candidates->resize(788, 477);
        NanHao_main_candidates->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(NanHao_main_candidates);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(NanHao_main_candidates);
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

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(NanHao_main_candidates);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(22);
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 1, 3, 1, 2);

        exitBt = new QPushButton(NanHao_main_candidates);
        exitBt->setObjectName(QStringLiteral("exitBt"));
        sizePolicy.setHeightForWidth(exitBt->sizePolicy().hasHeightForWidth());
        exitBt->setSizePolicy(sizePolicy);
        exitBt->setFont(font1);

        gridLayout->addWidget(exitBt, 3, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 5, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 4, 1, 1);


        retranslateUi(NanHao_main_candidates);
        QObject::connect(exitBt, SIGNAL(clicked()), NanHao_main_candidates, SLOT(returns()));
        QObject::connect(pushButton, SIGNAL(clicked()), NanHao_main_candidates, SLOT(import()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), NanHao_main_candidates, SLOT(import_model()));

        QMetaObject::connectSlotsByName(NanHao_main_candidates);
    } // setupUi

    void retranslateUi(QDialog *NanHao_main_candidates)
    {
        NanHao_main_candidates->setWindowTitle(QApplication::translate("NanHao_main_candidates", "NanHao_main_candidates", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NanHao_main_candidates", "\345\257\274\345\205\245\345\200\231\351\200\211\344\272\272\345\220\215\345\215\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NanHao_main_candidates", "\345\257\274\345\205\245\346\250\241\346\235\277", Q_NULLPTR));
        exitBt->setText(QApplication::translate("NanHao_main_candidates", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NanHao_main_candidates: public Ui_NanHao_main_candidates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANHAO_MAIN_CANDIDATES_H
