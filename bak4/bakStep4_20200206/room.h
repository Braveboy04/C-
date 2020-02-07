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
	set<int> m_Record;
	//multimap<int, pair<long, string>> m_Record;
	multimap<int, pair<long, string>> all_Record;

	Room();

	void initRoom();
	void showRoom();
	void reserveMenu(int sel);
	void checkSel();
	void doReserve(int day, int time);
	void busyTime();
	void tbusyTime();
};

#endif
