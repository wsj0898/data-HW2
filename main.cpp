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
	
	cout << "�߶ȣ�" << tree.height() << endl;
	cout << "��ģ��" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.depthTraverse();
	tree.isComplettTree();
	cout << endl;

	tree2.makeTree('Y', tree, tree1);
	cout << endl;
	cout << "�߶ȣ�" << tree2.height() << endl;
	cout << "��ģ��" << tree2.size() << endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();
	tree.depthTraverse();
	tree.isComplettTree();

	return 0;
}