#include <iostream>
#include "polynomial.h"
using namespace std;
polynomial::polynomial() {
	termArray = 0;
	capacity = 0;
	terms = 0;
}
void polynomial::addTerm(term temp) {
	for (int i = 0; i <= terms; i++) {
		if (termArray[i].exp == 0 && termArray[i].coef == 0) {
			termArray[i] = temp;
			terms++;
			break;
		}
		else if (termArray[i].exp == temp.exp) {
			termArray[i].coef += temp.coef;
			break;
		}
	}
}
ostream& operator << (ostream& out, const polynomial& p) {
	for (int i = 0; i < p.terms; i++) {
		if (p.termArray[i].getExp() == 0) out << p.termArray[i].getCoef();
		else {
			if (p.termArray[i].getCoef() != 1) out << p.termArray[i].getCoef();
			out << 'x';
			if (p.termArray[i].getExp() != 1) out << '^' << p.termArray[i].getExp();
		}
		if(i!= p.terms-1)out << " + ";
	}
	out << endl;
	return out;
}
istream& operator >> (istream& in, polynomial& p){
	int n;
	cout << "Enter Size of Polynomial: ";
	in >> n;
	p.termArray = new term[n];
	p.capacity = n;
	for (; p.terms < p.capacity;) {
		cout << "Enter exp: ";
		in >> n;
		p.termArray[p.terms].setExp(n);
		cout << "Enter coef: ";
		in >> n;
		p.termArray[p.terms++].setCoef(n);
	}
	return in;
}
polynomial polynomial::operator*(const polynomial& p) {
	polynomial ans;
	ans.termArray = new term[terms * p.terms];
	ans.capacity = terms * p.terms;
	ans.terms = 0;
	term abc;
	for (int i = 0; i < terms; i++) {
		for (int j = 0; j < p.terms; j++) {
			abc.exp = termArray[i].exp + p.termArray[j].exp;
			abc.coef = termArray[i].coef * p.termArray[j].coef;
			ans.addTerm(abc);
		}
	}
	ans.adjustCapacityToTerms();
	return ans;
}
polynomial polynomial::operator+(const polynomial& p) {
	polynomial c;
	int apos = 0;
	int bpos = 0;
	int cpos = 0;
	c.capacity = p.capacity + capacity;
	c.terms = 0;
	c.termArray = new term[p.capacity + capacity];
	while (apos < terms && bpos < p.terms) {
		if (termArray[apos].exp == p.termArray[bpos].exp) {
			if (termArray[apos].coef + p.termArray[bpos].coef != 0) {
				c.termArray[cpos].exp = termArray[apos].exp;
				c.termArray[cpos].coef = termArray[apos].coef + p.termArray[bpos].coef;
				cpos++;
			}
			apos++; bpos++;
		}
		else if (termArray[apos].exp > p.termArray[bpos].exp) {
			c.termArray[cpos].exp = termArray[apos].exp;
			c.termArray[cpos].coef = termArray[apos].coef;
			cpos++; apos++;
		}
		else {
			c.termArray[cpos].exp = p.termArray[bpos].exp;
			c.termArray[cpos].coef = p.termArray[bpos].coef;
			cpos++; bpos++;
		}
	}
	while (apos < terms) {
		c.termArray[cpos].exp = termArray[apos].exp;
		c.termArray[cpos].coef = termArray[apos].coef;
		apos++; cpos++;
	}
	while (bpos < p.terms) {
		c.termArray[cpos].exp = p.termArray[bpos].exp;
		c.termArray[cpos].coef = p.termArray[bpos].coef;
		bpos++; cpos++;
	}
	c.terms = cpos;
	c.adjustCapacityToTerms();
	return c;
}
void polynomial::operator=(const polynomial & p) {
	delete[]termArray;
	termArray = new term[p.capacity];
	capacity = p.capacity;
	terms = p.terms;
	for (int i = 0; i < p.terms; i++)
		termArray[i] = p.termArray[i];
}
polynomial::polynomial(polynomial& p) {
	termArray = new term[p.capacity];
	capacity = p.capacity;
	terms = p.terms;
	for (int i = 0; i < p.terms; i++)
		termArray[i] = p.termArray[i];
}
void polynomial::adjustCapacityToTerms() {
	term* temp = termArray;
	termArray = new term[terms];
	for (int i = 0; i < terms; i++)
		termArray[i] = temp[i];
	capacity = terms;
	delete temp;
}
int polynomial::evaluate(int n) {
	int ans = 0;
	for (int i = 0; i < terms; i++) {
		ans = ans + (termArray[i].coef * pow(n, termArray[i].exp));
	}
	return ans;
}
polynomial::~polynomial() {
	delete []termArray;
}