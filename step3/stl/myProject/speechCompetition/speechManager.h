#ifndef __speechManager_h
#define __speechManager_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>

#include "speaker.h"
#include "pause.h"

#define FILENAME "log.csv"

class SpeechManager
{
public:

	SpeechManager();

	~SpeechManager();

	void showMenu();

	void runCompelite();

	void createSpeaker(vector<Speaker> &vs);

	void showRecord();

	void delRecord();

	void exitSystem();

};

void printV(Speaker &sp);

void showVP(vector<Speaker> &p);

void nextPart(vector<Speaker> &p);

void pushAFromB(vector<Speaker> &targetV, vector<Speaker> &v1);

bool mySort(Speaker &p1, Speaker &p2);

void showResult(vector<Speaker> &v);

void save(const vector<Speaker> &v);
#endif
