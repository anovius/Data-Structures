#include "Stack.h"
#include <iostream>
using namespace std;
template<class T> 
Stack <T> ::Stack(){
	top  = NULL;
}
template<class T>
bool Stack <T> ::isEmpty() {
	return top == NULL;
}
template<class T>
void Stack <T> ::push(T d) {
	top = new Node<T>(d, top);
}
template<class T>
T Stack <T>::pop() {
	if (!isEmpty()) {
		T data = top->data;
		Node<T>* temp = top;
		top = top->next;
		delete temp;
		return data;
	}
}
template<class T>
Stack <T> ::~Stack() {
	while (top != NULL)
		pop();
}