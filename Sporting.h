/*
class Sporting
@para:m the num of school <= 20
@para:n the num of program <=20
@para:The list of schoolId--schoolName
@para:The list of programId--programName
Description: The male program's Id 1-m, while the femal's m+1--m+w
*/
#pragma once
#ifndef SPORTING_H
#define SPORTING_H
enum TYPE 
{
	THREE = 3,
	FIVE = 5
};
struct schoolNode {
	int schoolKey;
	string name;
};
struct schoolScore {
	int key;
	int score;
};
struct programNode {
	int programKey;
	string name;
	int program_type;
};
struct score_list {
	int program_key;
	vector<schoolScore> program_score_list;
};
class Sporting {
private:
	int m;
	int n;
	vector<schoolNode> school;
	vector<programNode> program;
	vector<score_list> list;
	int male_female(int,int) const;
	int sortByScore(int)const;
	static int findType(const Sporting&,const int);         //seacrch the program type(3 or 5) 
	int score_3[3] = { 5,3,2 };
	int score_5[5] = { 7,5,3,2,1 };
public:
	Sporting() {};
	~Sporting() {};
	void initInput(ifstream&);
	void scoreInput();  //input score in list
	void searchPro(int) const;   //search info by program key
	void searchSch(int) const;   //search info by school key
	void sort_(int ) const;
};
#endif // SPORINTG_H