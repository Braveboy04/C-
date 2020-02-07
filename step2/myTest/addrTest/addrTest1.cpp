#include <iostream>

using namespace std;

int a;
int *funcA();
int *funcB(int &b);
int *funcC();
int &funcD();

int main()
{
	int a = 10;
	int b = 10;
	
	int *p = funcA();
	cout << *p << endl;
	cout << p << endl;

	int *pb = funcB(b);
	cout << *pb << endl;
	cout << pb << endl;

	int *pc = funcC();
	cout << *pc << endl;
	cout << pc << endl;

	int &ref = funcD();
	cout << ref << endl;
	cout << &ref << endl;
	funcD() = 20;
	cout << ref << endl;
	cout << &ref << endl;

	return 0;
}

int *funcA()
{
	a = 10;
	return &a;
}

int *funcB(int &b)
{
	b = 10;
	return &b;
}

int *funcC()
{
	int *p = new int(10);
	return p;
}

int &funcD()
{
	static int a = 10;
	return a;
}
