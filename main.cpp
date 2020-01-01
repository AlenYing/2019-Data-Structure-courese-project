/*
   main.cpp:主函数
*/
#include<string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include"menu.h"
#include"Sporting.h"
const vector<string> MenuText = { "运动会分数统计","退出" };
const vector<string> SportingMenu = { "Input the score of each program", 
									  "Output by school Id",
									  "Output by score of school",
									  "Output by male and female score"};
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
			ifstream file("Text.csv");
			if (!file)
			{
				cerr << "fail to open file";
			}
			Sporting sp;
			sp.initInput(file);
			sp.scoreInput();
			//int temp;
			//cout << "Please input the program id: (for search)" << endl;
			//cin >> temp;
			//sp.searchPro(temp);
			sp.sort_(11);
		}

	}
	return 0;
}


