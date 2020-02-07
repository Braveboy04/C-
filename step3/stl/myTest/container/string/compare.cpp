#include <iostream>
#include <string>

using namespace std;

int sizeOfStr(string &str)
{
	return str.size();
}

void test01()
{
	//string str1 = "iello";
	string str1;
	str1 = "hello";
	string str2 = "hfllo";

	if (str1.compare(str2) == 0)
	{
		cout << "str1 = str2" << endl;
	}
	else if ( str2.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else 
	{
		cout << "str1 < str2" << endl;
	}

	cout << endl;
	cout << str1.size() << endl;
	cout << sizeOfStr(str1) << endl;
	cout << endl;

}

int main()
{
	test01();

	return 0;
}
