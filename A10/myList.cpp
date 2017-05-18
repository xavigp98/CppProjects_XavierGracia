#include "myList.h"



myList::myList()
{
	first = nullptr;
	last = first;
}

myList::myList( myList& in)
{
	node* manterior=nullptr, *mactual=nullptr,*msiguiente=nullptr,*ianterior=nullptr,*iactual=nullptr,*isiguiente=nullptr;
	int c = 0;
	iactual = in.first;
	while (iactual != in.last) {
		if (c < 1) {
			first = new node{ iactual->info,nullptr,nullptr };
			manterior = first;
			iactual = iactual->next;
			c++;
		}
		else {
			mactual = new node{ iactual->info,nullptr,manterior };
			manterior->next = mactual;
			iactual = iactual->next;
			manterior = mactual;
		}
	}
	
	last = new node{ in.last->info,nullptr,mactual };
	mactual->next = last;
}

void myList::push_front(int value)
{
	if (last == first && first == nullptr) {
		node * buffer = new node{ value,first,nullptr };
		first = buffer;
		last = first;
	}
	else {
		node * buffer = new node{ value,first,nullptr };
		first->previous = buffer;
		first = buffer;
	}
}

void myList::pop_front()
{
	if (last == first) {
		last = nullptr;
		first = nullptr;
		last = first;
	}
	else {
		node* aux = first->next;
		first = nullptr;
		first = aux;
		first->previous = nullptr;
	}
}

void myList::pop_back()
{

	if (last == first) {
		last = nullptr;
		first = nullptr;
		last = first;
	}
	else {
		node*aux = last->previous;
		last = nullptr;
		last = aux;
		last->next = nullptr;
	}
}

void myList::push_back(int value)
{
	if (first == last && first == nullptr) {
		node * buffer = new node{ value,nullptr,nullptr };
		last = buffer;
		first = last;
	}
	else {
		node*buffer = new node{ value,nullptr,last };
		last->next = buffer;
		last = buffer;
	}
}

void myList::shiftLeft()
{
	pop_front();
	push_back(rand());
}

void myList::shiftRight()
{
	pop_back();
	push_front(rand());
}

void myList::rotateLeft()
{
	node * aux = last;
	pop_back();
	push_front(last->info);
}

void myList::rotateRight()
{
	node * aux = first;
	pop_front();
	push_back(aux->info);
}


myList::~myList()
{

}
