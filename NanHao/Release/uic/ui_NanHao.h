/********************************************************************************
** Form generated from reading UI file 'NanHao.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANHAO_H
#define UI_NANHAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NanHaoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *userEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLineEdit *passEdit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerBt;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *loginBt;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NanHaoClass)
    {
        if (NanHaoClass->objectName().isEmpty())
            NanHaoClass->setObjectName(QStringLiteral("NanHaoClass"));
        NanHaoClass->resize(800, 450);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NanHaoClass->sizePolicy().hasHeightForWidth());
        NanHaoClass->setSizePolicy(sizePolicy);
        NanHaoClass->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(NanHaoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 0, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(781, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 0, 1, 7);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(48);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 7);

        horizontalSpacer_8 = new QSpacerItem(1001, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 0, 1, 7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 0, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(18);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_2, 5, 2, 1, 1);

        userEdit = new QLineEdit(centralWidget);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        sizePolicy.setHeightForWidth(userEdit->sizePolicy().hasHeightForWidth());
        userEdit->setSizePolicy(sizePolicy);
        userEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(userEdit, 5, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(270, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 4, 1, 3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 6, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 7, 0, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_3, 7, 2, 1, 1);

        passEdit = new QLineEdit(centralWidget);
        passEdit->setObjectName(QStringLiteral("passEdit"));
        sizePolicy.setHeightForWidth(passEdit->sizePolicy().hasHeightForWidth());
        passEdit->setSizePolicy(sizePolicy);
        passEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passEdit, 7, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(270, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 7, 4, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 8, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 8, 4, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 8, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 9, 0, 1, 1);

        registerBt = new QPushButton(centralWidget);
        registerBt->setObjectName(QStringLiteral("registerBt"));
        sizePolicy.setHeightForWidth(registerBt->sizePolicy().hasHeightForWidth());
        registerBt->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(14);
        registerBt->setFont(font2);

        gridLayout->addWidget(registerBt, 9, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(277, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 9, 2, 1, 3);

        loginBt = new QPushButton(centralWidget);
        loginBt->setObjectName(QStringLiteral("loginBt"));
        sizePolicy.setHeightForWidth(loginBt->sizePolicy().hasHeightForWidth());
        loginBt->setSizePolicy(sizePolicy);
        loginBt->setFont(font2);

        gridLayout->addWidget(loginBt, 9, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 9, 6, 1, 1);

        NanHaoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NanHaoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        NanHaoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NanHaoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NanHaoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NanHaoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NanHaoClass->setStatusBar(statusBar);

        retranslateUi(NanHaoClass);
        QObject::connect(loginBt, SIGNAL(clicked()), NanHaoClass, SLOT(on_loginBt_clicked()));

        QMetaObject::connectSlotsByName(NanHaoClass);
    } // setupUi

    void retranslateUi(QMainWindow *NanHaoClass)
    {
        NanHaoClass->setWindowTitle(QApplication::translate("NanHaoClass", "NanHao", Q_NULLPTR));
        label->setText(QApplication::translate("NanHaoClass", "\346\254\242\350\277\216\347\231\273\345\275\225\345\215\227\346\230\212\351\200\211\344\270\276\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("NanHaoClass", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userEdit->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("NanHaoClass", "\345\257\206\347\240\201", Q_NULLPTR));
        passEdit->setPlaceholderText(QString());
        registerBt->setText(QApplication::translate("NanHaoClass", "\346\263\250\345\206\214", Q_NULLPTR));
        loginBt->setText(QApplication::translate("NanHaoClass", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NanHaoClass: public Ui_NanHaoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANHAO_H
