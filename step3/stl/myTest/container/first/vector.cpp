#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrint(int val)
{
	cout << val << '\t';
}

void test()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << endl;
	cout << "This is an array: " << endl;
	cout << endl;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	cout << endl;

	v.pop_back();

	//第一种遍历容器的方法
	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//cout << endl;
	//cout << "This is an array: " << endl;
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << '\t';
	//	itBegin++;
	//}
	//cout << endl;
	//cout << endl;

	//第二种遍历容器的方法
	//cout << endl;
	//cout << "This is an array: " << endl;
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << '\t';
	//}	
	//cout << endl;
	//cout << endl;

	//第三种遍历容器的方法
	cout << endl;
	cout << "This is an array: " << endl;
	cout << endl;
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	cout << endl;
}

int main()
{
	test();

	return 0;
}
