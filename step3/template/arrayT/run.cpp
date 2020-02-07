#include <iostream>
#include <string>

#include "myArray.hpp"
#include "pause.h"

using namespace std;

void test01()
{
	//int a1[5] = {1,0,3,4,5};
	MyArray<int>ma(5);
	//ma.m_Arr = a1;
	//ma = a1;
	ma.showArr();
	ma.showNum();

	MyArray<int>ma0(ma);
	//ma0 = ma;
	ma0.showArr();
	ma0.showNum();

	pause();
	exit(0);
}

void test02()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.addElement(i);
	}
	cout << "array1打印输出：" << endl;
	array1.showArr();
	array1.showNum();

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.delElement();
	cout << "array2打印输出：" << endl;
	array2.showArr();
	array2.showNum();

	pause();
	exit(0);
}

int main()
{
	//test01();
	
	test02();


	cout << "请选择输入数组的类型: " << endl;
	cout << "0、exit" << endl <<
		"1、int" << endl <<
		"2、float" << endl <<
		"3、double" << endl <<
		"4、char" << endl;
	int sel = 0;

	cin >> sel;
	switch (sel)
	{
	case 0:
		return 0;

		break;

	case 1:
		{
		MyArray<int>a1(5);
		cout << "请输入数组的值: " << endl;
		a1.setArr();
		a1.showArr();
		}

		break;

	case 2:
		{
		MyArray<float>a1(5);
		cout << "请输入数组的值: " << endl;
		a1.setArr();
		a1.showArr();
		}

		break;

	case 3: 
		{
		MyArray<double>a1(5);
		cout << "请输入数组的值: " << endl;
		a1.setArr();
		a1.showArr();
		}

		break;

	case 4: 
		{
		MyArray<char>a1(5);
		cout << "请输入数组的值: " << endl;
		a1.setArr();
		a1.showArr();
		}

		break;

	default:

		break;


	}


//	while (true)
//	{
//		MyArray<int>a1(5);
//
//		//*(a1.m_Arr) = {1,1,2,3,5};	//错误的赋值方式
//		//
//		a1.setArr();
//
//		a1.showArr();
//	}
//
	return 0;
}
