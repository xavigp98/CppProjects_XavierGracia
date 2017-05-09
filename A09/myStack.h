#pragma once
class myStack
{
	struct node
	{
		int info;
		node* next;
	};
public:
	node* s = nullptr;	//puntero mirando al primer nodo del stack
	myStack();
	myStack(myStack& in);
	myStack(int size, int value);
	void pop();
	void push(int l);
	int top();
	int size();
	bool isEmpty();
	~myStack();
};

