#include "myList.h"



myList::myList()
{
	first = new node{ {rand() % 5},{nullptr },{nullptr} };
	last = first;
}

myList::myList( myList& in)
{
	node* manterior, *mactual,*msiguiente,*ianterior,*iactual,*isiguiente;
	int c = 0;
	first = new node{in.first->info,nullptr,nullptr};
	mactual = in.first->next;
	first->next = mactual;
	mactual->previous = first;
	iactual = in.first->next;
	ianterior = in.first;
	isiguiente = iactual->next;
	while (mactual != in.last) {
		manterior = mactual;
		mactual = iactual->next;
		msiguiente = mactual->next;
		ianterior = iactual;
		iactual = iactual->next;
		isiguiente = iactual->next;
	}
}

void myList::push_front(int value)
{
	first->previous = new node{value,first,nullptr};
	first = first->previous;
}

void myList::pop_front()
{
	node* aux = first->next;
	first = nullptr;
	first = aux;
}

void myList::pop_back()
{
	node*aux = last->previous;
	last = nullptr;
	last = aux;
}


myList::~myList()
{

}
