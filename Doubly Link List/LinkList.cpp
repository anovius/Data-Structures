#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

void LinkList::insertAfter(Node* y, int d)
{
	if (y != nullptr && y != tail)
	{
		Node* t = new Node(d, y, y->next);
		y->next->prev = t;
		y->next = t;
	}
}
void LinkList::remove(Node* x)
{
	if (x != nullptr && x != head && x != tail)
	{
		x->prev->next = x->next;
		x->next->prev = x->prev;
		delete x;
	}
}

void LinkList::print()
{
	Node* curr = head->next;
	cout << "List: ";
	while (curr != tail)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}


Node* LinkList::getHead()
{
	return head;
}

void LinkList::insertBefore(Node* y, int d) {
	if (y != nullptr && y != head) {
		Node* t = new Node(d, y, y->prev);
		y->prev->next = t;
		y->prev = t;
	}
}
void LinkList::insert(int d) {
	Node* c = head->next;
	while (c != tail && c->data < d) {
		c = c->next;
	}
	insertBefore(c, d);
}

Node* LinkList::search(int d) {
	Node* curr = head->next;
	while (curr != tail)
	{
		if (curr->data == d)return curr;
		curr = curr->next;
	}
	return NULL;
}

void LinkList::remove(int d) {
	Node* temp = search(d);
	if (temp != NULL)
		remove(temp);
	else
		cout << "No such element exists!\n";
}
void LinkList::Merge(LinkList& L) {
	Node* l1 = head->next;
	Node* l2 = L.head->next;
	Node* temp;
	bool check = false;
	while (l2 != L.tail) {
		if (l2->data <= l1->data || check) {
			temp = l2->next;
			l1->prev->next = l2;
			l2->prev = l1->prev;
			l2->next = l1;
			l1->prev = l2;
			l2 = temp;
		}
		else {
			l1 = l1->next;
		}
		if (l1 == tail) check = true;
	}
	L.head->next = L.tail;
	L.tail->prev = L.head;
}
LinkList::~LinkList() {
	Node* curr = head->next;
	Node* temp;
	while (curr != tail)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	delete head;
	delete tail;
}