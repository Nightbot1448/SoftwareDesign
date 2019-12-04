#include "Text.h"

Text::Text(double x, double y, const QString& text, int fontSize) : Shape(x,y), text(text), fontSize(fontSize){
    length = text.length();
    figureRect = QRectF(-10/1.5,-10/2, (10*1.2)*(fontSize/12)*length, 30*(fontSize/12));
}
Text::Text(QDataStream &stream)
    : Shape(stream) {
    QString qtext;
    stream >> qtext;
    text = qtext;
    stream >> fontSize;
    length = text.length();
}
void Text::saveToStream(QDataStream &stream) const {
    stream << QString::fromStdString("text");
    stream << figureRect;
    stream << QPoint(cent.x, cent.y);
    stream << scenePos();
    stream << text;
    stream << fontSize;
}
void Text::print(std::ostream& out){
    out<<"Длина текста "<< length<<"\n";
    out<<"Размер шрифта "<< fontSize<<"\n";
    out<<"Текст "<< text.toStdString() <<"\n";
}
void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setBrush(QColor(col.r, col.g, col.b));
    auto font = painter->font();
    font.setPointSize(fontSize);
    painter->setFont(font);
    painter->drawText(figureRect, text);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}
