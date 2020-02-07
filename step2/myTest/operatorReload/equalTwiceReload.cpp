#include <iostream>

using namespace std;

class Num
{
public:

	int a;
	int b;

	//Num();
	//Num(int a, int b):a(a),b(b){};
	
	Num(int a = 0, int b = 0):a(a),b(b)
	{
		cout << "构造函数" << a << '\t' << b << endl;
	}

	Num(const Num &n)
	{
		cout << "拷贝构造" << a << '\t' << b << endl;
	}

	~Num()
	{
		cout << "析构函数" << a << '\t' << b << endl;
	}

	void show()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}

	bool operator==(const Num &n2)
	{
		if (a == n2.a && b == n2.b)
			return true;
		else
			return false;
	}

};

//bool operator==(const Num &n1, const Num &n2)
//{
//	if (n1.a == n2.a && n1.b == n2.b)
//		return true;
//	else
//		return false;
//}

void test()
{
	Num n1(1,2);
	Num n2(1,2);
	if (n1 == n2)
		cout << " n1 = n2 " << endl;

}

int main()
{
	test();

	return 0;
}
