#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printV(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 4);
	}

	for_each(v1.begin(), v1.end(), printV);
	cout << endl;
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, printV);
	cout << endl;

	fill(v3.begin(), v3.end(), 0);
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, printV);
	cout << endl;

	fill(v3.begin(), v3.end(), 0);
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, printV);
	cout << endl;
	
	fill(v3.begin(), v3.end(), 0);
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
	for_each(v3.begin(), itEnd, printV);
	cout << endl;
}

int main()
{
	test01();


	return 0;
}
