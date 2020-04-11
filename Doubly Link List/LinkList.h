#pragma once
#include "Node.h"

class LinkList
{
	Node* head;
	Node* tail;
public:
	LinkList();
	void insertAfter(Node* y, int d);
	void remove(Node* x);
	void print();
	Node* getHead();
	void insertBefore(Node* y, int d);
	void insert(int d);
	void remove(int d);
	Node* search(int d);
	void Merge(LinkList& L); 
	~LinkList();
};
