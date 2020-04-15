#pragma once
template <class T>
class Node
{
	template <class T>
	friend class Stack;
	T data;
	Node<T>* next;
public:
	Node(T d, Node* N);
};