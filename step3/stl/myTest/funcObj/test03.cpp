#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

//class Person
//{
//public:
//	int a;
//	int b;
//	Person(int a, int b)
//	{
//		this->a = a;
//		this->b = b;
//	}
//};

void test01()
{
	negate<int> n;

	cout << n(50) << endl;

	plus<int> p;

	cout << p(10,20) << endl;
}

void test02()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " " ;
	}
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " " ;
	}
	cout << endl;

	//自定类型不可使用内建函数
	/*
	Person p1(4,5);
	Person p2(5,4);

	plus<Person> p;
	cout << p(p1,p2) << endl;
	*/

}

int main()
{
	//test01();
	//
	test02();
	
	return 0;
}
