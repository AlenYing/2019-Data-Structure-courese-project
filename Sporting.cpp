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
#include<fstream>
using namespace std;
#include"Sporting.h"
void Sporting::initInput(ifstream& fin)
{
	int female_num = 0;   //female program
	int male_num = 0;   //male program
	int school_num = 0;    //school
	vector<schoolNode> _school;
	vector<programNode> _program;
	cout << endl << "Please input the Max num of program(male,female),school: ";
	cin >> male_num >> female_num>>school_num;
	if (school_num == 0 || male_num + female_num == 0)
	{
		cerr << "Wrong!" << endl;
		return;
	}
	n = male_num + female_num;
	m = school_num;
	for (int i = 0; i < n; i++)
	{
		programNode temp;
		fin >> temp.programKey >> temp.name >> temp.program_type;
		_program.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		schoolNode temp;
		fin >> temp.schoolKey >> temp.name;
		_school.push_back(temp);
	}
	school = _school;
	program = _program;
}
int Sporting::findType(const Sporting &mine,const int _key)
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
	for (int i = 0; i < n; i++)
	{
		cout << "please input the program Id";
		int num = 0;
		int type;
		score_list temp_score_list;
		cin >> temp_score_list.program_key;
		type = findType(*this, temp_score_list.program_key);

		if (type == (int)TYPE::THREE) num = 3;
		else if (type == (int)TYPE::FIVE) num = 5;

		cout << "this program has " << num << " winning school"<<endl;
		for (int j = 0; j < num;)
		{
			cout << "NO." << ++j <<": ";
			schoolScore temp;
			cin >> temp.key >> temp.score;
			temp_score_list.program_score_list.push_back(temp);
		}
		list.push_back(temp_score_list);
	}
}
void Sporting::searchPro(int _key) const
{
	for (auto i : program) 
	{
		if (i.programKey == _key)
		{
			cout << "The program " << _key << ' ' << i.name <<endl;
		}
	}
	int i = 0;
	for (auto school_score : list)
	{
		if (school_score.program_key == _key) 
		{
			for (auto school_key : school_score.program_score_list)
			{
				cout << "No." << ++i << "is : \n";
				for (auto school_name : school)
				{
					if (school_key.key == school_name.schoolKey)
						cout <<"The ID of the school: "<<school_key.key <<endl<<"The name of the school: "<< school_name.name<<endl;
				}
				cout <<"The score of the school: "<< school_key.score<<endl;
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
void Sporting::searchSch(int school_key) const 
{
	for (auto schoolinfo : school)
	{
		if (school_key == schoolinfo.schoolKey)
			cout << "The school:" << school_key << ' ' << schoolinfo.name << ':' << endl;
	}
	for (auto i : list)
	{
		int order = 1;
		for (auto j : i.program_score_list)
		{
			if (j.key == school_key)
			{
				for (auto pro_name : program)
				{
					if (i.program_key == pro_name.programKey)
						cout <<"In program:"<<pro_name.programKey<<' '<< pro_name.name;
				}
				cout << " get No." << order <<' '<< j.score<<endl;
			}
			order++;
		}
	}
}
/*
  print by order
  @para: type 
   1 -> by school key
   2 ->sex score 
   3 -> by score 
*/
void Sporting::sort_(const int sort_type) const 
{
	switch (sort_type)
	{
		case 1:
		{
			for (int i = 0; i < m; i++)
			{
				for (auto school_info : school)
				{
					if (school_info.schoolKey == i+1)
					{
						cout << school_info.schoolKey << ' ' << school_info.name << endl;
						break;
					}
				}
			}
		}break;
		case 2:
		{
			cout << "Please input the sex type( 0 is male, 1 is female)";
			int sex_t;
			cin >> sex_t;
			int* ans = new int[m];
			int* index = new int[m];
			for (int i = 0; i < m; i++)
			{
				ans[i] = male_female(i + 1, sex_t);
				index[i] = ans[i];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m - 1; j++)
				{
					if (ans[j] < ans[j + 1])
					{
						int temp = ans[j];
						ans[j] = ans[j + 1];
						ans[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ans[i] == index[j])
					{
						for (auto k : school)
						{
							if (k.schoolKey == j+1)
							{
								cout << j+1 << ". " << k.name << endl;
								break;
							}
						}
						break;
					}
				}
			}
		}break;
		case 3:
		{
			int* ans = new int[m];
			int* index = new int[m];
			for (int i = 0; i < m; i++)
			{
				ans[i] = sortByScore(i + 1);
				index[i] = ans[i];
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m - 1; j++)
				{
					if (ans[j] < ans[j + 1])
					{
						int temp = ans[j];
						ans[j] = ans[j + 1];
						ans[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ans[i] == index[j])
					{
						for (auto k : school)
						{
							if (k.schoolKey == j + 1)
							{
								cout << j + 1 << ". " << k.name << endl;
								break;
							}
						}
					}
				}
			}
		}break;
		default: {
			cerr << "input wrong type";
		}; break;
	}
}
/*
  get every school's male and female score
*/
int Sporting::male_female(int school_key,int sex_type) const 
{
	int result[2] = {0,0};     //male in 0,female in 1
	for (auto i : list)
	{
		int sex = 0;
		int type = findType(*this, i.program_key);
		int order = 1;
		for (auto j : i.program_score_list)
		{
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
	return result[sex_type];
}
int Sporting::sortByScore(int school_key) const
{
	int result = 0;
	for (auto i : list)
	{
		int type = findType(*this, i.program_key);
		int order = 1;
		for (auto j : i.program_score_list)
		{
			if (j.key == school_key)
			{
				type == 3 ? result += score_3[order - 1] : result = score_5[order - 1];
			}
			order++;
		}
	}
	return result;
}