#include "FiguresScene.h"
#include "Text.h"
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "TextInEllipse.h"
#include <QMouseEvent>
#include <QGraphicsSceneEvent>
#include <stack>
#include "Line.h"

FiguresScene::FiguresScene(QObject *parent)
    : QGraphicsScene(parent) {
    setItemIndexMethod(QGraphicsScene::NoIndex);
}

FiguresScene::~FiguresScene(){
}

void FiguresScene::setFigureType(QString newFigureType) {
     typeFigure = newFigureType;
}

void FiguresScene::setFigureRadius1(int newRadius) {
    if (newRadius <= 0) {
        newRadius = 30;
    }
    radius_1 = newRadius;
}

void FiguresScene::setFigureRadius2(int newRadius) {
    if (newRadius <= 0) {
        newRadius = 40;
    }
    radius_2 = newRadius;
}

void FiguresScene::setFigureFontSize(int fontSz) {
    if (fontSz <= 12)
        fontSz = 12;
    fontSize = fontSz;
}

void FiguresScene::setFigureText(QString newText) {
    if (!newText.size()) {
        newText = "\"\"";
    }
    figureText = newText;
}

QString FiguresScene::getFigureType() const {
    return typeFigure;
}

void FiguresScene::popFigure() {
    try {
//        auto elem_and_parent = figuresContainer.pop();
//        Shape *fig = elem_and_parent.first->elem();
        auto node = figuresContainer.pop();
        Shape *fig = node->elem();
        TreeNode<Shape *> *parentTreeNodeFig = node->getParent();
        if(parentTreeNodeFig)
         {
            if(!(parentTreeNodeFig->right()) && parentTreeNodeFig->getRightLine()){
                this->removeItem(parentTreeNodeFig->getRightLine());
                parentTreeNodeFig->setRightLine(nullptr);
            }
            else if(!(parentTreeNodeFig->left()) && parentTreeNodeFig->getLeftLine()){
                this->removeItem(parentTreeNodeFig->getLeftLine());
                parentTreeNodeFig->setLeftLine(nullptr);
            }
        }
        this->removeItem(fig);
        figuresCount--;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void FiguresScene::clearSFiguresScene() {
    this->clear();
    size_t cont_sz = figuresContainer.size();
    while (cont_sz--) {
        figuresContainer.pop();
    }
}

void FiguresScene::serialize(QDataStream &stream) {
    size_t cont_sz = figuresContainer.size();
    stream << cont_sz;
    while (cont_sz--) {
        Shape *fig = figuresContainer.pop()->elem();
        stream << *fig;
    }
    this->clear();
}

void FiguresScene::deserialize(QDataStream &stream) {
    std::size_t figuresToLoadCount;
    stream >> figuresToLoadCount;
    if (figuresToLoadCount > 0) {
        clearSFiguresScene();
    } else {
        return;
    }
    std::stack<Shape *> st;
    for (size_t i = 0; i < figuresToLoadCount; i++) {
       Shape* figure = Shape::loadFigure(stream);
       figure->setCurrentScene(this);
        if (figure) {
            st.push(figure);
        }
    }
    while(st.size())
    {
        Shape* shape = st.top();
        st.pop();
        figuresCount++;
        nodeType* parent = figuresContainer.push(new nodeType(shape));
        if (parent) {
            this->removeItem(parent->elem());
            if (parent->right()) {
                parent->setRightLine(new Line(parent->elem()->getCentCoords(), shape->getCentCoords()));
                parent->right()->setParent(parent);
                shape->setOwnerNode(parent->right());
                this->addItem(parent->getRightLine());
            }
            else {
                parent->setLeftLine(new Line(parent->elem()->getCentCoords(), shape->getCentCoords()));
                parent->left()->setParent(parent);
                shape->setOwnerNode(parent->left());
                this->addItem(parent->getLeftLine());
            }
            this->addItem(parent->elem());
        }
        else {
            shape->setOwnerNode(figuresContainer.root());
        }
        this->addItem(shape);
    }
}


void FiguresScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    auto item = this->itemAt(event->scenePos(), QTransform::fromScale(1, 1));
    if(!item) {
        auto type = this->getFigureType().toStdString();
        if (type == "text") {
            shape = new Text(event->scenePos().rx(),event->scenePos().ry(),this->figureText, this->fontSize);
        } else if (type == "circle") {
            shape = new Circle(event->scenePos().rx(),event->scenePos().ry(),this->radius_1);
        } else if (type == "ellipse") {
            shape = new Ellipse(event->scenePos().rx(), event->scenePos().ry(), this->radius_1, this->radius_2);
        } else if (type == "textInEllipse") {
            shape = new TextInEllipse(event->scenePos().rx(), event->scenePos().ry(), this->radius_1, this->radius_2, this->figureText, this->fontSize);
        }
        shape->setCurrentScene(this);
        figuresCount++;

        nodeType *parent = figuresContainer.push(new nodeType(shape));

        if (parent){
            this->removeItem(parent->elem());
            if(parent->right()){
                parent->setRightLine(new Line(parent->elem()->getCentCoords(), shape->getCentCoords()));
                parent->right()->setParent(parent);
                shape->setOwnerNode(parent->right());
                this->addItem(parent->getRightLine());
            }
            else {
                parent->setLeftLine(new Line(parent->elem()->getCentCoords(), shape->getCentCoords()));
                parent->left()->setParent(parent);
                shape->setOwnerNode(parent->left());
                this->addItem(parent->getLeftLine());
            }
            this->addItem(parent->elem());
        } else {
            shape->setOwnerNode(figuresContainer.root());
        }

        shape->setPos(event->scenePos());
        this->addItem(shape);

    }
}
