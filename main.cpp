//main.cpp
//Name 吴松骏 Num 5132119049
//2014.10.19 2:22

#include <iostream>
#include "que.h"
#include "bt.h"

using namespace std;

int main()
{
/*
	linkQ<char> myque;
	myque.enQueue('a');
	myque.enQueue('b');
	myque.enQueue('c');
	myque.enQueue('d');
	myque.enQueue('e');

	cout << myque.deQueue() << " ";
	cout << myque.deQueue() << " ";
	cout << myque.deQueue() << " ";
	cout << myque.deQueue() << " ";
	cout << endl << myque.isEmpty();
	cout << myque.deQueue() << " ";
	cout << endl << myque.isEmpty();
*/


	binT<char> tree, tree1('M'), tree2;

	tree.creatTree('@');
	
	cout << "高度：" << tree.height() << endl;
	cout << "规模：" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.depthTraverse();
	cout << endl << "1表示完全二叉树，0表示非完全二叉树：" << tree.isComplettTree() << endl;
	cout << endl;

	tree2.makeTree('Y', tree, tree1);
	cout << endl;
	cout << "高度：" << tree2.height() << endl;
	cout << "规模：" << tree2.size() << endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();
	tree2.depthTraverse();
	cout << endl << "1表示完全二叉树，0表示非完全二叉树：" << tree2.isComplettTree() << endl;

	return 0;
}