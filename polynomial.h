#pragma once
#include "term.h"
using namespace std;
class polynomial
{
	term* termArray;
	int capacity;
	int terms;
public:
	polynomial();
	polynomial(polynomial& p);
	friend istream& operator >> (istream& in, polynomial& p);
	friend ostream& operator << (ostream& out, const polynomial& p);
	void addTerm(term);
	polynomial operator+(const polynomial& p);
	polynomial operator*(const polynomial& p);
	void operator=(const polynomial& p);
	void adjustCapacityToTerms();
	int evaluate(int n);
	~polynomial();
};