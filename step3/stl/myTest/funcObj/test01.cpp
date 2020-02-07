#include <iostream>
#include <string>

using namespace std;

class MyPrint
{
public:
	int count = 0;

	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}

};

void doPrint(MyPrint &mp, string test)
{
	mp(test);
}

void test01()
{
	MyPrint mp;
	mp("good");
	mp("good");
	mp("good");
	mp("good");
	mp("good");
	cout << mp.count << endl;

}

void test02()
{
	MyPrint mp;
	doPrint(mp, "hello world * 2");
}

int main()
{
	test01();
	test02();

	return 0;
}
