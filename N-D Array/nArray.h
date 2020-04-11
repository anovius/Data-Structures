#pragma once
class nArray
{
	int* Array;
	int n; 
	int* U; 
public:
	nArray(int d, int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0, int n5 = 0, int n6 = 0, int n7 = 0);
	nArray(nArray& t);
	void operator= (const nArray& t);
	int findIndex(int d, int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0, int n5 = 0, int n6 = 0, int n7 = 0);
	int& operator()(int d, int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0, int n5 = 0, int n6 = 0, int n7 = 0);
	~nArray();
};

