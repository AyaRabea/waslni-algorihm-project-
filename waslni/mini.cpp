#include "mini.h"


mini::mini()
{
}


mini::~mini()
{
}
best::best()
{

	weight = numeric_limits<double>::max();
	pname = "_";
	ismarked = false;
}
unordered_map<string, vector<pair<string, double> > > mini::input()
{
	cout << "Please Enter number of citys: ";
	cin >> ncity;
	cout << endl;


	for (int i = 0; i < ncity; i++)
	{
		cout << "Please Enter the start city:" << endl;
		cin >> start;
		cout << "Enter The connected citys and the weghit/if you finish press 0 0 : " << endl;
		while (true)
		{
			cin >> endw.first >> endw.second;
			if (endw.first == "0"&&endw.second == 0) { break; }
			inf.push_back(endw);
		}
		wways[start] = inf;
		inf.erase(inf.begin(), inf.end());
	}
	return wways;
}
void mini::graph(unordered_map<string, vector<pair<string, double> > > w)
{
	wways = w;
	ncity = wways.size();
	cout << "start graph" << endl;
	cout << "Enter your Location :" << endl;
	cin >> mylocation;
	string begine = mylocation;

	int small = 0;

	for (it = wways.begin(); it != wways.end(); it++)
	{
		best object;
		object.name = (*it).first;
		if (object.name == mylocation) { object.weight = 0; object.ismarked = true; }
		bestway.push_back(object);
	}
	vector<pair<string, double> >v;
	for (int i = 0; i < ncity; i++)
	{
		it = wways.find(begine);
		v = (*it).second;
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < bestway.size(); k++)
			{
				if (v[j].first == bestway[k].name)
				{
					if ((v[j].second) + small < (bestway[k].weight))
					{
						bestway[k].weight = (v[j].second) + small;
						bestway[k].pname = begine;
					}
					break;
				}

			}
		}
		double min = numeric_limits<double>::max(); int index;
		bool b = false;
		for (int k = 0; k < bestway.size(); k++)
		{
			if (bestway[k].ismarked == false) {

				if (min > bestway[k].weight)
				{
					min = bestway[k].weight;
					begine = bestway[k].name;
					b = true;
					index = k;
				}
			}
		}
		if (small>min)
			small = min;
		if (b)
			bestway[index].ismarked = true;
		b = false;
	}

	cout << "end graph" << endl;

}
void mini::display() {

	int x;
	cout << "the shortest way : " << endl << endl;
	x = final.size();
	for (int i = 0; i <x; i++) {
		cout << final.top() << " -----> ";
		final.pop();
	}
	cout << " it takes time ( " << short_time << " ) " << endl << endl;
}
void mini::output(string destination)
{
	cout << "start output" << endl;
	final.push(destination);
	string find = destination;
	int numo = bestway.size();
	for (int i = 0; i < numo&&find != mylocation; i++)
	{
		cout << "LL" << endl;
		if (bestway[i].name == find)
		{
			final.push(bestway[i].pname);

			if (find == destination)
			{
				short_time = bestway[i].weight;
			}
			else short_time += bestway[i].weight;
			find = bestway[i].pname;
			i = -1;
		}

	}

	cout << "end output" << endl;
}