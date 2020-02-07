#include <iostream> 

using namespace std;

int &func(int &a, int &b);

int main()
{
	int a = 1;
	int b = 2;
        int &p = func(a,b);
	cout << p << endl;

	return 0;
}

int &func(int &a, int &b)
{
	static int c;
	c = a + b;
	return c;
}
