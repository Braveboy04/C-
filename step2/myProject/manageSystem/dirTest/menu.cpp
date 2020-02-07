#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Member
{
public:
	int m_Num;
	char m_Name[64];
	char group;

};

class Boss : public Member
{

};

class Menu
{
public:
	virtual void func() = 0;

	virtual ~Menu() 
	{

	}
};

class addWorker : public Menu
{
public:
	virtual void func()
	{
		ofstream ofs("member.dat",ios::out | ios::binary | ios::app | ios::ate);
		//ofstream ofs("member.dat",ios::out | ios::binary | ios::app );
		
		Member *m = new Boss;
		cout << "请输入编号: ";
		cin >> m->m_Num;
		cout << "请输入姓名: ";
		cin >> m->m_Name;
		cout << "请输入部门编号: " << endl <<
			"a)老	板	" << endl <<
			"b)经	理	" << endl <<
			"c)普通员工 	" << endl;
		cin >> m->group;

		ofs.write((char *)m,sizeof(m));
		ofs.close();

		delete m;

		
	}

};

void showMenu()
{

}

void showMember(Member *m)
{

	ifstream ifs("member.dat", ios::in | ios::binary);

	if( !ifs.is_open() )
	{
		cout << "ERROR!" << endl;
	}
	cout << "open success" << endl;

	while( ifs.read((char *)m,sizeof(m)))
	{
		cout << m->m_Num << endl <<
			m->m_Name << endl <<
			m->group << endl;
	}

	ifs.close();



}

void run(Menu *m)
{
	m->func();
}

void test()
{
	Menu *m = new addWorker;
	run(m);


	delete m;

}


int main()
{
	test();
	
	Member *m = new Boss;

	showMember(m);

	delete m;
	
	return 0;
}

