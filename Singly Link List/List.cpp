#include <iostream>
#include "List.h"
using namespace std;
List::List() {
	first = NULL;
}
void List::InsertAtStart(int d) {
	Node* t = new Node(d);
	t->next = first;
	first = t;
}
void List::InsertAtEnd(int d) {
	Node* t = new Node(d);
	if (first == NULL) {
		first = t;
		return;
	}
	Node* temp = first;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = t;
}
void List::InsertAfterNode(Node* node, int d) {
	if (node == NULL) {
		cout << "Node not Exists\n";
		return;
	}
	Node* t = new Node(d);
	t->next = node->next;
	node->next = t;
}
void List::DeleteAfterNode(Node* node) {
	if (node == NULL || node->next == NULL) {
		cout << "No Node not exits\n";
		return;
	}
	Node* temp = node->next;
	node->next = temp->next;
	delete temp;
}
bool List::DeleteNode(int data) {
	Node* node = SearchNode(data);
	if (node == NULL) {
		return false;
	}
	if (first == node) {
		first = node->next;
		delete node;
		return true;
	}
	Node* temp = first;
	while (temp->next != node) {
		temp = temp->next;
	}
	temp->next = node->next;
	delete node;
	return true;
}
bool List::InsertSorted(int data) {
	if (SearchNode(data) != NULL) {
		return false;
	}
	Node* newNode= new Node(data);
	if (first == NULL) {
		first = newNode;
		return true;
	}
	Node* curr = first;
	Node* prev = NULL;
	while (curr != NULL && curr->data < data) {
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL) {
		newNode->next = first;
		first = newNode;
	}
	else {
		prev->next = newNode;
		newNode->next = curr;
	}
	return true;
}
Node* List::SearchNode(int data) {
	if (first == NULL) return NULL;
	Node* temp = first;
	while (temp->next!=NULL) {
		if(temp->data == data) return temp;
		temp = temp->next;
	}
	if (temp->data == data)
		return temp;
	else return NULL;
}
void List::ShowList() {
	Node* temp = first;
	cout << "List: ";
	while (temp->next != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << temp->data << '\n';
}
void List::Reverse() {
	if (first == NULL || first->next == NULL) {
		cout << "Can not be reversed\n";
		return;
	}
	Node* temp;
	Node* curr = first->next;
	Node* prev = first;
	first->next = NULL;
	while (curr->next != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	curr->next = prev;
	first = curr;
}
