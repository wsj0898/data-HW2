﻿//bt.cpp
//Name 吴松骏 Num 5132119049
//2014.10.16 13:51

#ifndef _bt
#define _bt

#include <iostream>
#include "que.h"

using namespace std;

template<class T>
class binT
{
private:
	//二叉树结点类
	struct node
	{
		node *left, *right;
		T data;

		node() :left(NULL), right(NULL){}
		//构造函数
		node(T item, node *l = NULL, node *r = NULL) :data(item), left(l), right(r){}
		~node(){}
	};

	//二叉树根节点
	node *root;

	struct elem
	{
		node *p;
		int num;
	};

public:
	binT() :root(NULL){}
	binT( const T &value )
	{
		root = new node(value);
	}
	~binT()
	{
		clear();
	}

	T getRoot() const
	{
		return root->data;
	}
	T getLeft() const
	{
		return root->lefg->data;
	}
	T getRight() const
	{
		return root->right->data;
	}

	//把2棵树拼成1棵树
	void makeTree(const T &x, binT &lt, binT &rt)
	{
		root = new node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void delLeft()
	{
		binT tmp = root->left;
		root->left = NULL;
		tmp.clear();
	}
	void delRight()
	{
		binT tmp = root->right;
		root->right = NULL;
		tmp.clear();
	}

	bool isEmpty() const
	{
		return root == NULL;
	}

	void clear()
	{
		if (root != NULL)
			clear(root);
		root = NULL;
	}

	int size() const
	{
		return size(root);
	}

	int height() const
	{
		return height(root);
	}

	void preOrder() const
	{
		if (root != NULL)
		{
			cout << "\n前序遍历：";
			preOrder(root);
		}
	}
	void postOrder() const
	{
		if (root != NULL)
		{
			cout << "\n后序遍历：";
			postOrder(root);
		}
	}
	void midOrder() const
	{
		if (root != NULL)
		{
			cout << "\n中序遍历：";
			midOrder(root);
		}
	}

	void creatTree(T flag);

	//层次遍历
	void depthTraverse();

	//判断完全二叉树
	bool isComplettTree();

private:
	int height(node *t) const
	{
		if (t == NULL)
			return 0;
		else
		{
			int lt = height(t->left),
				rt = height(t->right);
			return 1 + ( ( lt > rt ) ? lt : rt );
		}
	}

	void clear(node *t)
	{
		if (t->left != NULL)
			clear(t->left);
		if (t->right != NULL)
			clear(t->right);
		delete t;
	}

	int size(node *t) const
	{
		if (t == NULL)
			return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(node *t) const
	{
		if (t != NULL)
		{
			cout << t->data << " ";
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void postOrder(node *t) const
	{
		if (t != NULL)
		{
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << " ";
		}
	}
	void midOrder(node *t) const
	{
		if (t != NULL)
		{
			midOrder(t->left);
			cout << t->data << " ";
			midOrder(t->right);
		}
	}
};

template<class T>
void binT<T>::creatTree(T flag)
{
	linkQ<node *> que;
	node *tmp;
	T x, ldata, rdata;

	cout << "\n请输入根节点：";
	cin >> x;
	root = new node(x);
	que.enQueue(root);

	while (!que.isEmpty())
	{
		tmp = que.deQueue();
		cout << "\n输入" << tmp->data << "的两个儿子(输入@表示空结点)：";
		cin >> ldata >> rdata;
		if (ldata != '@')
			que.enQueue(tmp->left = new node(ldata));
		if (rdata != '@')
			que.enQueue(tmp->right = new node(rdata));
	}

	cout << "creat completted!\n";
}

template<class T>
void binT<T>::depthTraverse()
{
	linkQ<node *> que;
	node *cur;

	cout << endl << "层次遍历：";
	if (root == NULL)
		return;

	que.enQueue(root);
	while (!que.isEmpty())
	{
		cur = que.deQueue();
		if (cur->left != NULL)
			que.enQueue(cur->left);
		if (cur->right != NULL)
			que.enQueue(cur->right);
		cout << cur->data << ' ';
	}
}

template<class T>
bool binT<T>::isComplettTree()
{

	linkQ<elem> que;
	elem cur, child;
	int count = 1;
	int last = 1;

	if (root == NULL)
		return true;
	cur.p = root;
	cur.num = 1;
	que.enQueue(cur);
	int testPoint = 1;

	while (que.isEmpty() == 0)
	{
		//cout << endl << que.isEmpty() << ' ' << testPoint++;
		cur = que.deQueue();
		//cout << endl << que.isEmpty();
		if (cur.p->left != NULL)
		{
			++count;
			child.p = cur.p->left;
			last = child.num = cur.num * 2;
			que.enQueue(child);
		}
		if (cur.p->right != NULL)
		{
			++count;
			child.p = cur.p->right;
			last = child.num = cur.num * 2 + 1;
			que.enQueue(child);
		}
	}
	return (count==last);
}

#endif //_bt