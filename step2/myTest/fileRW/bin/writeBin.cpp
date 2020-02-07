#include <iostream>
#include <fstream>
#include <string>

//说明：创建对象为非指针时可以正常写入写出包括追加写入，创建对象为指针时出错，待调试

using namespace std;

class Person 
{
public:

	string m_Name;
	int m_Age;
};

class SPerson : public Person
{
public:


};

void test01()
{
	ofstream ofs("person.txt",ios::out | ios::binary);

	Person p = {"xiaoming", 18};

	ofs.write((const char*)&p, sizeof(p));

	ofs.close();
}

void test02()
{
	ifstream ifs("person.txt", ios::in | ios::binary);

	if (!ifs.is_open()) 
	{
		cout << "ERROR!" << endl;

		return;
	}

	Person p;

	ifs.read((char*)&p, sizeof(p));
	cout << endl;
	cout << &p << endl;
	cout << "Name: " << p.m_Name <<
	       endl << 
	       "Age: " << p.m_Age << endl;
	cout << endl;

	ifs.read((char*)&p, sizeof(p));
	cout << endl;
	cout << &p << endl;
	cout << "Name: " << p.m_Name <<
	       endl << 
	       "Age: " << p.m_Age << endl;
	cout << endl;

	ifs.close();
}

void test03()
{
	ofstream ofs("person.txt",ios::out | ios::binary | ios::app | ios::ate);

	Person p = {"xiaohong", 18};

	ofs.write((const char*)&p, sizeof(p));

	ofs.close();
}

int main()
{
	test01();
	test02();
	test03();
	cout << "~~~~~~~~~~~~~~" << endl;
	test02();
	return 0;
}
