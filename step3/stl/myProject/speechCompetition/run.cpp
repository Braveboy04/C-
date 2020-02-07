#include <iostream>

#include "speechManager.h"

int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;

	int sel;

	while(true)
	{
		sm.showMenu();
		cout << "请输入您的选择: " << endl;
		cin >> sel;

		switch(sel)
		{
		case 0:
			sm.exitSystem();

			break;

		case 1:
			sm.runCompelite();

			break;

		case 2:

			break;

		case 3:

			break;

		default:
			{
				cout << "输入错误！请重新输入！" << endl;
				pause();
				continue;
			}

			break;
		}
	}	


	return 0;
}
