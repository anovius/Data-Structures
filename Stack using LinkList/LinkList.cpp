#include "LinkList.h"
#include <iostream>
using namespace std;
LinkList::LinkList() {
	first = NULL;
}
void LinkList::push(int d) {
	first = new Node(d, first);
}
bool LinkList::IsEmpty() {
	return first == NULL;
}
int LinkList::pop() {
	if (!IsEmpty()) {
		int d = first->data;
		Node* temp = first;
		first = first->next;
		delete temp;
		return d;
	}
	else return -1;
}
void LinkList::show() {
	Node* temp = first;
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}
LinkList::~LinkList() {
	Node* temp;
	while (first != NULL) {
		temp = first;
		first = first->next;
		delete temp;
	}
}