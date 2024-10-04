#include <iostream>
#include "list.h"

int main() {
	LinkedList* T = new LinkedList();
	for (int i = 0; i < 10; i++) {
		T->InsTail(rand() % 10);
	}

	T->PrintAll();
	T->PrintCur();

	Node* temp = new Node();
	temp->data = 0;
	T->Find(T->list, temp);

	T->PrintCur();

}