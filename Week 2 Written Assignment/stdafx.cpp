#include "stdafx.h"


List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

bool List::isEmpty() {
	if (head == NULL)
		return true;
	else
		return false;
}

void List::addNode(char val) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = val;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
}

void List::printValue() {

}
