#include <iostream>
#include "bubble.h"

using namespace std;

void bubble(int arr[],int len)
{
	//int arr[9] = { 4,2,8,0,5,7,1,3,9 };

	int temp;

	for (int i = 0; i < len; i++)
		cout << arr[i] << '\t';
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j+1] )
			{
				temp = arr[j];
				arr[j] = arr [j+1];
				arr [j+1] = temp;
			}
		}
	}

	for (int i = 0; i < len; i++)
		cout << arr[i] << '\t';
	cout << endl;
}
