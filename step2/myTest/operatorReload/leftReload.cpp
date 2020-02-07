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
};

Num &operator+(Num &n1, Num &n2)
{
	Num *temp;
	//temp.a = n1.a + n2.a;
	//temp.b = n1.b + n2.b;
	//
	temp->a = n1.a + n2.a;
	temp->b = n1.b + n2.b;

	//cout << "a = " << n1.a << "+" << n2.a << "=" << temp->a << endl;
	//cout << "b = " << n1.b << "+" << n2.b << "=" << temp->b << endl;
	return *temp;
}

ostream &operator<<(ostream &ut, Num &n)
{
	ut << "leftReload: " << "a = " << n.a << " b = " << n.b;
	return cout;
}


int main()
{
	Num n1(1,1);
	Num n2(2,2);
	Num n3;

        n3 = n1 + n2 + n1;
	n3.show();
	cout << n3 << endl;
	return 0;
}
