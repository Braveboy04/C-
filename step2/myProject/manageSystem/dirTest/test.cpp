#include <iostream>
#include <string>

using namespace std;

class Member
{
public:
	int m_Num;
	string m_Name;
	string m_Work;

	virtual void work() = 0;

};

class Boss : public Member
{
public:
	virtual void work();
};

class Manager : public Member
{
public:
	virtual void work();
};

class Worker : public Member
{
public:
	virtual void work();
};


void Boss::work()
{
	        cout << "管理公司所有事务." << endl;
}

void Manager::work()
{
	        cout << "完成老板交给的任务，并下发任务给员工." << endl;
}

void Worker::work()
{
	        cout << "完成经理交给的任务." << endl;
}

void test()
{
	Boss b1;
	b1.work();
}

int main()
{
	test();

	return 0;
}

