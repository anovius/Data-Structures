#pragma once
class LinkList;
class Node
{
	friend LinkList;
	int data;
	Node* next;
public:
	Node(int d=0, Node* n= 0);
};

