/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *saveAction;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QMdiArea *mdiArea;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QComboBox *chooseObject;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *radius_1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *radius_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *fontSize;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QLineEdit *lineEditText;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearScene;
    QPushButton *newSceneButton;
    QPushButton *deleteButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1146, 760);
        MainWindow->setMinimumSize(QSize(950, 570));
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(919, 0));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        verticalLayout_6->addWidget(mdiArea);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);

        horizontalLayout_8->addWidget(label);

        chooseObject = new QComboBox(centralwidget);
        chooseObject->addItem(QString());
        chooseObject->addItem(QString());
        chooseObject->addItem(QString());
        chooseObject->addItem(QString());
        chooseObject->setObjectName(QString::fromUtf8("chooseObject"));

        horizontalLayout_8->addWidget(chooseObject);


        verticalLayout_10->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        radius_1 = new QLineEdit(centralwidget);
        radius_1->setObjectName(QString::fromUtf8("radius_1"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radius_1->sizePolicy().hasHeightForWidth());
        radius_1->setSizePolicy(sizePolicy);
        radius_1->setMinimumSize(QSize(140, 25));
        radius_1->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_2->addWidget(radius_1);


        verticalLayout_10->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        radius_2 = new QLineEdit(centralwidget);
        radius_2->setObjectName(QString::fromUtf8("radius_2"));
        radius_2->setEnabled(false);
        radius_2->setMinimumSize(QSize(140, 25));
        radius_2->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_6->addWidget(radius_2);


        verticalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        fontSize = new QLineEdit(centralwidget);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));
        fontSize->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontSize->sizePolicy().hasHeightForWidth());
        fontSize->setSizePolicy(sizePolicy1);
        fontSize->setMinimumSize(QSize(140, 25));
        fontSize->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_7->addWidget(fontSize);


        verticalLayout_10->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        lineEditText = new QLineEdit(centralwidget);
        lineEditText->setObjectName(QString::fromUtf8("lineEditText"));
        lineEditText->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEditText->sizePolicy().hasHeightForWidth());
        lineEditText->setSizePolicy(sizePolicy1);
        lineEditText->setMinimumSize(QSize(30, 0));
        lineEditText->setBaseSize(QSize(30, 0));
        lineEditText->setFrame(true);

        horizontalLayout_11->addWidget(lineEditText);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        clearScene = new QPushButton(centralwidget);
        clearScene->setObjectName(QString::fromUtf8("clearScene"));

        horizontalLayout_9->addWidget(clearScene);

        newSceneButton = new QPushButton(centralwidget);
        newSceneButton->setObjectName(QString::fromUtf8("newSceneButton"));
        newSceneButton->setMinimumSize(QSize(0, 25));
        newSceneButton->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_9->addWidget(newSceneButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setMinimumSize(QSize(0, 25));
        deleteButton->setMaximumSize(QSize(140, 16777215));

        horizontalLayout_9->addWidget(deleteButton);


        verticalLayout_10->addLayout(horizontalLayout_9);


        horizontalLayout->addLayout(verticalLayout_10);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1146, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(openAction);
        menu->addAction(saveAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        openAction->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\321\213", nullptr));
        chooseObject->setItemText(0, QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        chooseObject->setItemText(1, QApplication::translate("MainWindow", "\320\255\320\273\320\273\320\270\320\277\321\201", nullptr));
        chooseObject->setItemText(2, QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        chooseObject->setItemText(3, QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202 \320\262 \321\215\320\273\320\273\320\270\320\277\321\201\320\265", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\270/\320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\264\320\270\321\203\321\201 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        radius_1->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\264\320\270\321\203\321\201 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202", nullptr));
        clearScene->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\205\320\265\320\274\321\203", nullptr));
        newSceneButton->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\206\320\265\320\275\320\260", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
