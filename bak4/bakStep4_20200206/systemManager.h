#ifndef __systemManager_h
#define __systemManager_h

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

#include "pause.h"
#include "user.h"
#include "room.h"

#define ROOMFILE "room.log"
#define STUDENTFILE "student.log"
#define TEACHERFILE "teacher.log"
#define ADMINFILE "admin.log"

using namespace std;

class SystemManager
{
public:
	//map<int, int> Room[3];

	vector<Room> vr;

	set<Room> sr;

	vector<Student> vs;

	vector<Teacher> vt;

	vector<Admin> va;

	bool usersFileIsEmpty;

	bool studentFileIsEmpty;

	bool teacherFileIsEmpty;

	bool adminFileIsEmpty;

	bool roomFileIsEmpty;

	SystemManager();		//功能基本完成

	~SystemManager();		//功能基本完成

	void systemMenu();		//功能基本完成

	void exitSystem();		//功能基本完成

	void adminLogin();		//功能基本完成

	void studentLogin();		//功能基本完成

	void teacherLogin();		//功能基本完成

	void initUser();		//功能基本完成

	void loadRoom();		//功能基本完成

	void loadStudent();		//功能基本完成

	void loadTeacher();		//功能基本完成

	void loadAdmin();		//功能基本完成

	void saveStudent();		//功能基本完成

	void saveTeacher();		//功能基本完成

	void saveAdmin();		//功能基本完成

	void saveRoom();		//功能基本完成

	void showRoom(Room &r);
};

bool r_Sort(const Room &r1, const Room &r2);



#endif
