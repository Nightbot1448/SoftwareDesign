/********************************************************************************
** Form generated from reading UI file 'figuresscene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGURESSCENE_H
#define UI_FIGURESSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "shapeview.h"

QT_BEGIN_NAMESPACE

class Ui_FiguresSceneMdi
{
public:
    QGridLayout *gridLayout_2;
    ShapeView *graphicsView;

    void setupUi(QWidget *FiguresSceneMdi)
    {
        if (FiguresSceneMdi->objectName().isEmpty())
            FiguresSceneMdi->setObjectName(QString::fromUtf8("FiguresSceneMdi"));
        FiguresSceneMdi->setEnabled(true);
        FiguresSceneMdi->resize(280, 287);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FiguresSceneMdi->sizePolicy().hasHeightForWidth());
        FiguresSceneMdi->setSizePolicy(sizePolicy);
        FiguresSceneMdi->setMinimumSize(QSize(200, 200));
        FiguresSceneMdi->setMaximumSize(QSize(2100, 2100));
        FiguresSceneMdi->setSizeIncrement(QSize(1, 1));
        FiguresSceneMdi->setBaseSize(QSize(320, 320));
        gridLayout_2 = new QGridLayout(FiguresSceneMdi);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new ShapeView(FiguresSceneMdi);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setMinimumSize(QSize(180, 180));
        graphicsView->setMaximumSize(QSize(2080, 2080));
        graphicsView->setSizeIncrement(QSize(1, 1));
        graphicsView->setBaseSize(QSize(300, 300));
        graphicsView->setDragMode(QGraphicsView::NoDrag);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(FiguresSceneMdi);

        QMetaObject::connectSlotsByName(FiguresSceneMdi);
    } // setupUi

    void retranslateUi(QWidget *FiguresSceneMdi)
    {
        FiguresSceneMdi->setWindowTitle(QApplication::translate("FiguresSceneMdi", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiguresSceneMdi: public Ui_FiguresSceneMdi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGURESSCENE_H
