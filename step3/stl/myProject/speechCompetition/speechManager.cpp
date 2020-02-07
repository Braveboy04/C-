#include "speechManager.h"

using namespace std;

SpeechManager::SpeechManager()
{

}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "********* 欢迎参加演讲比赛 *********" << endl;
	cout << "*********  1.开始演讲比赛  *********" << endl;
	cout << "*********  2.查看往届记录  *********" << endl;
	cout << "*********  3.清空比赛记录  *********" << endl;
	cout << "*********  0.退出比赛程序  *********" << endl;
	cout << "************************************" << endl;
}

void SpeechManager::runCompelite()
{
	system("clear");
	vector<Speaker> vs;

	createSpeaker(vs);

	cout << "选手编号如下: " << endl;
	//for_each(vs.begin(), vs.end(), printV);
	showVP(vs);

	cout << "接下来开始抽签分组 " << endl;
	pause();
	random_shuffle(vs.begin(), vs.end());

	vector<Speaker> group1;
	vector<Speaker> group2;
	for (vector<Speaker>::iterator it = vs.begin(); it != vs.end(); it++)
	{
		if (group1.size() != (vs.size() / 2))
		{
			group1.push_back(*it);
		}
		else if (group2.size() != (vs.size() / 2))
		{
			group2.push_back(*it);
		}
	}
	
	cout << "分组结果如下: " << endl;
	cout << "A 组: " << endl;
	showVP(group1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "B 组: " << endl;
	showVP(group2);
	cout << "接下来请各参赛选手按照分组和抽签顺序进行演讲！" << endl;
	cout << "演讲完毕后请继续下个流程" << endl;
	pause();

	cout << "让我们恭喜以下晋级者！他们分别是: " << endl;
	cout << "A 组: " << endl;
	nextPart(group1);
	showVP(group1);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "B 组: " << endl;
	nextPart(group2);
	showVP(group2);
	cout << "准备开始决赛！" << endl;
	pause();

	cout << "接下来请各参赛选手按照抽签顺序进行演讲！" << endl;
	vector<Speaker> finalGroup;
	pushAFromB(finalGroup, group1);
	pushAFromB(finalGroup, group2);
	random_shuffle(finalGroup.begin(), finalGroup.end());
	//sort(finalGroup.begin(), finalGroup.end(), mySort);
	showVP(finalGroup);
	cout << "下个回合将公布胜出选手，请各位选手在本回合好好发挥！" << endl;
	pause();

	cout << "接下来公布最终结果，他们分别是: " << endl;
	random_shuffle(finalGroup.begin(), finalGroup.end());
	nextPart(finalGroup);
	showResult(finalGroup);
	cout << "恭喜他们！" << endl;
	save(finalGroup);
	pause();
	exit(0);
	
}

void SpeechManager::createSpeaker(vector<Speaker> &vs)
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp(name, 10001 + i);
		vs.push_back(sp);
	}

}

void SpeechManager::exitSystem()
{
	cout << "感谢您的使用，程序正在退出... " << endl;
	pause();
	exit(0);
}

void printV(Speaker &sp)
{
	sp.showInfo();
}

void showVP(vector<Speaker> &vp)
{
	for (vector<Speaker>::iterator it = vp.begin(); it != vp.end(); it++)
	{
		//cout << (int)(it - vp.begin() + 1) << "号\t" ;
		it->showInfo();
	}

}

void nextPart(vector<Speaker> &p)
{
	random_shuffle(p.begin(), p.end());
	while (p.size() > 3)
	{
		p.pop_back();
	}
}

void pushAFromB(vector<Speaker> &targetV, vector<Speaker> &v1)
{
	for (vector<Speaker>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		targetV.push_back(*it);
	}
}

bool mySort(Speaker &p1, Speaker &p2)
{
	return p1.m_Num < p2.m_Num;
}
			
void showResult(vector<Speaker> &v)
{
	string place = "123" ;
	int i = 0;
	for (vector<Speaker>::iterator it = v.begin(); it != v.end(); it++, i++)
	{
		cout << "第 " << place[i] << " 名:\t" ;
		it->showInfo();
	}

}

void save(const vector<Speaker> &v)
{
	ofstream ofs(FILENAME, ios::out);
	for (vector<Speaker>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Name << endl;
	}


	ofs.close();
}
