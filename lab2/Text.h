#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "includes.h"
#include "Shape.h"

class Text : virtual public Shape{
public:
    Text(double x = 0, double y = 0, const QString& text = "", int fontSize = 0);
    Text(QDataStream& stream);
    void saveToStream(QDataStream& stream) const override;

    void print(std::ostream& out) override;

protected:
    QString text;
    std::size_t length;
    int fontSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
#endif
