#include <iostream>
#include "bubble.h"

using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	const int* p = &a;

	p = &b;
	cout << *p << endl;

	cout << "Please enter an array: ";
	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	bubble(arr,5);
	
	for (int i = 0; i < 5; i++)
		cout << arr[i];
	cout << endl;

	return 0;
}
