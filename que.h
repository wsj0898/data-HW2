//main.cpp
//Name 吴松骏 Num 5132119049
//2014.10.19 2:22

#ifndef _linkq
#define _linkq
//#include <iostream>
//using namespace std;

template<class TT>
class linkQ
{
private:
	struct node
	{
		TT data;
		node *next;

		node(const TT &x, node *n = NULL)
		{
			data = x;
			next = n;
		}
		node() :next (NULL){}
		~node(){}
	};

	node *front, *rear;

public:
	linkQ()
	{
		front = rear = NULL;
		//rear->next = NULL;
	}
	~linkQ();

	bool isEmpty()
	{
		//cout << "emptu" << (front == NULL);
		return rear == NULL;
	}

	void enQueue(const TT &x);
	TT deQueue();
	TT getHead()
	{
		return front->data;
	}
};

template<class TT>
linkQ<TT>::~linkQ()
{
	node *tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

template<class TT>
void linkQ<TT>::enQueue(const TT &x)
{
	if (rear == NULL)
		front = rear = new node(x);
	else
	{
		rear->next = new node(x);
		rear = rear->next;
	}
}

template<class TT>
TT linkQ<TT>::deQueue()
{
	node *tmp = front;
	TT value = front->data;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete tmp;
	return value;
}
#endif //_linkq