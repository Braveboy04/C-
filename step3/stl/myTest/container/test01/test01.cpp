#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Person 
{
public:
	string m_Name;
	float m_Score;


	Person(string name, float score) : m_Name(name), m_Score(score) {}
};

void printVector(const vector<Person> &v)
{
	cout << endl;

	for (vector<Person>::const_iterator vi = v.begin(); vi != v.end(); vi++)
	{
		cout << endl;
		cout << "Name: " << vi->m_Name << "\tScore: " << vi->m_Score << endl;
		cout << endl;
	}

	cout << endl;
}
void test01()
{
	srand((unsigned int)time(NULL));
	vector<Person> v;

	Person p1("ming",0);
	Person p2("uzi",0);
	Person p3("xiaohu",0);
	Person p4("xlb",0);
	Person p5("langx",0);	

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	for (vector<Person>::iterator it = v.begin(); it !=  v.end(); it++)
	{
		cout << "请为选手 " << it->m_Name << " 打分: " << endl;
		deque<float> d;

		float temp;
		for (int i = 0; i < 10; i++)
		{
			temp = rand() % 41 + 60;
			d.push_back(temp);

		}

		//float temp;
		//for (int i = 0; i < 10; i++)
		//{
		//	cin >> temp;
		//	d.push_back(temp);
		//}


		//for ( int i = 0; i < 10; i++)
		//{
		//	d.push_back(i);
		//}

		sort(d.begin(),d.end());
		d.pop_back();
		d.pop_front();

		float total = 0;
		for (deque<float>::iterator di = d.begin(); di != d.end(); di++)
		{
			total += *di;
		}	
		
		it->m_Score = total / d.size();

		cout << "total = " << total << endl;
		cout << "score = " << total / d.size() << endl;
		cout << endl;
	}

	printVector(v);
}


int main()
{
	test01();

	return 0;
}
