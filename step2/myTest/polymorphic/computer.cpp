#include <iostream>

using namespace std;

class CPU
{
public:
	virtual ~CPU() {}
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual ~VideoCard() {}
	virtual void display() = 0;
};

class Memory
{
public:
	virtual ~Memory() {}
	virtual void storage() = 0;
};

class IntelCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Intel's CUP is running! " << endl;
	}
};

class LenovoCpu : public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo's CUP is running! " << endl;
	}
};

class IntelVC : public VideoCard
{
public:
	void display()
	{
		cout << "InterVC is running!" << endl;
	}
};

class LenovoVC : public VideoCard
{
public:
	void display()
	{
		cout << "LenovoVC is running!" << endl;
	}
};

class IntelMr : public Memory
{
public:
	void storage()
	{
		cout << "InterMemory is running!" << endl;
	}
};

class LenovoMr : public Memory
{
public:
	void storage()
	{
		cout << "LenovoMemory is running!" << endl;
	}
};



class Computer
{
private:
	CPU *m_Cpu;
	VideoCard *m_Vc;
	Memory *m_Mr;

public:
	Computer(CPU *cpu, VideoCard *vc, Memory *mr) : m_Cpu(cpu),m_Vc(vc),m_Mr(mr)
	{
		cout << "computer 构造函数" << endl;
	}
	//{
	//	cout << endl;
	//	cpu->calculate();
	//	vc->display();
	//	mr->storage();
	//	cout << endl;
	//}

	void run()
	{
		cout << endl;
		m_Cpu->calculate();
		m_Vc->display();
		m_Mr->storage();
		cout << endl;
	}

	~Computer()
	{
		cout << "computer 析构函数" << endl;
		if(m_Cpu != NULL)
		{
			delete m_Cpu;
			m_Cpu = NULL;
		}
		if(m_Vc != NULL)
		{
			delete m_Vc;
			m_Vc = NULL;
		}
		if(m_Mr != NULL)
		{
			delete m_Mr;
			m_Mr = NULL;
		}
	}
	
};

void test()
{
	CPU *cpu[2];
	cpu[0] = new IntelCpu;
	cpu[1] = new LenovoCpu;

	VideoCard *vc[2];
	vc[0] = new IntelVC;
	vc[1] = new LenovoVC;

	Memory *mr[2];
	mr[0] = new IntelMr;
	mr[1] = new LenovoMr;

	Computer *cm[3];
	cm[0] = new Computer(cpu[0], vc[0], mr[0]);
	cm[1] = new Computer(cpu[0], vc[0], mr[1]);
	cm[2] = new Computer(cpu[0], vc[1], mr[0]);

	cm[0]->run();
	cm[1]->run();
	cm[2]->run();

	for(int i = 0; i <= 2; i++)
	{
		cout << cm[i] << endl;
	}
	cout << endl;

	//delete cpu[0];
	//delete cpu[1];

	delete cm[2];
	delete cm[1];
	delete cm[0];

	//delete [] vc;
	//delete [] mr;
	//delete [] cm;
	

	//for(int i = 0; i <= 2; i++)
	//{
	//	cout << cm[i] << endl;
	//	if(i <= 1)
	//	{
	//		delete cpu[i];
	//		delete vc[i];
	//		delete mr[i];
	//		delete cm[i];
	//	}
	//	if(i == 2)
	//		delete cm[i];
	//}

}


int main()
{
	test();

	return 0;
}
