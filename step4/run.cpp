#include <iostream>

#include "systemManager.h"
#include "pause.h"

using namespace std;

void test()
{
	SystemManager sm;
	sm.studentLogin();

	exit(0);
}

int main()
{
	//test();

	system("clear");

	SystemManager sm;

	while (true)
	{
		sm.systemMenu();

		int sel;
		cin >> sel;

		switch(sel)
		{
		case 0:
			sm.exitSystem();

			break;

		case 1:
			sm.studentLogin();

			break;

		case 2:
			sm.teacherLogin();

			break;

		case 3:
			sm.adminLogin();

			break;

		default:

			break;

		}

	}

	return 0;
}
