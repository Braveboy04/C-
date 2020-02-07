#ifndef __room_h
#define __room_h

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

#include "pause.h"

#define DAYMENU 0
#define TIMEMENU 1

#define CHECKING 0
#define SUCCESS 1
#define FAIL 2

#define MORNING 0
#define AFTERNOON 1

using namespace std;

class Room
{
public:
	int m_Num;
	int m_Capacity;
	int m_Total;
	set<int> m_Record;
	//map<int, int> m_Record;
	multimap<int, pair<long, string>> all_Record;

	Room();

	void initRoom();
	void showRoomHead();
	void showRoom();
	void reserveMenu(int sel);
	int checkSel();
	int doReserve(int day, int time);
	void busyTime();
};

#endif
