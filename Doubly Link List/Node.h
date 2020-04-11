#pragma once
class LinkList;
class Node
{
	friend LinkList;
	int data;
	Node* next;
	Node* prev;
public:
	Node(int d = 0, Node* n = 0, Node* p= 0);
};

