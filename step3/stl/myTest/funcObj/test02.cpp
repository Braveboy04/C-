#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterFive
{
public:
	bool operator() (int val)
	{
		return val > 5;
	}
};

class MyCompare
{
public:
	bool operator() (int v1, int v2)
	{
		return v1 > v2;
	}
};

void test()
{
	vector<int> v;
	
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for (vector<int>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		cout << *vit << " " ;
		//vit++;
	}
	cout << endl;

	//vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	//while (it != v.end())
	//{
	//	cout << *it << " " ;
	//	it++;
	//}
	//cout << endl;

	sort(v.begin(), v.end(), MyCompare());

	for (vector<int>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		cout << *vit << " " ;
		//vit++;
	}
	cout << endl;

}

int main()
{
	test();

	return 0;
}
