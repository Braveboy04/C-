#include <iostream>
#include <queue>

using namespace std;

void test()
{
	queue<int> q;

	for (int i = 0; i < 10; i++)
	{
		q.push(i);
	}

	while(!q.empty())
	{
		//cout << q.front() << endl;

		cout << q.back() << '\t' << q.front() << endl;

		q.pop();
	}

	cout << "size = " << q.size() << endl;

}

int main()
{
	test();

	return 0;
}
