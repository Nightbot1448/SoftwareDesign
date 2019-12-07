#include "Shape.h"
#include "Text.h"
#include "Circle.h"
#include "Ellipse.h"
#include "TextInEllipse.h"
#include "Line.h"
#include "EmptyErrorBT.h"
#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QCursor>
#include <stdexcept>

Shape::Shape() {
    cent = Point(0,0);
}

Shape::Shape(double x, double y): cent(x,y), ang(0), col(0,255,255){
    this->setPos(x,y);
}
Shape::Shape(QDataStream& stream) {
    stream >> figureRect;
    QPoint qcent;
    stream >> qcent;
    cent = Point(qcent.x(),qcent.y());
    QPointF pos;
    stream >> pos;
    setPos(pos);
}

void Shape::changePos(double x, double y){
    for(auto& it: pts){
        it.x+=x - cent.x;
        it.y+=y - cent.y;
    }
    this->setPos(x,y);
    cent.x=x;
    cent.y=y;
}

Shape* Shape::loadFigure(QDataStream &stream) {
    QString type;
    stream >> type;

    if (type == "text") {
        return new Text(stream);
    } else if (type == "circle") {
        return new Circle(stream);
    } else if (type == "ellipse") {
        return new Ellipse(stream);
    } else if (type == "textInEllipse") {
        return new TextInEllipse(stream);
    } else {
        throw std::logic_error("Incorrect figure type");
    }
}
Point Shape::getCentCoords() const {
    return cent;
}
QRectF Shape::boundingRect() const {
    return figureRect;
}
Colour Shape::getColour() const{
    return col;
}
void Shape::changeColour(short r, short g, short b){
    col={r,g,b};
}

QGraphicsScene *Shape::getCurrentScene(){
    return parrent_scene_;
}

void Shape::setCurrentScene(QGraphicsScene *sc){
    parrent_scene_ = sc;
}

TreeNode<Shape *> *Shape::getOwnerNode() {
    return owner_node_;
}

void Shape::setOwnerNode(TreeNode<Shape *> *n) {
    owner_node_ = n;
}

void Shape::forPrint(std::ostream& out){
    out<<"Центр. коорд. "<<cent.x<<" "<<cent.y<<std::endl;
    out<<"Угол поворота "<<ang<<std::endl;
    out<<"Точки "<<std::endl;
    int count=0;
    for(const auto& it: pts){
        count++;
        out<<count<<") ("<<it.x<<", "<<it.y<<")\n";
    }
    out<<"Цвет "<<col.r<<" "<<col.g<<" "<<col.b<<std::endl;
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
    this->cent.x = mapToScene(event->pos()).x();
    this->cent.y = mapToScene(event->pos()).y();

}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    TreeNode<Shape*>* node = owner_node_;
    TreeNode<Shape*>* parent = node->getParent();
    if (parent) {
        if (parent->left() == node)
        {
            delete parent->getLeftLine();
            parent->setLeftLine(nullptr);
        }
        else if (parent->right() == node) {
            delete parent->getRightLine();
            parent->setRightLine(nullptr);
        }
        else
            throw ParentChildError("child of parent != node");
    }
    if (node->left())
    {
        delete node->getLeftLine();
        node->setLeftLine(nullptr);
    }
    if (node->right()) {
        delete node->getRightLine();
        node->setRightLine(nullptr);
    }
    Q_UNUSED(event)
}
void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    TreeNode<Shape*>* node = owner_node_;
    TreeNode<Shape*>* parent = node->getParent();
    auto scene = getCurrentScene();
    scene->removeItem(this);
    if (parent) {
        scene->removeItem(parent->elem());
        if (parent->left() == node)
        {
            parent->setLeftLine(new Line(parent->elem()->getCentCoords(), cent));
            scene->addItem(parent->getLeftLine());
        }
        else if (parent->right() == node) {
            parent->setRightLine(new Line(parent->elem()->getCentCoords(), cent));
            scene->addItem(parent->getRightLine());
        }
        else
            throw ParentChildError("child of parent != node");
        scene->addItem(parent->elem());
    }
    auto left_child = node->left();
    auto right_child = node->right();
    if (left_child)
    {
        scene->removeItem(left_child->elem());
        node->setLeftLine(new Line(cent, left_child->elem()->getCentCoords()));
        scene->addItem(node->getLeftLine());
        scene->addItem(left_child->elem());
    }
    if (right_child) {
        scene->removeItem(right_child->elem());
        node->setRightLine(new Line(cent, node->right()->elem()->getCentCoords()));
        scene->addItem(node->getRightLine());
        scene->addItem(right_child->elem());
    }
    scene->addItem(this);
    Q_UNUSED(event)
}

QDataStream& operator<<(QDataStream& stream, const Shape& shape) {
    shape.saveToStream(stream);
    return stream;
}

QDataStream& operator<<(QDataStream& stream, const Shape* shape) {
    shape->saveToStream(stream);
    return stream;
}
