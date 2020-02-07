#include <iostream>
#include <fstream>

using namespace std;

void test01()
{
	ofstream ofs;
	
	ofs.open("hello.cpp",ios::out);

	ofs << "#include <iostream>" << endl;
	ofs << "using namespace std;" << endl;
	ofs << "int main() " << endl;
	ofs << "{" << endl << 
		"	cout << " << "\"hello world\"" << " << endl; " <<
		"}" << endl;

	ofs.close();

}

int main()
{
	test01();

	return 0;
}
