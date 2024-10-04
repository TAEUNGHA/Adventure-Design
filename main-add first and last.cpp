#include <iostream>
#include "list.h"

int main() {
	LinkedList* T = new LinkedList();
	for (int i = 0; i < 10; i++) {
		T->InsTail(rand() % 10);
	}


	T->PrintAll();

	T->InsHead(10);
	T->InsTail(11);

	T->PrintAll();

}