#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Parent 
{
public:

	virtual void who() = 0;

	Parent()
	{
		cout << "Parent构造函数" << endl;
	}
	virtual ~Parent() 
	{
		cout << "Parent析构函数" << endl;
	}
};

class Son : public Parent 
{
public:
	string *m_Name;

	Son(string name)
	{
		m_Name = new string(name);
	
		cout << "Son构造函数" << endl;
	}

	virtual void who()
	{
		cout << endl;
		cout << *m_Name << "I'm son!" << endl;
		cout << endl;
	}

	~Son()
	{
		cout << "Son析构函数" << endl;
		if(m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}


};

void writeBin(Parent *s)
{
	ofstream ofs("test.dat",ios::out | ios::binary);
	//ofstream ofs;
	//ofs.open("test.dat",ios::out | ios::binary);
	ofs.write((const char *)s, sizeof(s));
	ofs.close();
}

void readBin(Parent *s)
{
	ifstream ifs("test.dat",ios::in | ios::binary);
	ifs.read((char *)s,sizeof(s));
	cout << Son::m_Name << endl;
	ifs.close();
}

void test()
{
	Parent *s1 = new Son("xiaoming");
	s1->who();
	writeBin(s1);
	readBin(s1);
	
	delete s1;

}

int main()
{
	test();

	return 0;
}

