#pragma once
#include <iostream>
#include <list> 
class myList
{
private:
	struct node
	{
		int info;
		node* next, *previous;
	};
	node* last, *first;
public:
	myList();
	myList(myList& in);
	void push_front(int value);
	void pop_front();
	void pop_back();
	~myList();
};

