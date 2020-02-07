#ifndef __user_h
#define __user_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "room.h"
#include "pause.h"

#define STUDENTFILE "student.log"
#define ROOMFILE "room.log"

class User
{
public:

	long m_Num;
	string m_Name;
	string m_Password;

	vector<Room> *uvr;

	virtual void userMenu() = 0;
	virtual void checkSel() = 0;

	void toDo();
	void loadRoom(vector<Room> &vr);
	void saveRoom();
	void logout();
	bool operator==(const User &u);
};

class Student : public User
{
public:
	virtual void userMenu();
	virtual void checkSel();

	void doReserve();
	void showMyReserve();
	void showAllReserve();
	void cancleReserve();


};

class Teacher : public User
{
public:
	virtual void userMenu();
	virtual void checkSel();

	void showAllReserve();
	void checkReserve();
};

class Admin : public User 
{
public: 
	virtual void userMenu();
	virtual void checkSel();

	void addUser();
	void showUsers();
	void showRoom();
	void delAllReserve();
};


#endif
