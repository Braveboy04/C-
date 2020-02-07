#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &l)
{
	cout << endl;
	for (list<int>::const_iterator li = l.begin(); li != l.end(); li++)
	{
		cout << *li << " " ;
	}
	cout << endl;
	cout << endl;
}

void test()
{
	list<int> l;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}

	printList(l);

	list<int> l2(l.begin(),l.end());
	printList(l2);
	
	list<int> l3(10,100);
	printList(l3);

	list<int> l4(l3);
	printList(l4);

	l.assign(l4.begin(), l4.end());
	printList(l);

	l.assign(10,0);
	printList(l);

	l = l4;
	printList(l);

	cout << endl;
	cout << *(++l2.begin()) << endl;
	cout << endl;

	l2.reverse();
	printList(l2);
	
	l2.sort();
	printList(l2);

}

int main()
{
	test();

	return 0;
}
