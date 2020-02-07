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
	void getMyReserve();
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
	void delReserve(vector<Room>::iterator &it, pair<int, pair<long, string>> &tempPair, int realTime);


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
private:
	bool *sbp;
	bool *tbp;
	bool *abp;

	vector<Student> *vsp;
	vector<Teacher> *vtp;
	vector<Admin> *vap;
public: 
	virtual void userMenu();
	virtual void checkSel();

	void loadBool(bool &sb, bool &tb, bool &ab);
	void loadUsers(vector<Student> &vs, vector<Teacher> &vt, vector<Admin> &va);
	void addUser();
	void showUsers();
	void showStudent();
	void showTeacher();
	void showAdmin();
	void saveUser();
	void showRoom();
	void delAllReserve();
};


bool myRecordCompare(const pair<int, pair<long, string>> &p1, const pair<int, pair<long, string>> &p2);


#endif
