#include <iostream>
#include "LinkList.h"
using namespace std;
int main() {
	LinkList list;
	list.insert(5);
	list.insert(15);
	list.insert(7);
	list.insert(40);
	list.insert(70);
	list.insert(30);
	list.print();
	list.remove(5);
	list.print();
	LinkList abc;
	abc.insert(9);
	abc.insert(11);
	abc.insert(7);
	abc.insert(50);
	abc.print();
	abc.Merge(list);
	abc.print();
	list.insert(145);
	list.insert(125);
	list.insert(148);
	list.insert(105);
	list.print();
	return 0;
}