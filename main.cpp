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
#include"Polynomial.h"
const vector<string> MenuText = { "Sporting ","Polynomial"};

const vector<string> SportingMenu = { "Init the Sporting info(Necessary!)",
									  "Input the score of each program", 
									  "Output by school Id",
									  "Output by score of school",
									  "Output by male or female score",
									  "search by school Id",
									  "search by program Id"};

const vector<string> PolyMenu = { "Input two polynomial",
								  "Output the add result",
								  "Output the minus result"};

int main()
{
	int input = -1;
	Menu main_menu(MenuText);
    main_menu.display();
	while (input != 0)
	{
		cout << endl << "Choose the project:";
		cin >> input;
		switch (input)
		{
			case 1:
			{
				Menu SportingMenu(SportingMenu);
				SportingMenu.display();
				int fun_num = -1;
				ifstream file("Text.csv");
				if (!file)
				{
					cerr << "fail to open file";
				}
				Sporting sp;
				while (fun_num != 0)
				{
					cout << endl << "Please the num of the function: ";
					cin >> fun_num;
					switch (fun_num)
						{
						case 1:
						{
							sp.initInput(file);
						}break;
						case 2:
						{
							sp.scoreInput();
						}break;
						case 3:
						{
							sp.sort_(1);
						}break;
						case 4:
						{
							sp.sort_(3);
						}break;
						case 5:
						{
							sp.sort_(2);
						}break;
						case 6:
						{
							int sch_temp;
							cout << endl << "Please input the school Id:";
							cin >> sch_temp;
							sp.searchSch(sch_temp);
						}break;
						case 7:
						{
							int pro_temp;
							cout << endl << "Please input the program Id:";
							cin >> pro_temp;
							sp.searchPro(pro_temp);
						}break;
						case 0:
						{}break;
						default: 
						{
							cout << "Input error!Please try again!\n";
						}
					}
				}
			}break;
			case 2:
			{
				Menu poly_menu(PolyMenu);
				poly_menu.display();
				Poly* p1 = new Poly;
				Poly* p2 = new Poly;
				p1->next = NULL;
				p2->next = NULL;
				int fun_num = -1;
				while (fun_num != 0)
				{
					cout << "Please the num of the function: ";
					cin >> fun_num;
					switch (fun_num)
					{
						case 1:
						{
							int num1;
							cout << "Please input the first polynomial's length:";
							cin >> num1;
							createp(p1, num1);
							int num2;
							cout << "Please input the second polynomial's length:";
							cin >> num2;
							createp(p2, num2);
						}break;
						case 2:
						{
							display(add(p1, p2));
						}break;
						case 3:
						{
							display(minus_(p1, p2));
						}break;
						case 0: {}break;
						default: {cerr << "Input error!Please try again!\n"; }break;
					}
				}
			}break;
		}

	}
	return 0;
}


