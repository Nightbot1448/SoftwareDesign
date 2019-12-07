#include "container/BinaryTree.h"
#include "container/BinaryTreeIterator.h"

#include "shapes/Circle.h"
#include "shapes/Ellipse.h"
#include "shapes/Text.h"
#include "shapes/TextInEllipse.h"

//typedef TreeNode<Shape *> nodeType;
typedef TreeNode<int> nodeType;

int main(int argc, char **argv)
{
    /*Shape *shape_0 = new Circle(Point(1,2), 1.5);
    Shape *shape_1 = new Ellipse(Point(1,2), 1, 2);
    Shape *shape_2 = new Text("text", 8);
    Shape *shape_3 = new TextInEllipse("text in ellipse", 8, Point(1, 2), 2, 3);*/
	
    
    try {
		
        BinaryTree<nodeType> tree;
		tree.push(new nodeType(0));
		tree.push(new nodeType(1));
		tree.push(new nodeType(2));
		tree.push(new nodeType(3));
		tree.push(new nodeType(4));
		tree.push(new nodeType(5));
		tree.push(new nodeType(6));
		tree.push(new nodeType(7));
		tree.push(new nodeType(8));
		tree.push(new nodeType(9));

        BinaryTreeIterator<nodeType> iter = tree.iterator();

		size_t sz = tree.size();
		while (sz--) {
			auto el = tree.pop();
			std::cout << el->elem() << std::endl;
		}
		/*el = tree.pop();
		std::cout << std::endl << el->elem() << std::endl;

		iter = tree.iterator();
		while (iter.has_next()) {
			std::cout << iter.next().elem() << ' ';
		}
		el = tree.pop();
		std::cout << std::endl << el->elem() << std::endl;
		
		iter = tree.iterator();
		while (iter.has_next()) {
			std::cout << iter.next().elem() << ' ';
		}

		el = tree.pop();*/

		tree.clear();
		
    }
    catch(EmptyErrorBT &e)
    {
        std::cout << "Exception:" << e.what() << std::endl;
    }
    catch(InvalidIteratorBT &e)
    {
        std::cout << "Exception:" << e.what() << std::endl;
    }
    catch(std::exception &e){
        std::cout << "Exception:" << e.what() << std::endl;
    }

    return 0;
}