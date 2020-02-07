#include <iostream>

using namespace std;

int main()
{
	int a;

	cout << "请输入一个三位数: " << endl;
	cin >> a;

	do	
	{
		if(a < 100 || a > 999)
		{
			cout << "\n输入错误，请重新输入！" << endl;
			cout << "请输入一个三位数：" << endl;
			cin >> a;
		}
	}
	while (a < 100 || a > 999);

//	for (int i = 100;i < 1000;i++)
//	{
//		if (a / 100
//
	return 0;
}

