#ifndef __worker_h
#define __worker_h

#include <iostream>
#include <string>

#include "pause.h"

using namespace std;

class Worker
{
public:

	virtual void showInfo() = 0;

	virtual string getDeptName() = 0;

	virtual ~Worker() {}

	int m_Id;
	string m_Name;
	int m_DeptId;
};




#endif
