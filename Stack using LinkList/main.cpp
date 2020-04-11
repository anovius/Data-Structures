#include<iostream>
#include "LinkList.h"
using namespace std;
int main() {
	LinkList list;
	list.push(12);
	list.push(13);
	list.push(32);
	list.push(19);
	list.show();
	cout << list.pop() << endl;
	list.show();
	return 0;
}