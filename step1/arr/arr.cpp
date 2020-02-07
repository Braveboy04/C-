#include <iostream>

using namespace std;

int main()
{
	int arr1[5] = { 1,2 } ;

	for (int i = 0; i < 5; i++)
		cout << arr1[i] << '\t';

	cout << endl;

	cout << sizeof(arr1) << endl;

	cout << arr1 << endl;

	return 0;
}
