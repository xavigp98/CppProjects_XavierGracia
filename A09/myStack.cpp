#include "myStack.h"



myStack::myStack()
{
}

myStack::myStack(myStack & in)
{
}

myStack::myStack(int size, int value)
{
	node * transversal = s;
	for (int i = 0; i < size; ++i){
		
	}
}

void myStack::pop()
{
	node * puntero = s;
	s = s->next;
	delete puntero;
	puntero = nullptr;
}

void myStack::push(int l)
{
	node * puntero = new node({ {l},{s} });
	s = puntero;
}

int myStack::top()
{
	return s->info;
}

int myStack::size()
{
	int size;
	node * transversal = s;
	if (s == nullptr) {
		size = 0;
	}
	else {
		size = 1;
		while (transversal->next != nullptr) {
			++size;
			transversal = transversal->next;
		}
	}
	return size;
}


bool myStack::isEmpty()
{
	if (s == nullptr)
		return true;
	else
		return false;
}

myStack::~myStack()
{
}


