#include <iostream>
#include "add.h"

using namespace std;

int main()
{
	void c1(int a,int b,int c);
	void c2(int a,int b,int c);
	int a = 1;
	int b = 2;
	int c = 1;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	c1(a,b,c);
	c2(a,b,c);

	cout << add(a,b) << endl;
	
	cout << endl;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	cout << endl;
	return 0;
}

void c1(int a,int b,int c)
{
	c = (a++) + (++b) + (++c) + (++c);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}


void c2(int a,int b,int c)
{
	c = (a++) + (++b) + (c++) + (c++);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
