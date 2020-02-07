#include <iostream>
#include <set>

using namespace std;

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void printSet(const set<int> &s)
{
	cout << endl;
	for (set<int>::const_iterator si = s.begin(); si != s.end(); si++)
	{
		cout << *si << " " ;
	}
	cout << endl;
	cout << endl;
}

void printSet(const set<int, MyCompare> &s)
{
	cout << endl;
	for (set<int, MyCompare>::const_iterator si = s.begin(); si != s.end(); si++)
	{
		cout << *si << " " ;
	}
	cout << endl;
	cout << endl;
}

void test()
{
	set<int> s1;

	for (int i = 0; i < 10; i++)
	{
		s1.insert(i);
	}

	s1.insert(-1);
	s1.insert(5);
	s1.insert(10);

	printSet(s1);

	set<int> s2(s1);
	printSet(s2);

	set<int,MyCompare> s3;

	for (int i = 0; i < 10; i++)
	{
		s3.insert(i);
	}

	s3.insert(-1);
	s3.insert(5);
	s3.insert(10);
	//s3 = s2;
	printSet(s3);

	set<int, MyCompare> s4;
	s4 = s3;
	printSet(s4);

	if (s1.find(0) != s1.end())
		cout << "找到元素: " << *s1.find(0) << endl;
	else
		cout << "不存在该元素!" << endl;

	cout << s1.count(5) << endl;



}

int main()
{
	test();

	return 0;
}
