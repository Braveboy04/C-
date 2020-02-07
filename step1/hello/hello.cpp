#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	const int cs = 20;
	int i = 10;
	float f = 3.1415926;
	char c = 'c';
	int ci = c;

	char str1[] = "hello world*1";
	string str2 = "hello world*2";

	bool bool1 = false;
	bool bool2 = true;

	cout << "aa" << i << cs << endl;
	cout << sizeof(int) << endl;
	cout<<sizeof(short)<< endl;
	cout<<sizeof(long)<< endl;
	cout<<sizeof(long long)<< endl;
	cout<<sizeof(i)<<endl;
	cout<<f<<endl;
	cout<<c<<ci<<endl;

	cout << str1 <<endl;
	cout << str2 << endl;
	cout << sizeof(str1) << endl;
	cout << sizeof(str2) << endl;

	cout << bool1 << endl;
	cout << bool2 << endl;
	cout << sizeof(bool1) << endl;


	cout << bool1 << endl;

	cout << "aaaa"
		"bbbb"
		"cccc"
		<< endl;

	cout << "1111"
	     << "2222"
	     << "3333"
	     << "4444" <<endl;

	cout << sqrt(2) << endl;

	cout << rand() << endl;

	int blank(0x10);
	cout << hex << blank << endl;

	int test01{0x10};
	cout << dec << test01 << endl;

//	cout << "Enter :____\b\b\b\b" ;
//	cin >> test01;
//	cout << dec << test01 << endl;

	cout << 'P' << endl;
	cout << sizeof('P') << endl;
	cout << U'P' << endl;
	cout << sizeof(U'P') << endl;

	float f1 = 1.23E+10F;
	cout << f1 << endl;

	string str;
	cin >> str;
	cout << str << endl;

	char strB[100];
	cin >> strB;
	cout << sizeof(strB) << endl;

	cout.put('!');
	cin.get();
	return 0;
}
