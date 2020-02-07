#include <iostream>
#include <string>

using namespace std;

struct Student 
{
	string name;
	int score;
};

struct Teacher
{
	string name;
	Student stu[2];
};

void printStu(const Student* s);
void printTea(const Teacher* t);

int main()
{
	Teacher tea[2];
	tea[0] = {"t1","t1s1",90,"t1s2",91};
	cout << "tea1ok!" << endl;
	tea[1] = {"t2","t2s1",92,"t2s2",89};
	cout << "tea2ok!" << endl;

	printTea(&tea[0]);
	printTea(&tea[1]);


	return 0;
}


void printStu(const Student* s)
{
	cout << "姓名：" << s->name << endl 
	     <<	"成绩：" << s->score << endl;
}

void printTea(const Teacher* t)
{
	cout << "姓名：" << t->name << endl;
	for (int i = 0; i < 2; i++)
	{
		printStu(&(t->stu[i]));
		cout << endl;
	}
}
