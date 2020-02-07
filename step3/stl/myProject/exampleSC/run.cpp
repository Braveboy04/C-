#include <iostream>

#include "speechManager.h"
#include "pause.h"

using namespace std;

int main()
{
	SpeechManager sm;

	int choice = 0; //用来存储用户的选项

	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice)
		{
		case 1:  //开始比赛
			break;

		case 2:  //查看记录
			break;

		case 3:  //清空记录
			break;

		case 0:  //退出系统
			sm.exitSystem();
			break;

		default:
			system("clear"); //清屏
			break;
		}
	}

	pause();

	return 0;
}
