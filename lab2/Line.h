#ifndef LINE_H
#define LINE_H

#include <QGraphicsObject>
#include <Point.h>
#include <Shape.h>

class Line: public QGraphicsObject
{
protected:
    QPoint first, second;
public:
    Line();
    Line(QPoint f, QPoint s);
    QPoint getFirst();
    QPoint getSecond();
    void  setFirst(const Point &p);
    void  setSecond(const Point &p);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // LINE_H
