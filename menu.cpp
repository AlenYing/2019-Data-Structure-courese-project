#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"menu.h"
Menu::Menu(const vector<string> n_f_s)
{
	function_list_ = n_f_s;
	n = n_f_s.size();
}
void Menu::display() 
{
	for (int i = 0; i < n; i++)
	{
		cout<<i+1<<" ."<<function_list_[i];
	}
}
