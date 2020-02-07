#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void printV(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);	//0是初始值

	cout << "total = " << total << endl;

	vector<int> v2;
	v2.resize(10);
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;
	fill(v2.begin(), v2.end(), 9);
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;



}

int main()
{
	test01();

	return 0;
}
