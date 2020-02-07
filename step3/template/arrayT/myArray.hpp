#ifndef __myArray_hpp
#define __myArray_hpp

#include <iostream>
#include <string>

#include "pause.h"

using namespace std;

template <class T>
class MyArray
{
public:
	T* m_Arr = NULL;
	
	int m_Num = 0;

	int m_Len = 0;

	MyArray(int len);

	MyArray(const MyArray &ma);

	~MyArray();

	void showArr();

	void setArr();

	void addElement(const T& val);

	void delElement();

	void showNum();

//	T *operator=(T *arr);

	MyArray<T> operator=(const MyArray &ma);
	
	T& operator[](int index);

};

template <class T>
MyArray<T>::MyArray(int len)
{
	m_Len = len;
	m_Num = 0;
	m_Arr = new T[m_Len];
}

template <class T>
MyArray<T>::MyArray(const MyArray &ma)
{
	if (m_Arr != NULL)
	{
		delete [] m_Arr;
		m_Arr = NULL;
	}
	m_Len = ma.m_Len;
	m_Num = ma.m_Num;
	m_Arr = new T[m_Len];
	for (int i = 0; i < m_Num; i++)
	{
		m_Arr[i] = ma.m_Arr[i];
		//cout << m_Arr[i] << endl;
	}
}

template <class T>
MyArray<T>::~MyArray()
{
	if (m_Arr != NULL)
	{
		delete [] m_Arr;
		m_Arr = NULL;
		m_Len = 0;
		m_Num = 0;
	}

}

template <class T>
void MyArray<T>::showArr()
{
	cout << "This is an array: " << endl;
	for (int i = 0; i < m_Num; i++)
	{
		cout << *(m_Arr + i) << '\t';
	}
	cout << endl;

}

template <class T>
void MyArray<T>::setArr()
{
	for (int i = 0; i < m_Len; i++)
	{
		cin >> *(m_Arr+i);

	}

}

template <class T>
void MyArray<T>::addElement(const T& val)
{
	if (this->m_Len == this->m_Num)
	{
		return;
	}
	this->m_Arr[this->m_Num] = val;
	this->m_Num++;
}

template <class T>
void MyArray<T>::delElement()
{
	if (this->m_Num == 0)
	{
		return;
	}
	this->m_Num--;

}

template <class T>
void MyArray<T>::showNum()
{
	cout << "当前数组的元素个数为: \t" << m_Num << endl;
	cout << "当前数组的容量为: \t" << m_Len << endl;

}

template <class T>
MyArray<T> MyArray<T>::operator=(const MyArray &ma)
{
	if (m_Arr != NULL)
	{
		delete [] m_Arr;
		m_Len = 0;
		m_Num = 0;
	}

	//int len = 0;
	//cout << "name: " << typeid(arr).name() << endl;
	//cout << "sizeof(arr) = " << sizeof(arr) << endl;
	//cout << "sizeof(&arr) = " << sizeof(&arr) << endl;
	//cout << "sizeof(*arr) = " << sizeof(*arr) << endl;
	//len = sizeof(arr) / sizeof(*arr);
	
	//if (m_Len < len)
	//{
	//	cout << "Error!" << endl;
	//	pause();
	//	return this->m_Arr;
	//}
	
	m_Len = ma.m_Len;
	m_Num = ma.m_Num;
	m_Arr = new T[m_Num];


	for (int i = 0; i < m_Num; i++)
	{
		*(m_Arr + i) = *(ma.m_Arr + i);
	}
	//cout << " len = " << len << endl;
	//m_Num = len;
	return *this;;
}

template <class T>
T& MyArray<T>::operator[](int index)
{
	return this->m_Arr[index];
}

#endif
