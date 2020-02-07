#include <iostream>
#include <list>
#include <string>
#include <ctime>

using namespace std;

class Person
{
public:
	string m_Name;
	int m_Age;
	int m_Height;


	Person(string name, int age, int height) : m_Name(name), m_Age(age), m_Height(height) {}

};

void printList(const list<Person> &l)
{
	cout << endl;
	for (list<Person>::const_iterator li = l.begin(); li != l.end(); li++)
	{
		cout << endl;
		cout << "Name: " << li->m_Name << endl <<
			"Age: " << li->m_Age << endl << 
			"Heigh: " << li->m_Height << endl;
		cout << endl;

	}
	cout << endl;
}

////方法一：重载小于号<
//bool operator<(const Person &p1, const Person &p2)
//{
//	if (p1.m_Age < p2.m_Age)
//		return true;
//	else if (p1.m_Age == p2.m_Age && p1.m_Height > p2.m_Height)
//		return true;
//	else 
//		return false;
//}

//方法二：指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
	if (p1.m_Age == p2.m_Age)
		return p1.m_Height > p2.m_Height;
	else 
		return p1.m_Age < p2.m_Age;
}

void test()
{
	srand((unsigned int)time(NULL));

	Person p1("ming",20,169);
	Person p2("uzi",21,170);
	Person p3("xiaohu",21,171);

	list<Person> l;
	
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	
	l.sort(comparePerson);

	printList(l);
}

int main()
{
	test();

	return 0;
}
