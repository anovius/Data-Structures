#include <iostream>
#include "nArray.h"
using namespace std;
nArray::nArray(int d, int n1, int n2, int n3, int n4, int n5, int n6, int n7){
	n = d;
	int a[7];
	a[0] = n1;
	a[1] = n2;
	a[2] = n3;
	a[3] = n4;
	a[4] = n5;
	a[5] = n6;
	a[6] = n7;
	int size = 1;
	U = new int[d];
	for (int i = 0; i < d; i++) {
		size = size * a[i];
		U[i] = a[i];
	}
	//cout << "size " << size << endl;
	Array = new int[size];
}
nArray::nArray(nArray& t) {
	n = t.n;
	int size = 1;
	U = new int[n];
	for (int i = 0; i < n; i++) {
		size *= size * t.U[i];
		U[i] = t.U[i];
	}
	Array = new int[size];
	for (int i = 0; i < size; i++) {
		Array[i] = t.Array[i];
	}
}
void nArray::operator=(const nArray& t) {
	n = t.n;
	int size = 1;
	U = new int[n];
	for (int i = 0; i < n; i++) {
		size *= size * t.U[i];
		U[i] = t.U[i];
	}
	Array = new int[size];
	for (int i = 0; i < size; i++)
		Array[i] = t.Array[i];
}
int nArray::findIndex(int d, int n1, int n2, int n3, int n4, int n5, int n6, int n7) {
	int a[7];
	a[0] = n1;
	a[1] = n2;
	a[2] = n3;
	a[3] = n4;
	a[4] = n5;
	a[5] = n6;
	a[6] = n7;
	int mul = 1;
	int index = a[d - 1];
	for (int i = d-1; i > 0; i--) {
		mul = mul * U[i];
		int te = mul * a[i - 1];
		index = index + te;
	}
	//cout << "Index: "<< index << endl;
	return index;
}
int& nArray::operator()(int d, int n1, int n2, int n3, int n4, int n5, int n6, int n7) {
	int ind = findIndex(d, n1, n2, n3, n4, n5, n6, n7);
	return Array[ind];
}
nArray::~nArray() {
	delete[] U;
	delete[] Array;
}