#ifndef __room_h
#define __room_h

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

#include "pause.h"

#define DAYMENU 0
#define TIMEMENU 1

using namespace std;

class Room
{
public:
	int m_Num;
	int m_Capacity;
	int m_Total;
	map<int, bool> m_Data;		//用于寻找已被预约日期
	multimap<pair<long, string>, pair<int, bool>> m_Record;
	multimap<pair<long, string>, pair<int, bool>> all_Record;
	//set<int> busy;
	//set<int> free;

	//int m_ReserveDay;
	//int m_ReserveTime;

	Room();

	void initRoom();
	void showRoom();
	void getData();
	void reserveMenu(int sel);
	void checkSel();
	void doReserve(int day, int time);
	//void findBusyOrFree();
	void busyTime();
	void tbusyTime();
	//void freeTime();
};

bool reserveDataCompare(const pair<pair<long, string>, pair<int, bool>> &p1, const pair<pair<long, string>, pair<int, bool>> &p2);

#endif
