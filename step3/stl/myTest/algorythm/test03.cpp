#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void printV(int val)
{
	cout << val << " " ;
}

void test01()
{
	srand((unsigned int)time(NULL));
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), printV);
	cout << endl;

	vector<int> v2(v);
	vector<int> v3;
	v3.resize(v.size() + v2.size());

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), printV);
	cout << endl;

	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), printV);
	cout << endl;

	sort(v.begin(), v.end());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), printV);
	cout << endl;

	reverse(v3.begin(), v3.end());
	for_each(v3.begin(), v3.end(), printV);
	cout << endl;

	random_shuffle(v3.begin(), v3.end());
	for_each(v3.begin(), v3.end(), printV);
	cout << endl;
}

int main()
{
	test01();

	return 0;
}
