#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		//*it = 100;	//不可修改数据
		cout << *it << " " ;
	}
	cout << endl;
}

void test()
{
	vector<int> v;
	v.reserve(100000);

	int num = 0;
	int *p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if ( p != &v[0])
		{
			p = &v[0];
			num++;
			cout << endl;
			cout << "capacity = " << v.capacity() << endl;
			cout << "size = " << v.size() << endl;
			cout << "num = " << num << endl;
			cout << endl;
		}
	}

	printVector(v);
}

int main()
{
	test();

	return 0;
}
