#include <iostream>
#include <map>

using namespace std;

class MyCompare
{
public:
	bool operator() (int v1, int v2)
	{
		return v1 > v2;
	}
};

void printMap(const map<int, int> &m)
{
	for (map<int, int>::const_iterator mit = m.begin(); mit != m.end(); mit++)
	{
		cout << endl;
		cout << "Key: " << mit->first << "\tValue: " << mit->second << endl;
		cout << endl;
	}

}

void printMap(const map<int, int, MyCompare> &m)
{
	for (map<int, int, MyCompare>::const_iterator mit = m.begin(); mit != m.end(); mit++)
	{
		cout << endl;
		cout << "Key: " << mit->first << "\tValue: " << mit->second << endl;
		cout << endl;
	}

}

void test()
{
	map<int, int> m;

	m.insert(pair<int, int> (2,20));
	m.insert(pair<int, int> (1,10));
	m.insert(pair<int, int> (4,40));
	m.insert(pair<int, int> (3,30));
	m.insert(pair<int, int> (5,50));

	m.insert(make_pair(6,60));
	m.insert(make_pair(9,90));
	m.insert(make_pair(7,70));
	m.insert(make_pair(8,80));

	m.insert( map<int, int>::value_type(10,100));

	m[11] = 110;


	printMap(m);

	map<int, int, MyCompare> m1;
	m1.insert(make_pair(6,60));
	m1.insert(make_pair(9,90));
	m1.insert(make_pair(7,70));
	m1.insert(make_pair(8,80));
	printMap(m1);


	cout << endl;
	map<int, int>::iterator mit = m.begin();
	//cout << "Key: " << mit->first << "\tValue: " << mit->second << endl;
	cout << (*mit).first << endl;

}

int main()
{
	test();

	return 0;
}
