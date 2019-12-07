#ifndef SHAPE_H
#define SHAPE_H
#include <QDataStream>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include "includes.h"
#include "TreeNode.h"

class FiguresScene;

class Shape: public QGraphicsObject{
    friend class FiguresScene;
public:
    Shape();
    Shape(double x, double y);
    Shape(QDataStream& stream);
    static Shape* loadFigure(QDataStream& stream);
    virtual void changePos(double x, double y);
    void virtual saveToStream(QDataStream& stream) const = 0;

    virtual void forPrint(std::ostream& out);
    virtual void changeColour(short r, short g, short b);
    Point getCentCoords() const;
    Colour getColour() const;
    virtual void print(std::ostream& out) = 0;

    QGraphicsScene *getCurrentScene();
    void setCurrentScene(QGraphicsScene *);

    TreeNode<Shape *> *getOwnerNode();
    void setOwnerNode(TreeNode<Shape *> *n);

    friend std::ostream& operator<<(std::ostream& out, Shape& sh){
        sh.forPrint(out);
        sh.print(out);
        return out;
    }
    virtual ~Shape(){}

protected:
    Point cent;
    int ang = 0;
    Colour col = Colour(0,255,255);
    std:: vector<Point> pts;
    QRectF figureRect;
    QRectF boundingRect() const override;

    TreeNode<Shape *> *owner_node_;
    QGraphicsScene *parrent_scene_;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};
QDataStream& operator<<(QDataStream& stream, const Shape& shape);
QDataStream& operator<<(QDataStream& stream, const Shape* shape);
#endif
