#include <iostream>

using namespace std;

struct T 
{
	int a;
	int b;
};

void printT(const T* p);

int main()
{
	T t1;
	T *p;
	p = &t1;
	t1.a = 10 ;
	t1.b = 20 ;

	cout << t1.a << '\t' << t1.b << endl;
	cout << (*p).a << '\t' << (*p).b << endl;
	cout << p->a << '\t' << p->b << endl;
	//cout << *(p->a) << '\t' << *(p->b) << endl;		//error
	cout << '!' << endl;

	printT(p);

	return 0;
}

void printT(const T* p)
{
	//p->a = 100;
	cout << p->a << '\t' << p->b << endl;
}
