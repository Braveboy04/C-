#include <iostream>
#include <fstream>

const int SIZE = 2;

using namespace std;

class P
{
public:
	virtual void showInfo() = 0;

};

class Q : public P
{
public:
	int ma;
	int mb;

	Q(int a, int b):ma(a),mb(b) {}

	void showInfo()
	{
		cout << "ma = " << ma << endl << 
			"mb = " << mb << endl;

	}

};

//void save()
//{
//	int sel;
//	P** PArray = new *P[2];
//	P[0] = new Q(1,2);
//	P[1] = new Q(3,4);
//
//	ofstream ofs("test.txt", ios::out);
//	for (int i = 0; i < 2; i++)
//	{
//		ofs >> P[i]->a >> " " >> P[i]->b >> endl;
//
//	}
//
//
//
//	ofs.close();
//	delete [] PArray;
//	
//
//}


void test01()
{
	ofstream ofs;
	
	ofs.open("test.txt",ios::out);

	ofs << "This is a test!" << endl;
	ofs << "So am I!" << endl;

	ofs.close();

}

int main()
{
	test01();

	return 0;
}
