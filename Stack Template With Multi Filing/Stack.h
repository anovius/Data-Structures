#pragma once
#include "Node.h"
#include "Node.cpp"
template <class T>
class Stack
{
	Node<T>* top;
public:
	Stack();
	bool isEmpty();
	void push(T d);
	T pop();
	~Stack();
};