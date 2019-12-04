#include "TextInEllipse.h"
#include "Shape.h"

TextInEllipse::TextInEllipse(double x, double y, double r_1, double r_2, const QString& newText, int newFontSize) : Shape(x,y) {
    radius_1 = r_1;
    radius_2 = r_2;
    length = text.length();
    text = newText;
    fontSize = newFontSize;
    figureRect = QRectF(-r_1, -r_2, 2*r_1, 2*r_2);
}
TextInEllipse::TextInEllipse(QDataStream &stream) : Shape(stream), Ellipse(stream), Text(stream) {}


void TextInEllipse::saveToStream(QDataStream &stream) const {
    stream << QString::fromStdString("textInEllipse");
    stream << figureRect;
    stream << QPoint(static_cast<int>(cent.x), static_cast<int>(cent.y));
    stream << scenePos();
    stream << radius_1;
    stream << radius_2;
    stream << text;
    stream << fontSize;
}

void TextInEllipse::print(std::ostream& out){
    out<< "Радиус 1 "<< radius_1 << "; Радиус 2: "<< radius_2 << "\n";
    out<< "Длина текста "<< length <<"\n";
    out<< "Размер шрифта "<< fontSize<<"\n";
    out<< "Текст "<< text.toStdString() <<"\n";
}
void TextInEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QColor(col.r, col.g, col.b));
    painter->drawEllipse(figureRect);
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    auto font = painter->font();
    font.setPointSize(fontSize);
    painter->setFont(font);
    painter->drawText(figureRect, Qt::AlignCenter, text);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

