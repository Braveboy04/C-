#include <iostream>

using namespace std;

template <class T>
void bubbleT(T *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (*(arr+i) > *(arr+j))
			{
				T temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

template <class T>
void mySort(T *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i+1; j < len; j++)
		{
			max = *(arr+i) < *(arr+j) ? max : j;
		}
		if (max != i)
		{
			T temp = *(arr+i);
			*(arr + i) = *(arr + max);
			*(arr + max) = temp;
		}
	}
}

template <> void mySort(char *arr, int len)
{
	cout << "reloading" << endl;
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i+1; j < len; j++)
		{
			max = *(arr+i) < *(arr+j) ? max : j;
		}
		if (max != i)
		{
			char temp = *(arr+i);
			*(arr + i) = *(arr + max);
			*(arr + max) = temp;
		}
	}
}

template <class T>
void showArr(T *arr, int len)
{
	cout << endl;
	cout << "This is an array: " << endl;
	for (int i = 0; i < len; i++)
	{
		cout << *(arr+i) << '\t';
	}
	cout << endl;
	cout << endl;
}


void test()
{
	int p[5] = { 1, 2, 4, 9, 3};
	int len = sizeof(p)/sizeof(int);
	showArr(p,len);
	bubbleT(p,len);
	showArr(p,len);
	mySort(p,len);
	showArr(p,len);

	char q[5] = { 'a', 'A', 'i', 'Q', 'b'};
	len = sizeof(q)/sizeof(char);
	showArr(q,len);
	bubbleT(q,len);
	showArr(q,len);
	mySort(q,len);
	showArr(q,len);
}

int main()
{
	test();

	return 0;
}
