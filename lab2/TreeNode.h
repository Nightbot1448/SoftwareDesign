#ifndef SOFTWARE_DESIGN_TREENODE_H
#define SOFTWARE_DESIGN_TREENODE_H

#include <utility>
#include <QGraphicsObject>

template<typename T>
class TreeNode{
    T elem_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode *parent_;
    QGraphicsObject *left_line_;
    QGraphicsObject *right_line_;
public:
	
    explicit TreeNode(T base);
    TreeNode(T base, TreeNode *elem, bool is_right = false);
    TreeNode(T base, TreeNode* left, TreeNode* right);

	
    T &elem();
    const T &elem() const;
    void elem(T base);

    TreeNode *&left();
    void left(T left);
    void left(TreeNode *left);

    TreeNode *getParent();
    void setParent(TreeNode *);

    QGraphicsObject *getLeftLine();
    void setLeftLine(QGraphicsObject *);

    QGraphicsObject *getRightLine();
    void setRightLine(QGraphicsObject *);

    TreeNode *&right();
    void right(T right);
    void right(TreeNode *right);
     ~TreeNode();
};

template<typename T>
TreeNode<T>::TreeNode(T base) : elem_(base), left_(nullptr), right_(nullptr), parent_(nullptr), left_line_(nullptr), right_line_(nullptr){}

template<typename T>
TreeNode<T>::TreeNode(T base, TreeNode* left, TreeNode* right) : elem_(base), left_(left), right_(right), parent_(nullptr), left_line_(nullptr), right_line_(nullptr){}

template<typename T>
TreeNode<T>::TreeNode(T base, TreeNode *elem, bool is_right) : elem_(base), parent_(nullptr), left_line_(nullptr), right_line_(nullptr) {
    if (is_right)
    {
        left_ = nullptr;
        right_ = elem;
    }
    else
    {
        left_ = elem;
        right_ = nullptr;
    }
}

template<typename T>
T &TreeNode<T>::elem() { return elem_; }

template<typename T>
const T &TreeNode<T>::elem() const { return elem_; }

template<typename T>
void TreeNode<T>::elem(T base) { elem_ = base; }

template<typename T>
TreeNode<T> *&TreeNode<T>::left() { return left_; }

template<typename T>
void TreeNode<T>::left(T left) { left_ = new TreeNode<T>(left); }

template<typename T>
void TreeNode<T>::left(TreeNode *left) { left_ = left;}

template<typename T>
TreeNode<T> *&TreeNode<T>::right() { return right_; }

template<typename T>
void TreeNode<T>::right(T right) { right_ = new TreeNode<T>(right); }

template<typename T>
void TreeNode<T>::right(TreeNode *right) { right_ = right; }

template<typename T>
QGraphicsObject *TreeNode<T>::getLeftLine(){
    return left_line_;
}

template<typename T>
void TreeNode<T>::setLeftLine(QGraphicsObject *l){
    left_line_ = l;
}

template<typename T>
QGraphicsObject *TreeNode<T>::getRightLine(){
    return right_line_;
}

template<typename T>
TreeNode<T> *TreeNode<T>::getParent(){
    return parent_;
}
template<typename T>
void TreeNode<T>::setParent(TreeNode *p){
    parent_ = p;
}

template<typename T>
void TreeNode<T>::setRightLine(QGraphicsObject *l){
    right_line_ = l;
}

template<typename T>
TreeNode<T>::~TreeNode() {}

#endif //SOFTWARE_DESIGN_TREENODE_H
