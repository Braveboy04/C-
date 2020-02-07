#include <iostream>

using namespace std;

class AbstractCaculator
{
public:
	int Num1;
	int Num2;

	virtual int result()
	{
		return 0;
	}

	AbstractCaculator(int a = 0, int b = 0) : Num1(a),Num2(b){}

	virtual ~AbstractCaculator(){}

	void setNum(const int &a, const int &b)
	{
		Num1 = a;
		Num2 = b;
	}
};

class AddCaculator : virtual public AbstractCaculator
{
public:
	AddCaculator(int a = 0, int b = 0) 
	{
		Num1 = a;
		Num2 = b;
	}

	//AddCaculator(int a = 0, int b = 0) : Num1(a),Num2(b){}

	int result()
	{
		return Num1 + Num2;
	}
};
	
class SubCaculator : public AbstractCaculator
{
public:
	int result()
	{
		return Num1 - Num2;
	}
};

class MulCaculator : public AbstractCaculator
{
public:
	int result()
	{
		return Num1 * Num2;
	}
};


int test()
{
	char sel;
	cout << "This is a caculator, please select a function: " << endl << 
		"a) Add " << endl <<
		"b) Sub " << endl << 
		"c) Mul " << endl << 
		"q) Quit " << endl;
	cin >> sel;
	switch(sel)
	{
		case 'q':
			return 1;

		case 'a':
		case 'A':
			{
				int a;
				int b;
				cout << "Please enter 2 nums: ";
				cin >> a >> b;

				//AbstractCaculator *ca = new AddCaculator(a,b);
				AbstractCaculator *ca = new AddCaculator;
				ca->setNum(a,b);
	     			cout << a << " + " << b << " = " << ca->result() << endl;
				//ca = NULL;
				delete ca;
			}

			return 0;
			break;
			
		
		case 'b':
		case 'B':
			cout << "bB" << endl;break;

			return 0;
			break;

		case 'c':
		case 'C':
			cout << "cC" << endl;break;

			return 0;
			break;

		default:
			cout << "error!" << endl;
			return 0;

	}
	//if ( sel < 65 || (sel >67 && sel < 97) || sel > 99)
	//{
	//	cout << "error!" << endl;
	//	return 0;
	//}
	//else if (sel == 0)
		return 1;

}
int main()
{
	while(1)
	{
		if (test() != 0)
			break;
	}


	return 0;
}
