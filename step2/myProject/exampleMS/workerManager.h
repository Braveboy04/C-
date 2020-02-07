#ifndef __workerManager_h
#define __workerManager_h

#include <iostream>
#include <fstream>

#include "worker.h"
#include "pause.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager
{
public:
	int m_EmpNum;

	bool m_FileIsEmpty;

	Worker ** m_EmpArray;

	WorkerManager();

	~WorkerManager();

	void Show_Menu();

	void exitSystem();

	void Add_Emp();

	void save();

	int get_EmpNum();

	void init_Emp();

	void Show_Emp();

	int IsExist(int id);

	void Del_Emp();

	void Mod_Emp();

	void Find_Emp();

	void Sort_Emp();

	void Clean_File();

};

#endif
