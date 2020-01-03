#include<iostream>
#include<iomanip>
using namespace std;
#include"Polynomial.h"

void createp(Poly*& p, int num) {
	Poly* r = p;
	cout << "Input the polynomial(coef,expo):";
	for (int i = 0; i < num; i++)
	{
		Poly* temp = new Poly;
		cin >> temp->coef >> temp->expo;
		temp->next = r->next;
		r->next = temp;
		r = temp;
	}
	r->next = NULL;
}
Poly* add(Poly* p1, Poly* p2) {
	Poly* ans = new Poly;
	//先将p1赋值给ans
	Poly* p = p1->next;
	Poly* q = p2->next;
	Poly* r = ans;
	r->next = NULL;
	while (q != NULL || p != NULL)
	{
		if (q == NULL)
		{
			r->next = p;
			break;
		}
		if (p == NULL) {
			r->next = q;
			break;
		}
		if (p->coef > q->coef)
		{
			Poly* t = p->next;
			p->next = r->next;
			r->next = p;
			r = p;
			p = t;
		}
		else if (p->coef == q->coef)
		{
			if ((p->expo + q->expo) != 0) {
				Poly* t = new Poly;
				t->expo = p->expo + q->expo;
				t->coef = q->coef;
				t->next = r->next;
				r->next = t;
				r = t;
				p = p->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		else if (p->coef < q->coef)
		{
			Poly* t = q->next;
			q->next = r->next;
			r->next = q;
			r = q;
			q = t;
		}
	}
	return ans;
}
Poly* minus_(Poly* p1, Poly* p2) 
{
	Poly* ans = new Poly;
	//先将p1赋值给ans
	Poly* p = p1->next;
	Poly* q = p2->next;
	Poly* r = ans;
	r->next = NULL;
	while (q != NULL || p != NULL)
	{
		if (q == NULL)
		{
			r->next = p;
			break;
		}
		if (p == NULL) {
			r->next = q;
			break;
		}
		if (p->coef > q->coef)
		{
			Poly* t = p->next;
			p->next = r->next;
			r->next = p;
			r = p;
			p = t;
		}
		else if (p->coef == q->coef)
		{
			if ((p->expo - q->expo) != 0) {
				Poly* t = new Poly;
				t->expo = p->expo - q->expo;
				t->coef = q->coef;
				t->next = r->next;
				r->next = t;
				r = t;
				p = p->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		else if (p->coef < q->coef)
		{
			Poly* t = q->next;
			q->next = r->next;
			r->next = q;
			r = q;
			q = t;
		}
	}
	return ans;
}
void display(const Poly* ans)
{
	Poly* c = ans->next;
	while (c != NULL)
	{
		cout << c->coef << ' ';
		cout << c->expo;
		if (c->next) cout << ' ';
		c = c->next;
	}
	cout << endl;
}