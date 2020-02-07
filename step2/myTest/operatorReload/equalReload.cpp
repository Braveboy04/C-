#include <iostream>

using namespace std;

class Num
{
public:

	int *a;

	//Num();
	//Num(int a, int b):a(a),b(b){};
	
	Num(int b = 0)
	{
		a = new int(b);
		//*a = b;
		cout << "构造函数" << a << endl;
	}

	Num(const Num &n)
	{
		cout << "拷贝构造" << a << endl;
	}

	~Num()
	{
		cout << "析构函数前" << a << endl;
		if(a != NULL)
		{
			delete a;
			a = NULL;
		}
		cout << "析构函数后" << a << endl;
	}

	void show()
	{
		cout << "a = " << a << endl;
	}

	Num &operator=(const Num &n)
	{
		if( a != NULL )
		{
			delete a;
			a = NULL;
		}
		a = new int(*n.a);
		return *this;
	}

};

void test()
{
	Num n1(1);
	Num n2(2);
	Num n3(3);
    	n3 = n2 = n1;

	cout << n1.a << endl;
	cout << n2.a << endl;
	cout << n3.a << endl;
	cout << *n1.a << endl;
	cout << *n2.a << endl;
	cout << *n3.a << endl;

	//n2 = n1;
}


int main()
{
	test();

	return 0;
}
