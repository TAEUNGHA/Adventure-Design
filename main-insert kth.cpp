#include <iostream>
#include "list.h"

int main() {
	LinkedList* T = new LinkedList();
	for (int i = 0; i < 7; i++) {
		T->InsTail(rand() % 10);
	}
		Node* temp = T->list->curnode;
	for (int i = 0; i < 3; i++) {
		T->InsTail(rand() % 10);
	}

	T->PrintAll();

	T->list->curnode = temp;
	T->InsAfterCur(10);
	T->PrintAll();

}