/*
 class menu: �˵��ĳ�ʼ�����������
*/
#pragma once
#ifndef MENU_H
#define MENU_H
class Menu {
private:
	int n;
	vector<string> function_list_;
public:
	Menu(const vector<string>);
	void display();
};
#endif // MENU_H

