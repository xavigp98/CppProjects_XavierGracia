#include "myStack.h"

int main() {

	myStack uno;

	uno.push(3);

	int tres = uno.top();

	int size = uno.size();

	uno.pop();

	bool isEmpty = uno.isEmpty();

	return 0;
}