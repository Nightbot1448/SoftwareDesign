#include "FiguresSceneMDI.h"
#include "ui_figuresscene.h"
#include "ShapeView.h"
#include "Text.h"

FiguresSceneMdi::FiguresSceneMdi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiguresSceneMdi)
{
    ui->setupUi(this);
    figureScene = new FiguresScene(this);
    ui->graphicsView->setScene(figureScene);
}

FiguresSceneMdi::~FiguresSceneMdi()
{
    delete ui;
}
