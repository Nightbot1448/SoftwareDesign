#ifndef SOFTWARE_DESIGN_BINARYTREE_H
#define SOFTWARE_DESIGN_BINARYTREE_H

#include <iostream>
#include <queue>
#include <deque>
#include "TreeNode.h"
#include "EmptyErrorBT.h"

template <typename T>
class BinaryTree {
    T *root_;

    void print_klp_(T *node);
public:
	BinaryTree();
    explicit BinaryTree(T *base);

//	BinaryTreeIterator<T> iterator();

	T* root() const;
    void print_klp();
    void clear(T* node);
    void clear();
    T*  push(T *); //return parent pointer
	T* pop();

    size_t size();

    ~BinaryTree();
};

template <typename T>
BinaryTree<T>::BinaryTree(T *base) {
    if (base != nullptr)
        root_ = base;
    else
        throw EmptyErrorBT("pointer is empty");
}

template <typename T>
BinaryTree<T>::BinaryTree() {
	root_ = nullptr;
}

template <typename T>
T* BinaryTree<T>::root() const { 
	return root_; 
}

template <typename T>
T *BinaryTree<T>::push(T *elem) {
	if (root_) {
		std::queue<T*> current;
		current.push(root_);
		size_t queue_sz = 1;
		while (queue_sz && (queue_sz & (queue_sz - 1)) == 0) {
			std::queue<T*> next;
			while (current.size()) {
				auto el = current.front();
				current.pop();
				if (el->left()) {
					next.push(el->left());
				}
				else { 
					el->left(elem);
                    return el;
				}
				if (el->right()) {
					next.push(el->right());
				}
				else
				{
					el->right(elem);
                    return el;
				}
			}
			queue_sz = next.size();
			current = next;
		}
	}
	else {
		root_ = elem;
        return nullptr;
	}
}

template <typename T>
T* BinaryTree<T>::pop() {
	if (root_) {
		if (root_->left()) {
			std::deque<T*> current;
			current.push_back(root_);
			while (true)
			{
				std::deque<T*> previous;
				previous = current;
				current.clear();
				for (auto el : previous) {
					if (el->left()) {
						current.push_back(el->left());
					}
					if (el->right()) {
						current.push_back(el->right());
					}
				}
				size_t previous_sz = previous.size();
				size_t current_sz = current.size();

				if (current_sz != 2 * previous_sz) {
					if (current_sz % 2) {
						previous[current_sz / 2]->left() = nullptr;
					}
					else {
						previous[current_sz / 2]->right() = nullptr;
					}
					return current.back();
				}
				else if (!(current.front()->left())) {
					previous.back()->right() = nullptr;
					return current.back();
				}
			}
		}
		else {
			auto for_return = root_;
			root_ = nullptr;
			return for_return;
		}
	}
	else
		throw EmptyErrorBT("pop from empty tree");
}

template <typename T>
void BinaryTree<T>::print_klp_(T* node)
{
    std::cout << node->elem() << ' ';
    if (node->left()) {
        print_klp_(node->left());
    }
    if (node->right()) {
        print_klp_(node->right());
    }
}

template <typename T>
void BinaryTree<T>::print_klp()
{
    print_klp_(root_);
}

template <typename T>
size_t BinaryTree<T>::size(){
    if(!root_)
        return 0;
    std::queue<T *> queue_;
    queue_.push(root_);
    size_t count = 0;
    while(queue_.size())
    {
        auto el = queue_.front();
        queue_.pop();
        ++count;
        if(el->left())
            queue_.push(el->left());
        if(el->right())
            queue_.push(el->right());
    }
    return count;
}

template <typename T>
void BinaryTree<T>::clear(T* node)
{
    if (node == nullptr)
        return;
    if (node->left()) {
        clear(node->left());
		auto t = node->left();
		t = nullptr;
    }
    if (node->right()){
        clear(node->right());
		auto t = node->right();
		t = nullptr;
    }
	delete node;
}

template <typename T>
void BinaryTree<T>::clear()
{
	if (root_)
		clear(root_);
	root_ = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
    clear(root_);
	root_ = nullptr;
}

#endif //SOFTWARE_DESIGN_BINARYTREE_H
