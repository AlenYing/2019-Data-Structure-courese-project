/*
   main.cpp:主函数
*/
#include<string>
#include <iostream>
#include <vector>
using namespace std;
#include"menu.h"
#include"Sporting.h"
const vector<string> MenuText = { "退出","运动会分数统计" };
int main()
{
	int input = -1;
	Menu main_menu(MenuText);
    main_menu.display();
	while (input != 0)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			Sporting sp;
		}

	}
	return 0;
}


