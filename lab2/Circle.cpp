#include "Circle.h"
#include "Shape.h"

Circle::Circle(double x, double y, double r) : Shape(x,y), radius(r){
    figureRect = QRectF(-r, -r, 2*r, 2*r);
}
Circle::Circle(QDataStream &stream)
    : Shape(stream) {
    stream >> radius;
}
void Circle::saveToStream(QDataStream &stream) const {
    stream << QString::fromStdString("circle");
    stream << figureRect;
    stream << QPoint(static_cast<int>(cent.x), static_cast<int>(cent.y));
    stream << scenePos();
    stream << radius;
}

void Circle::print(std::ostream& out){
    out<< "Радиус "<< radius <<"\n";
}

double Circle::getRadius() {
    return radius;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QColor(col.r, col.g, col.b));     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawEllipse(figureRect);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

