#ifndef __member_h
#define __menber_h

#include <iostream>
#include <string>

using namespace std;

class Member
{
public:
	int m_Num;
	string m_Name;
	string m_Work;

	virtual void work() = 0;

};

class Boss : public Member
{
public:
	virtual void work();
};

class Manager : public Member
{
public:
	virtual void work();
};

class Worker : public Member
{
public:
	virtual void work();
};



#endif
