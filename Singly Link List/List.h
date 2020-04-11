#pragma once
#include "Node.h"
class List
{
	Node* first;
public:
	List();
	bool InsertSorted(int data);
	void InsertAtStart(int d);
	void InsertAtEnd(int d);
	void InsertAfterNode(Node* node,int d);
	void DeleteAfterNode(Node* node);
	bool DeleteNode(int data);
	Node* SearchNode(int data);
	void Reverse();
	void ShowList();
};

