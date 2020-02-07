#include <iostream>

using namespace std;

int g_a = 10;
int g_b = 10;

int main()
{
	int a = 10;
	int b = 10;

	static int s_a = 10;
	static int s_b = 10;


	cout << "局部变量a地址：" << &a << endl;
	cout << "局部变量b地址：" << &b << endl;

	cout << "全局变量a地址：" << &g_a << endl;
	cout << "全局变量b地址：" << &g_b << endl;

	cout << "静态变量a地址：" << &s_a << endl;
	cout << "静态变量b地址：" << &s_b << endl;

	return 0;
}

	

