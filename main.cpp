#include <iostream>
#include "que.h"
#include "bt.h"

using namespace std;

int main()
{
	binT<char> tree, tree1('M'), tree2;

	tree.creatTree('@');
	
	cout << "�߶ȣ�" << tree.height() << endl;
	cout << "��ģ��" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	cout << endl;

	tree2.makeTree('Y', tree, tree1);
	cout << endl;
	cout << "�߶ȣ�" << tree2.height() << endl;
	cout << "��ģ��" << tree2.size() << endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();

	return 0;
}