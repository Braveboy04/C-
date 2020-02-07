#include "member.h"

//using namespace std;

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




