#include<iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
int main() {
	Stack <int> st;
	st.push(12);
	st.push(32);
	st.push(23);
	Stack <char> st2;
	st2.push('a');
	st2.push('b');
	st2.push('h');
	Stack <string> st3;
	st3.push("usman");
	st3.push("okok");
	st3.push("bcsf18a522");
	cout << st.pop() << endl;
	cout << st2.pop() << endl;
	cout << st3.pop() << endl;
	return 0;
}