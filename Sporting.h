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
enum PROGRAMTYPE {
	THREE, FIVE
};
struct schoolNode {
	int schoolKey;
	string name;
	int score;
};
struct programNode {
	int programKey;
	string nane;
	PROGRAMTYPE p;
};
struct program_school_score {
	int p_key;
	vector<schoolNode> p_s;
};
class Sporting {
private:
	int m;
	int n;
	vector<schoolNode> school;
	vector<programNode> program;
	vector<program_school_score> list;
public:
	Sporting(int _m, int _n, vector<schoolNode> _school, vector<programNode> _program);
	void initInput();   //input m and n and vector school and vector program
	void scoreInput();  //input score in list
	bool searchPro();   //search info by program key
	bool searchSch();   //search info by school key
};
#endif // SPORINTG_H