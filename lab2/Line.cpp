#include <algorithm>
#include "Line.h"

Line::Line()
{
    first = Point();
    second = Point();
}

Line::Line(QPoint f, QPoint s){
    first = f;
    second = s;
}

QPoint Line::getFirst(){
    return first;
}

QPoint Line::getSecond(){
    return second;
}

void Line::setFirst(const Point &p){
    first = p;
}

void Line::setSecond(const Point &p){
    first = p;
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QColor(0,0,0));     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawLine(first, second);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Line::boundingRect() const {
    return QRectF(QPoint(std::min(first.x(), second.x()), std::min(first.y(), second.y())),
                  QPoint(std::max(first.x(), second.x()), std::max(first.y(), second.y())));
}
