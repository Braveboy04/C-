#include <iostream>

using namespace std;

void test()
{
	int arr[5] = {1,1,2,3,4};
	int len = 0;
	
	len = sizeof(arr) / sizeof(*arr);	


	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << *(arr+i) << '\t';
	}
	cout << endl;
	cout << endl;


}

int& operator=(int *arr1, int *arr2)
{
	int len1 = 0;
	int len2 = 0;
	len1 = sizeof(arr1) / sizeof(*arr1);
	len2 = sizeof(arr2) / sizeof(*arr2);
	if (len1 != len2)
	{
		cout << "Error!" << endl;
		return;
	}

	for (int i = 0; i < len1; i++)
	{
		*(arr1+i) = *(arr2+i);
	}

	return arr1;


}

int main()
{
	test();

	return 0;

}
