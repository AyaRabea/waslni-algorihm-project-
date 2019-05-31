#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<limits>
#include<stack>
using namespace std;
class best
{
public:
	string name;
	string pname;
	double weight;
	bool ismarked;
	best();


};

class mini
{
public:
	int ncity;
	string start;
	pair<string, double>endw;
	vector<pair<string, double>>inf;
	unordered_map<string, vector<pair<string, double> > >wways;
	unordered_map<string, vector<pair<string, double> > >::iterator it;
	vector<best>bestway;
	string mylocation;
	double short_time;
	stack<string>final;
	mini();
	~mini();
	unordered_map<string, vector<pair<string, double> > >input();
    void graph(unordered_map<string, vector<pair<string, double> > > w);
	void output(string n);
	void display();
};
