#pragma once
#ifndef HOSPITAL
#define HOSPITAL
struct node
{
	string id;
	node* next;
};
struct LinkQn
{
	node* front;
	node* rear;
};
#endif // !HOSPITAL
