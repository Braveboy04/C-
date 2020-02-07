#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	
	cout << "三位数的水仙花数有：" << endl;

	int i = 100;
	do
	{
		a = i / 100;
		b = (i - a * 100) / 10;
		c = (i - a * 100 - b * 10);
		if (a * a * a + b * b * b + c * c * c == i)
			cout << i << endl;
		i++;
	}while(i < 1000);

	return 0;
}
