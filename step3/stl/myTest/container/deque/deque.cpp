#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d)
{
	cout << endl;
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " " ;
	}
	cout << endl;
}

void printVector(const vector<int> &v)
{
	cout << endl;
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	printDeque(d1);

	d1.resize(20);
	printDeque(d1);
	
	d1.resize(30,10);
	printDeque(d1);

	d1.resize(10);
	printDeque(d1);

	for (int i = 0; i < 10; i++)
	{
		d1.push_front(i);
	}

	printDeque(d1);

	d1.insert(d1.begin()+5,0);
	printDeque(d1);

	sort(d1.begin(),d1.end());
	printDeque(d1);

	vector<int> v;
	for (int i = 9; i >= 0; i--)
	{
		v.push_back(i);
	}
	printVector(v);

	sort(v.begin(), v.end());
	printVector(v);

}

int main()
{
	test();

	return 0;
}
