#include <iostream>

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

void test()
{
	//Worker *worker = NULL;
	//
	//worker = new Employee(1,"张三",1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2,"李四",2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3,"牛斯",3);
	//worker->showInfo();
	//delete worker;

	//delete worker;
	//worker = NULL;
	//
	pause();

	exit(0);

}


int main()
{
	//test();

	WorkerManager wm;
	//if (wm.m_FileIsEmpty)
	//cout << "This is a test message: " << (bool)wm.m_FileIsEmpty << endl;

	int choice = 0;

	while (true)
	{
		wm.Show_Menu();

		cout << "请输入你的选择: " << endl;
		cin >> choice;

		switch(choice)
		{
			case 0:			//退出系统
				wm.exitSystem();

				break;

			case 1:			//添加职工
				wm.Add_Emp();

				break;

			case 2: 		//显示职工
				wm.Show_Emp();

				break;

			case 3:			//删除职工
				wm.Del_Emp();
				
				break;

			case 4:			//修改职工
				wm.Mod_Emp();

				break;

			case 5:			//查找职工
				wm.Find_Emp();

				break;

			case 6:			//排序职工
				wm.Sort_Emp();

				break;

			case 7:			//清空文件
				wm.Clean_File();

				break;

			default:
				cout << "输入错误！请按回车继续！" << endl;
				cin.get();
				cin.get();
				system("clear");
				break;

		}
	}

	cin.get();


	return 0;
}
