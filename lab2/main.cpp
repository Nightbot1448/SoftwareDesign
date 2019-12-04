#include "mainwindow.h"
#include "includes.h"
#include "Point.h"
#include "Colour.h"
#include "Shape.h"
#include "Text.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
