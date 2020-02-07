#include <iostream>
#include <fstream>

using namespace std;

void test01()
{
	ifstream ifs;
	
	ifs.open("test.txt",ios::in);

	if( !ifs.is_open())
	{
		cout << "ERROR!" << endl;
		return;
	}

	//char buf[1024] = {};
	//while ( ifs >> buf )
	//{
	//	cout << buf << endl;
	//}

	//char buf[1024] = {};
	//while ( ifs.getline(buf,sizeof(buf)) )
	//{
	//	cout << buf <<endl;
	//}
	
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//char buf;
	//while ((buf = ifs.get()) != EOF )
	//{
	//	cout << buf;
	//}


	ifs.close();

}

int main()
{
	test01();

	return 0;
}
