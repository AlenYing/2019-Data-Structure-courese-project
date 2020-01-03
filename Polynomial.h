#pragma once
#ifndef POLYNOMIAL
#define POLYNOMIAL
struct Poly {
	float expo;
	float coef;
	Poly* next;
};
void createp(Poly*& p, int);
Poly* add(Poly* p1, Poly* p2);
Poly* minus_(Poly* p1, Poly* p2);
void display(const Poly*);

#endif // !POLYNOMIAL
