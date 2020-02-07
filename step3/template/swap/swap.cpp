#include <iostream>

using namespace std;

template <typename T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 1;
	int b = 2;

	float c = 2;
	float d = 2.2;

	cout << "a = " << a << " b = " << b << endl;
	mySwap(a,b);
	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	mySwap<float>(c,d);
	cout << "c = " << c << " d = " << d << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "a = " << a << " b = " << b << endl;
	swap(a,b);
	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;
	swap(c,d);
	cout << "c = " << c << " d = " << d << endl;
	return 0;
}
