#ifndef TEXT_IN_ELLIPSE_H
#define TEXT_IN_ELLIPSE_H
#include "Ellipse.h"
#include "Text.h"

class TextInEllipse : virtual public Ellipse, virtual public Text{
public:
    TextInEllipse(double x = 0, double y = 0, double r_1 = 0, double r_2 = 0, const QString& newText = "", int newFontSize = 0);
    TextInEllipse(QDataStream& stream);
    void saveToStream(QDataStream& stream) const override;
    void print(std::ostream& out) override;
protected:
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TEXT_IN_ELLIPSE_H
