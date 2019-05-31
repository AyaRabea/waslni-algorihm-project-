#pragma once
#include "mini.h"
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<limits>
#include<stack>
using namespace std;

class inorder
{
public:
	unordered_map<string, vector<pair<string, double> > >ways;
	void update();
	void deletee();
	void delete_edge(string city, string edge);
	void delete_city(string city);
	void display_date();
	void order();
	void input();
	inorder();
	~inorder();

};

