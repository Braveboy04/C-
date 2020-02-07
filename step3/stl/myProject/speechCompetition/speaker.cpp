#include "speaker.h"

Speaker::Speaker(string name, int num) : m_Name(name), m_Num(num)
{

}

Speaker::~Speaker()
{

}

void Speaker::showInfo()
{
	cout << "Num: " << m_Num << "\tName: " << m_Name << endl;
}
