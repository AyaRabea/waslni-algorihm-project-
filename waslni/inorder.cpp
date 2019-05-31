#include "mini.cpp"
#include "inorder.h"
#include "mini.h"
mini m;


inorder::inorder()
{
}
inorder::~inorder()
{
}
void  inorder::input()
{
	ways = m.input();
}
void  inorder::order()
{
	input();
	cout << "press 1 to update ||press 2 to delete ||press 3 to display graph date ||press 4 to show the shortest path " << endl;
	int n;
	cin >> n;
	while (n != 0)
	{

		if (n == 1)update();
		else if (n == 2)deletee();
		else if (n == 3)display_date();
		else if (n == 4)
		{
			string destination;
			m.graph(ways);
			cout << "please enter your destination : " << endl;
			cin >> destination;
			m.output(destination);
			m.display();
		}
		cout << "press 1 to update ||press 2 to delete ||press 3 to display graph date ||press 4 to show the shortest path " << endl;
		cin >> n;
	}
}
void inorder::update()
{
	cout << "Press 1 if you want add new city|| Press 2 if you want add edge || Press 3 if you want edit weight of edge" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "Enter the number of city that you want add" << endl;
		int num;
		cin >> num;
		m.ncity = ways.size();
		m.ncity += num;
		for (int i = 0; i < num; i++)
		{
			cout << "Please Enter the start city:" << endl;
			cin >> m.start;

			m.it = ways.find(m.start);
			if (m.it != ways.end()) {
				cout << "this city already exists in the graph" << endl;
				m.ncity--;
			}
			else
			{
				cout << "Enter The connected citys and the weghit/if you finish press 0 0 : " << endl;
				while (true)
				{
					cin >> m.endw.first >> m.endw.second;
					unordered_map<string, vector<pair<string, double> > >::iterator its;
					if (m.endw.first == "0"&&m.endw.second == 0) { break; }
					its = ways.find(m.endw.first);
					if (its != ways.end()) {
						bool b = true;
						cout << (*m.it).second.size() << endl;
						for (int i = 0; i < (*m.it).second.size(); i++)
						{
							if ((*m.it).second[i].first == m.endw.first) { b = false; }
						}
						if (b)
							m.inf.push_back(m.endw);
						else
							cout << " this edge already belong to the city" << endl;
					}
					else {
						cout << " this city doesn't belong to the graph (add the city if you want to use it)" << endl;
					}
				}
				ways[m.start] = m.inf;
				m.inf.erase(m.inf.begin(), m.inf.end());
			}
		}
	}
	else if (n == 2)
	{
		cout << "Enter the city that you want add edges for it" << endl;
		string city;
		cin >> city;
		m.it = ways.find(city);
		if (m.it == ways.end()) {
			cout << "this city doesn't belong to the graph" << endl;
		}
		else
		{
			m.inf = (*m.it).second;
			cout << "enter the edge and the weight and 0 0 to finish" << endl;
			while (true)
			{
				cin >> m.endw.first >> m.endw.second;
				unordered_map<string, vector<pair<string, double> > >::iterator its;
				if (m.endw.first == "0"&&m.endw.second == 0) { break; }
				its = ways.find(m.endw.first);
				if (its != ways.end()) {
					bool b = true;
					cout << (*m.it).second.size() << endl;
					for (int i = 0; i < (*m.it).second.size(); i++)
					{
						if ((*m.it).second[i].first == m.endw.first) {b = false;}
					}
					if (b)
						m.inf.push_back(m.endw);
					else
						cout << " this edge already belong to the city" << endl;
				}
				else {
					cout << " this city doesn't belong to the graph (add the city if you want to use it)" << endl;
				}
			}
			ways[city] = m.inf;
			m.inf.erase(m.inf.begin(), m.inf.end());
		}
	}
	else if (n == 3)
	{
		cout << "Enter the city that you want update edge for it" << endl;
		string city;
		cin >> city;
		m.it = ways.find(city);
		if (m.it == ways.end()) {
			cout << "this city doesn't belong to the graph" << endl;
		}
		else
		{
			vector<pair<string, double> >vupdate;
			vupdate = (*m.it).second;
			cout << "Enter the edge that you want update for it" << endl;
			string edge;
			cin >> edge;
			cout << "Enter the weight for edge that you want update it" << endl;
			int weight;
			cin >> weight;
			for (int i = 0; i < vupdate.size(); i++)
			{
				if (vupdate[i].first == edge) { vupdate[i].second = weight; ways[city] = vupdate; break; }
			}
		}
	}
}
void inorder::deletee()
{
	cout << "press 1 if you want delete edge || press 2 if you want delete city" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "Enter the name of city that you want to delete edge inside it" << endl;
		string city, edge;
		cin >> city;
		cout << "Enter the name of edge" << endl;
		cin >> edge;
		delete_edge(city, edge);
	}
	if (n == 2)
	{
		cout << "Enter the name of city that you want to delete" << endl;
		string city;
		cin >> city;
		delete_city(city);
	}
}
void inorder::delete_edge(string city, string edge)
{
	vector<pair<string, double> >vdelete;
	m.it = ways.find(city);
	vdelete = (*m.it).second;
	for (int i = 0; i < vdelete.size(); i++)
	{
		if (vdelete[i].first == edge)
		{
			vdelete.erase(vdelete.begin()+i);
			break;
		}
	}
	ways[city] = vdelete;
}
void inorder::delete_city(string city)
{
	ways.erase(city);
	unordered_map<string, vector<pair<string, double> > >::iterator its;
	for (its = ways.begin(); its != ways.end(); its++) {
		delete_edge((*its).first, city);
	}
}
void inorder::display_date()
{
	cout << ways.size() << endl;
	for (m.it = ways.begin(); m.it != ways.end(); m.it++)
	{
		cout << (*m.it).first << endl;
		for (int i = 0; i < (*m.it).second.size(); i++)
		{
			cout << (*m.it).second[i].first << "    " << (*m.it).second[i].second << endl;
		}
	}
}
