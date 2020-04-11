#pragma once
class List;
class Node
{
	friend List;
	int data;
	Node* next;
public:
	Node(int d = 0);
};

