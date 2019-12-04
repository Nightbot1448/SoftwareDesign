#include "Ellipse.h"
#include "Shape.h"

Ellipse::Ellipse(double x, double y, double r_1, double r_2) : Shape(x,y), radius_1(r_1), radius_2(r_2) {
    figureRect = QRectF(-r_1, -r_2, 2*r_1, 2*r_2);
}
Ellipse::Ellipse(QDataStream &stream)
    : Shape(stream) {
    stream >> radius_1 >> radius_2;
}
void Ellipse::saveToStream(QDataStream &stream) const {
    stream << QString("ellipse");
    stream << figureRect;
    stream << QPoint(static_cast<int>(cent.x), static_cast<int>(cent.y));
    stream << scenePos();
    stream << radius_1;
    stream << radius_2;
}

void Ellipse::print(std::ostream& out){
    out<< "Радиус 1 "<< radius_1 << "; Радиус 2: "<< radius_2 << "\n";
}

double Ellipse::getRadius1() {
    return radius_2;
}

double Ellipse::getRadius2() {
    return radius_1;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QColor(col.r, col.g, col.b));     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawEllipse(figureRect);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

