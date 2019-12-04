#ifndef FIGURESSCENE_H
#define FIGURESSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include "Shape.h"
#include "BinaryTree.h"
#include <queue>

typedef TreeNode<Shape *> nodeType;

namespace Ui {
class FiguresScene;
}

class FiguresScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit FiguresScene(QObject *parent = nullptr);
    void setFigureType(QString newFigureType);
    void setFigureRadius1(int newRadius);
    void setFigureRadius2(int newRadius);
    void setFigureFontSize(int fontSz);
    void setFigureText(QString newText);
    void popFigure();
    void clearSFiguresScene();
    void serialize(QDataStream& stream);
    void deserialize(QDataStream& stream);
    QString getFigureType() const;
    ~FiguresScene();

private:
    Ui::FiguresScene *ui;
    QGraphicsScene *scene;     // Объявляем графическую сцену
    QString typeFigure = "circle";
    int radius_1 = 100;
    int radius_2 = 80;
    int fontSize = 12;
    QString figureText = "\"\"";
    Shape* shape;
//    std::queue<Shape*> figuresQueue;
    BinaryTree<nodeType> figuresContainer;
    int figuresCount = 0;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // FIGURESSCENE_H
