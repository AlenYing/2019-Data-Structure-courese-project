/*
   main.cpp:主函数
*/
#include<string>
#include <iostream>
#include <vector>
using namespace std;
#include"menu.h"
#include"Sporting.h"
const vector<string> MenuText = { "运动会分数统计" };
int main()
{
	Menu main_menu(MenuText);
    main_menu.display();
	return 0;
}


