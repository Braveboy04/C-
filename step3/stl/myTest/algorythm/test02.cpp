#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Person 
{
public:
	int a;
	int b;

	Person(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	bool operator==(const Person &p)
	{
		if (this->a == p.a && this->b == p.b)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};

class GreaterThree
{
public:
	bool operator()(const Person &p)
	{
		return (p.a + p.b) > 3;
	}
};

bool GreaterFour(const Person &p)
{
	if ((p.a + p.b) > 4)
	{
		return true;
	}
	else 
		return false;
}


void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	v.insert(v.begin() + 5, 2, 5);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	if (adjacent_find(v.begin(), v.end()) != v.end())
	{
		cout << "找到对象" << endl;
	}
	else 
	{
		cout << "没有找到对象" << endl;
	}

	bool if_7 = binary_search(v.begin(), v.end(), 7);
	if(if_7)
	{
		cout << "找到对象" << endl;
	}
	else 
	{
		cout << "没有找到对象" << endl;
	}


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	vector<Person> vp;

	Person p1(1,2);
	Person p2(2,3);
	Person p3(3,4);
	Person p4(4,5);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	
	for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		cout << "a = " << it->a << "\tb = " << it->b << endl;
	}

	Person pp(3,4);

	vector<Person>::iterator it = find(vp.begin(), vp.end(), pp);
	if (it != vp.end())
	{
		cout << "找到对象" << endl;
	}
	else 
	{
		cout << "没有找到对象" << endl;
	}

	it = find_if(vp.begin(), vp.end(), GreaterThree());
	if (it != vp.end())
	{
		cout << "找到对象" << endl;
	}
	else 
	{
		cout << "没有找到对象" << endl;
	}

	it = find_if(vp.begin(), vp.end(), GreaterFour);
	if (it != vp.end())
	{
		cout << "找到对象" << endl;
	}
	else 
	{
		cout << "没有找到对象" << endl;
	}

	int num = count(vp.begin(), vp.end(), pp);
	cout << "找到和pp(3,4)相等的元素个数为: \t" << num << endl;

	num = count_if(vp.begin(), vp.end(), GreaterThree());
	cout << "找到总和大于3的元素个数为: \t" << num << endl;

	num = count_if(vp.begin(), vp.end(), GreaterFour);
	cout << "找到总和大于4的元素个数为: \t" << num << endl;
}

int main()
{
	test01();

	return 0;
}
