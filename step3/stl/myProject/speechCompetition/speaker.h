#ifndef __speaker_h
#define __speaker_h

#include <iostream>
#include <string>

using namespace std;

class Speaker
{
public:
	string m_Name;

	int m_Num;

	Speaker(string name, int num);
	
	~Speaker();

	void showInfo();


};

#endif
