#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	string m_Name;
	int m_Age;

	Person(string name, int age) : m_Name(name), m_Age(age) {}

	void showInfo()
	{
		cout << endl;
		cout << "Name: " << m_Name << " Age: " << m_Age << endl;
		cout << endl;
	}

};

void test()
{
	vector<vector<Person>> v;

	Person p1("ming",20);
	Person p2("uzi",20);
	Person p3("xiaohu",20);

	Person p4("Flandro",21);
	Person p5("xuanxuanxuan",22);
	Person p6("TS",20);

	vector<Person> v1;
	vector<Person> v2;
	vector<Person> v3;

	v1.push_back(p1);
	v1.push_back(p2);

	v2.push_back(p3);
	v2.push_back(p4);

	v3.push_back(p5);
	v3.push_back(p6);
	
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<Person>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<Person>::iterator p = it->begin(); p != it->end(); p++)
		{
			p->showInfo();
		}
	}


}

int main()
{
	test();

	return 0;
}
