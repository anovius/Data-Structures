#include<iostream>
#include "nArray.h"
using namespace std;
int main() {
	nArray arr2(5, 4, 4, 5, 9, 1); //5d array of size 4x4x5x9x1
	arr2(5, 1, 1, 1, 1, 0) = 7; //setting 5d array’s (1,1,1,1,1)th element to 7
	cout << arr2(5, 1, 1, 1, 1, 0) << endl; //prints 7, already set
	arr2(5, 1, 1, 1, 2, 0) = 59;
	cout << arr2(5, 1, 1, 1, 2, 0) << endl; 
	nArray abc(2, 1, 1);
	abc(2, 0, 0) = 54;
	cout << abc(2, 0, 0) << endl;
	nArray xyz(1, 5);
	xyz(1, 3) = 10;
	cout << xyz(1, 3) << endl;
	nArray arr(7, 3, 4, 6, 3, 2, 6, 5);
	arr(7, 1, 2, 3, 5, 0, 1, 1) = 199;
	cout << arr(7, 1, 2, 3, 5, 0, 1, 1) << endl;
	nArray oneD(1, 3);
	oneD(1, 2) = 6;
	cout << oneD(1, 2) << endl;
	nArray cp(oneD);
	cout << cp(1, 2) << endl;
	return 0;
}