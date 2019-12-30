/*
class Sporting
@para:m the num of school <= 20
@para:n the num of program <=20
@para:The list of schoolId--schoolName
@para:The list of programId--programName
Description: The male program's Id 1-m, while the femal's m+1--m+w
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"Sporting.h"
void Sporting::initInput(int _m, int _n, vector<schoolNode> _school, vector<programNode> _program)
{
	cout << "??????????????????????????????????????§µ??????";
	cin >> _m >> _n;
	m = _m;
	n = _n;
	cout << "???????????§µ????????";
	for (int i = 0; i < n; i++)
	{
		schoolNode temp;
		cin >> temp.schoolKey >> temp.name;
		_school.push_back(temp);
	}
	cout << "??????????????????????????";
	for (int i = 0; i < m; i++)
	{
		programNode temp;
		cin >> temp.programKey >> temp.name >> temp.program_type;
		_program.push_back(temp);
	}
	school = _school;
	program = _program;
}
int Sporting::findType(Sporting &mine,int _key)
{
	for (auto i : mine.program) 
	{
		if (_key == i.programKey) 
		{
			return i.program_type;
		}
	}
}
void Sporting::scoreInput()
{
	cout << "?????????????§µ??(????????§µ?????§µ???)";
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		int type;
		score_list temp_score_list;
		cin >> temp_score_list.program_key;
		type = findType(*this, temp_score_list.program_key);

		if (type == (int)TYPE::THREE) num = 3;
		else if (type == (int)TYPE::FIVE) num = 5;

		cout << "??????" << num << "???§µ?????";
		for (int j = 0; j < num; j++)
		{
			schoolScore temp;
			cin >> temp.key >> temp.score;
			temp_score_list.program_score_list.push_back(temp);
		}
		list.push_back(temp_score_list);
	}
}
void Sporting::searchPro(int _key)
{
	for (auto i : program) 
	{
		if (i.programKey == _key)
		{
			cout << "????????????" << _key << " ??????" << i.name;
		}
	}
	for (auto school_score : list)
	{
		if (school_score.program_key == _key) 
		{
			for (auto school_key : school_score.program_score_list)
			{
				int i = 0;
				cout << "??" << ++i << "?????";
				for (auto school_name : school)
				{
					if (school_key.key == school_name.schoolKey)
						cout << school_key.key << school_name.name;
				}
				cout << school_key.score;
			}
		}
	}
}
/*
search for the pro info by school key
@para:vector<score_list> list;
struct score_list {
	int program_key;
	vector<schoolScore> program_score_list;
};
*/
void Sporting::searchSch(int school_key)  
{
	for (auto i : list)
	{
		for (auto j : i.program_score_list)
		{
			int order = 1;
			if (j.key == school_key)
			{
				cout << "???§µ???????";
				for (auto pro_name : program)
				{
					if (i.program_key == pro_name.programKey)
						cout << pro_name.name<<"?§Ý??";
				}
				cout << "??" << order << "??" << ", ?????" << j.score;
			}
			order++;
		}
	}
}
/*
  print by order
  @para: type 
   1 -> by school key
    11 -> by school key and sex score 
   2 -> by program key
   3 -> by score 
*/
void Sporting::sort(int type)
{
	switch(type)
	{
		case 1: 
		{
			for (int i = 1; i <= 20; i++)
			{
				for (auto school_info : school)
				{
					if (school_info.schoolKey == i)
					{
						cout << school_info.schoolKey << ' ' << school_info.name;
						break;
					}
				}
			}
		}break;
		case 2:
		{
			for (int i = 1; i <= 20; i++)
			{
				for (auto program_info : program)
				{
					if (program_info.programKey == i)
					{
						cout << program_info.programKey << ' ' << program_info.name;
						break;
					}
				}
			}
		}break;
	}
}
/*
 same as search by school_key except print
*/
int* Sporting::male_female(int school_key) 
{
	int result[2] = {0,0};     //male in 0,female in 1
	for (auto i : list)
	{
		int sex = 0;
		for (auto j : i.program_score_list)
		{
			int type = findType(*this, i.program_key);
			int order = 1;
			if (j.key == school_key)
			{
				for (auto pro_name : program)
				{
					if (i.program_key == pro_name.programKey)
					{
						const int& a = i.program_key;
						if (a > m)
						{
							sex = 1;
						}
						else if (a <= m && a > 0)
						{
							sex = 0;
						}
					}
				}
				type == 3 ? result[sex] += score_3[order - 1] : result[sex] = score_5[order - 1];
			}
			order++;
		}
	}
	return result;
}
int Sporting::sortByScore(int school_key) 
{
	int result = 0;
	for (auto i : list)
	{
		int sex = 0;
		for (auto j : i.program_score_list)
		{
			int type = findType(*this, i.program_key);
			int order = 1;
			if (j.key == school_key)
			{
				type == 3 ? result += score_3[order - 1] : result = score_5[order - 1];
			}
			order++;
		}
	}
	return result;
}