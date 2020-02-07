#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

class Worker 
{
public:
	string m_Name;
	int m_Salary;

};

void creatWorker(vector<Worker> &v)
{

	int salary = 0;
	string nameSeed = "ABCDEFFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		salary = rand() % 10000 + 10000;
		Worker w;
		string name = "员工";
		name += nameSeed[i];
		w = {name, salary};
		v.push_back(w);
		//cout << (--v.end())->m_Salary << endl;
	}
	

}

void creatMap(const vector<Worker> &v, multimap<int, Worker> &m)
{
	int group = 0;
	
	for (vector<Worker>::const_iterator vit = v.begin(); vit != v.end(); vit++)
	{
		group = rand() % 3;
		m.insert(make_pair(group, *vit));
	}
	cout << "success" << endl;
}

void showWorker(const multimap<int, Worker> &m)
{
	cout << "部门A: " << endl;
	int num = 0;
	for (multimap<int, Worker>::const_iterator mit = m.find(0); mit != m.end(), num < m.count(0); mit++, num++)
	{
		cout << "Name: " << mit->second.m_Name << "\tSalary: " << mit->second.m_Salary << endl;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "部门B: " << endl;
	num = 0;
	for (multimap<int, Worker>::const_iterator mit = m.find(1); mit != m.end(), num < m.count(1); mit++, num++)
	{
		cout << "Name: " << mit->second.m_Name << "\tSalary: " << mit->second.m_Salary << endl;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "部门C: " << endl;
	num = 0;
	for (multimap<int, Worker>::const_iterator mit = m.find(2); mit != m.end(), num < m.count(2); mit++, num++)
	{
		cout << "Name: " << mit->second.m_Name << "\tSalary: " << mit->second.m_Salary << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	vector<Worker> vw;

	creatWorker(vw);

	multimap<int, Worker> vm;

	creatMap(vw,vm);

	showWorker(vm);
	
	return 0;
}
