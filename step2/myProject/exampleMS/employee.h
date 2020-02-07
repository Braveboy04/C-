#ifndef __employee_h
#define __employee_h

#include "worker.h"

using namespace std;

class Employee : public Worker
{
public:

	Employee(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDeptName();

};

#endif
