#pragma once
class polynomial;
class term
{
	friend polynomial;
	int exp;
	int coef;
public:
	void setExp(int n) { exp = n; }
	void setCoef(int n) { coef = n; }
	int getExp() {
		return exp;
	}
	int getCoef() {
		return coef;
	}
	term();
};

