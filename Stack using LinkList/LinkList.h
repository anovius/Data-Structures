#pragma once
#include "Node.h"
class LinkList
{
	Node* first;
public:
	LinkList();
	void push(int d);
	int pop();
	bool IsEmpty();
	void show();
	~LinkList();
};

