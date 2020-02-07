#include <iostream>

using namespace std;

class Person
{
	int a = 1;

public:
	Person():a(05)
	{
		cout << a << "无参构造" << endl;
	}

	Person(int b):a(b)
	{
		//a = b;
		cout << a << "有参构造" << endl;
	}
	
	Person(const Person &p)
	{
		a = p.a;
		cout << a << "拷贝构造" << endl;
	}

	~Person()
	{
		cout << a << "析构函数" << endl;
	}
};

void cp(Person p)
{
	cout << "void cp" << endl;
}

Person cp()
{
	Person cp(20);
	cout << "Person cp" << endl;
	return cp;
}

void test()
{
	Person a;
	Person b(10);
	Person c(a);
	Person d = 11;
	Person e = Person(12);
	cp(e);
	Person f = cp();
}

int main()
{
	test();
	cout << sizeof(Person) << endl;

	return 0;
}
