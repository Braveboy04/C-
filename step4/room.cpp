#include "room.h"

Room::Room()
{
	this->initRoom();
}

void Room::initRoom()
{
	this->m_Num = 0;
	this->m_Capacity = 0;
	this->m_Total = 0;

}

void Room::showRoomHead()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "机房号: " << this->m_Num << endl;
	cout << "机房容量: " << this->m_Capacity << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
}

void Room::showRoom()
{
	this->showRoomHead();
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "预约情况: " << endl;
	this->busyTime();
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
}

void Room::reserveMenu(int sel)
{
	if (sel == 0)
	{
		cout << "请输入要预约的工作日: " << endl;
		cout << "1) 周一 " << endl;
		cout << "2) 周二 " << endl;
		cout << "3) 周三 " << endl;
		cout << "4) 周四 " << endl;
		cout << "5) 周五 " << endl;
	}
	else if (sel == 1)
	{
		cout << "请输入要预约的时间段: " << endl;
		cout << "1) 上午 " << endl;
		cout << "2) 下午 " << endl;
	}
}

int Room::checkSel()
{
	int day;
	int time;
	this->reserveMenu(DAYMENU);
	cin >> day;
	switch (day)
	{
	case 1:
		{
			this->reserveMenu(TIMEMENU);
			cin >> time;
			return this->doReserve(day, time);
		}
		break;

	case 2:
		{
			this->reserveMenu(TIMEMENU);
			cin >> time;
			return this->doReserve(day, time);
		}
		break;

	case 3:
		{
			this->reserveMenu(TIMEMENU);
			cin >> time;
			return this->doReserve(day, time);
		}
		break;

	case 4:
		{
			this->reserveMenu(TIMEMENU);
			cin >> time;
			return this->doReserve(day, time);
		}
		break;

	case 5:
		{
			this->reserveMenu(TIMEMENU);
			cin >> time;
			return this->doReserve(day, time);
		}
		break;

	default:
		{
			cout << "输入错误，请重新预约！ " << endl;
			return -1;
		}
		break;
	}
}

int Room::doReserve(int day, int time)
{
	int realTime = (day - 1) * 2 + time - 1;
	set<int>::iterator it = m_Record.find(realTime);
	if (it != m_Record.end())
	{
		cout << "您所预约的时间段已预约，请重新选择预约时间！ " << endl;
		return realTime;
	}
	else
	{
		m_Record.insert(realTime);
		cout << "预约成功！请耐心等待老师审核！" << endl;
		m_Total++;	//预约数目增加，方便从记录文件中读取记录
		return realTime;
	}
}

void Room::busyTime()
{
	if (all_Record.size() == 0)
	{
		cout << "No Data!" << endl;
		return;
	}
	for (multimap<int, pair<long, string>>::iterator it = all_Record.begin(); it != all_Record.end(); it++)
	{
		int day = it->first / 2 + 1;
		int time = it->first % 2;
		long num = it->second.first;
		string name = it->second.second;

		if (time == 0)
		{
			cout << num << '\t' << name << '\t' << "day " << day << " morning\tchecking" << endl;
		}
		else if (time == 1)
		{
			cout << num << '\t' << name << '\t' << "day " << day << " afternoon\tchecking" << endl;
		}
	}
}

bool reserveDataCompare(const pair<pair<long, string>, pair<int, bool>> &p1, const pair<pair<long, string>, pair<int, bool>> &p2)
{
	if (p1.second.first == p2.second.first && p1.second.second == p2.second.second)
		return true;
	else 
		return false;
}

