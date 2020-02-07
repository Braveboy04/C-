#include <iostream>

using namespace std;

class BasePage
{
public:
	int a = 0;
	static int b;
	int c = 10;

	BasePage()
	{
		cout << "父类构造函数" << endl;
	}

	~BasePage()
	{
		cout << "父类析构函数" << endl;
	}

	virtual void head()
	{
		cout << "I'm HEAD!" << endl;
	}

	virtual void tail()
	{
		cout << "I'm TAIL!" << endl;
	}

	virtual void content()
	{
		cout << "I'm BasePage!" << endl;
	}

};

class CPP : virtual public BasePage
{
public:
	int a = 10;
	static int b;

	CPP()
	{
		cout << "子类构造函数" << endl;
	}
	
	~CPP()
	{
		cout << "子类析构函数" << endl;
	}

	void content()
	{
		cout << "I'm CPP!" << endl;
	}


};

class JAVA : virtual public BasePage
{
public:
	int a = 20;
	static int b;

	JAVA()
	{
		cout << "子类构造函数" << endl;
	}
	
	~JAVA()
	{
		cout << "子类析构函数" << endl;
	}

	void content()
	{
		cout << "I'm JAVA!" << endl;
	}


};

class CJ :public CPP, public JAVA
{
	void content()
	{
		cout << "I'm CPP+JAVA!" << endl;
	}


};

int BasePage::b = 0;
int CPP::b = 10;
int JAVA::b = 30;

void webPrint(BasePage &b)
{
	cout << "\n\n~~~~~~~~~~~~~~~~~~~\n";
	b.head();
	b.content();
	b.tail();
	cout << "~~~~~~~~~~~~~~~~~~~\n\n";
}

void test01()
{
	CPP cpp;
	JAVA ja;
	CJ cj;
	
	webPrint(cpp);
	webPrint(ja);
	webPrint(cj);
	cout << "I'm CPP+JAVA.c: " << cj.c << endl;

	//cout << "\n\n~~~~~~~~~~~~~~~~~~~\n";
	//CPP cpp;
	//cpp.head();
	//cpp.content();
	//cpp.BasePage::content();

	//cout << "子类成员" << cpp.a << endl;
	//cout << "父类成员" << cpp.BasePage::a << endl;

	//cpp.tail();
	//cout << "~~~~~~~~~~~~~~~~~~~\n\n";
}

int main()
{
	test01();

	return 0;
}
