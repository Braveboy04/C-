#ifndef __speechManager_h
#define __speechManager_h

#include <iostream>

#include "speaker.h"
#include "pause.h"

using namespace std;

class SpeechManager
{
public:
	//成员属性
	vector<int> v1;
	
	vector<int> v2;

	vector<int> vVictory;
	
	map<int, Speaker> m_Speaker;

	//成员函数
	SpeechManager();

	~SpeechManager();

	void show_Menu();

	void exitSystem();

	void initSpeech();

	void createSpeaker();
};

#endif
