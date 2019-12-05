#ifndef POINT_H
#define POINT_H

#include <QPoint>

class Point {
public:
    Point(): x(0), y(0){}
    Point(double x, double y): x(x),y(y){}
    double x;
    double y;
    operator QPoint() const{ return QPoint(x, y); }
};
#endif
