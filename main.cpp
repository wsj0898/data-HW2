#include <iostream>
#include "que.h"
#include "bt.h"

using namespace std;

int main()
{
	binT<char> tree, tree1('M'), tree2;

	tree.creatTree('@');
	
	cout << "高度：" << tree.height() << endl;
	cout << "规模：" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	cout << endl;

	tree2.makeTree('Y', tree, tree1);
	cout << endl;
	cout << "高度：" << tree2.height() << endl;
	cout << "规模：" << tree2.size() << endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();

	return 0;
}