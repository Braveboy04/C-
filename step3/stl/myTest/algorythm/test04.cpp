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
};

void printV(int val)
{
	cout << val << " ";
}

void printVP(Person &p)
{
	cout << "a = " << p.a << "\tb = " << p.b << endl;
}

bool LessFour(int val)
{
	return val < 4;
}

void test01()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for_each(v1.begin(), v1.end(), printV);
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;

	replace(v2.begin(), v2.end(), 1, 2);
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;

	replace_if(v2.begin(), v2.end(), LessFour, 4);
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for_each(v1.begin(), v1.end(), printV);
	cout << endl;
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	swap(v1,v2);
	for_each(v1.begin(), v1.end(), printV);
	cout << endl;
	for_each(v2.begin(), v2.end(), printV);
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}

void test02()
{
	vector<Person> vp;

	vector<Person> v1,v2;
	for(int i = 0; i < 10; i++)
	{
		Person p1(i, i + 1);
		Person p2(i + 4, i + 1);
		v1.push_back(p1);
		v2.push_back(p2);
	}

	for_each(v1.begin(), v1.end(), printVP);
}

void test03()
{
	vector<Person> vp;

	vector<Person> v1,v2;

	for (int i = 0; i < 10; i++)
	{
		Person p(i, i + 1);
		vp.push_back(p);
	}
	for_each(vp.begin(), vp.end(), printVP);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		if (v1.size() != (vp.size() / 2))
		{
			v1.push_back(*it);
		}

		if (v2.size() != (vp.size() / 2))
		{
			v2.push_back(*it);
		}
	}
	for_each(v1.begin(), v1.end(), printVP);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for_each(v2.begin(), v2.end(), printVP);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


}

void test04()
{
	vector<Person> vp;

	for (int i = 0; i < 10; i++)
	{
		Person p(i, i + 1);
		vp.push_back(p);
	}
	for_each(vp.begin(), vp.end(), printVP);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		cout << (int)(it - vp.begin()) << endl;
	}


}

int main()
{
	//test01();
	
	//test02();

	//test03();

	test04();

	return 0;
}
