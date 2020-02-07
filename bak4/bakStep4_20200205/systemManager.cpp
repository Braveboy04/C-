#include "systemManager.h"

SystemManager::SystemManager()
{
	this->initUser();

	this->loadStudent();

	this->loadTeacher();

	this->loadAdmin();

	this->loadRoom();
}

SystemManager::~SystemManager()
{

}

void SystemManager::systemMenu()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "欢迎使用机房预约系统: " << endl;
	cout << "请输入您的登录身份: " << endl;
	cout << "1) 学生代表 " << endl;
	cout << "2) 老师 " << endl;
	cout << "3) 管理员 " << endl;
	cout << "0) 退出 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
}

void SystemManager::exitSystem()
{
	cout << "欢迎下次使用! " << endl;
	pause();
	exit(0);
}

void SystemManager::studentLogin()
{
	//this->initUser();
	//this->loadStudent();

	Student tmpA;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "学号: " ;
	cin >> tmpA.m_Num;
	cout << "姓名: " ;
	cin >> tmpA.m_Name;
	cout << "密码: " ;
	cin >> tmpA.m_Password;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	vector<Student>::iterator it = find(vs.begin(), vs.end(), tmpA);
	if (it != vs.end())
	{
		cout << "登录成功！" << endl;
		pause();
		tmpA.loadRoom(vr);
		tmpA.toDo();
	}
	else
	{
		cout << "登录失败！请重新尝试！" << endl;
		pause();
	}
}

void SystemManager::teacherLogin()
{
	//this->initUser();
	//this->loadTeacher();

	Teacher tmpA;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "职工号: " ;
	cin >> tmpA.m_Num;
	cout << "姓名: " ;
	cin >> tmpA.m_Name;
	cout << "密码: " ;
	cin >> tmpA.m_Password;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	vector<Student>::iterator it = find(vs.begin(), vs.end(), tmpA);
	if (it != vs.end())
	{
		cout << "登录成功！" << endl;
		pause();
		tmpA.toDo();
	}
	else
	{
		cout << "登录失败！请重新尝试！" << endl;
		pause();
	}
}

void SystemManager::adminLogin()
{
	//this->initUser();
	//this->loadAdmin();

	Admin tmpA;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	tmpA.m_Num = 0;
	cout << "姓名: " ;
	cin >> tmpA.m_Name;
	cout << "密码: " ;
	cin >> tmpA.m_Password;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	vector<Admin>::iterator it = find(va.begin(), va.end(), tmpA);
	if (it != va.end())
	{
		cout << "登录成功！" << endl;
		pause();
		tmpA.toDo();
	}
	else
	{
		cout << "登录失败！请重新尝试！" << endl;
		pause();
	}
}

void SystemManager::initUser()
{
	vs.clear();
	vt.clear();
	va.clear();

	if (adminFileIsEmpty)
	{
		cout << "loading admin... " << endl;
		Admin a;
		a.m_Num = 0;
		a.m_Name = "admin";
		a.m_Password = "admin";
		va.push_back(a);
	}
}

void SystemManager::loadRoom()
{
	ifstream ifs(ROOMFILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "INITROOM ERROR!" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "ROOMFILE文件为空！" << endl;
		this->roomFileIsEmpty = true;
		ifs.close();
		return;
	}

	this->roomFileIsEmpty = false;

	ifs.putback(ch);

	int num = 0;
	int capacity = 0;
	int total = 0;
	while (ifs >> num && ifs >> capacity && ifs >> total)
	{
		Room temp;
		temp.m_Num = num;
		temp.m_Capacity = capacity;
		temp.m_Total = total;
		for (int i = 0; i < temp.m_Total; i++)
		{
			long s_Num;
			string s_Name;
			int t_First;
			bool t_Second;
			ifs >> s_Num;
			ifs >> s_Name;
			ifs >> t_First;
			ifs >> t_Second;
			pair<long, string> t_Pair1 = make_pair(s_Num, s_Name);
			pair<int, bool> t_Pair2 = make_pair(t_First, t_Second);
			temp.all_Record.insert(make_pair(t_Pair1, t_Pair2));
		}
		vr.push_back(temp);
		showRoom(temp);
		num = 0;
		capacity = 0;
		total = 0;
	}
	sort(vr.begin(), vr.end(), r_Sort);

	ifs.close();
}

void SystemManager::showRoom(Room &r)
{
	cout << endl;
	cout << "Num: " << r.m_Num << "\tCapacity: " << r.m_Capacity << "\tTotal: " << r.m_Total << endl;
	
	for (multimap<pair<long, string>, pair<int, bool>>::iterator it = r.all_Record.begin(); it != r.all_Record.end(); it++)
	{
		cout << it->first.first << '\t' << it->first.second << '\t' << it->second.first << '\t' << it->second.second << endl;
	}

	//for (map<int, bool>::iterator it = r.m_Data.begin(); it != r.m_Data.end(); it++)
	//{
	//	cout << it->first << "\t" << it->second << endl;
	//}
	cout << endl;
}

void SystemManager::loadStudent()
{
	ifstream ifs(STUDENTFILE, ios::in);
	if (!ifs.is_open())
	{
		this->studentFileIsEmpty = true;
		cout << "Student文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "Student文件为空！" << endl;
		this->studentFileIsEmpty = true;
		ifs.close();
		return;
	}

	this->studentFileIsEmpty = false;

	ifs.putback(ch);

	Student temp;
	while (ifs >> temp.m_Num && ifs >> temp.m_Name && ifs >> temp.m_Password)
	{
		vs.push_back(temp);
	}	
	
	ifs.close();
}

void SystemManager::loadTeacher()
{
	ifstream ifs(TEACHERFILE, ios::in);
	if (!ifs.is_open())
	{
		this->teacherFileIsEmpty = true;
		cout << "Teacher文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "Teacher文件为空！" << endl;
		this->teacherFileIsEmpty = true;
		ifs.close();
		return;
	}

	this->teacherFileIsEmpty = false;

	ifs.putback(ch);

	Teacher temp;
	while (ifs >> temp.m_Num && ifs >> temp.m_Name && ifs >> temp.m_Password)
	{
		vt.push_back(temp);
	}	
	
	ifs.close();
}

void SystemManager::loadAdmin()
{
	ifstream ifs(ADMINFILE, ios::in);
	if (!ifs.is_open())
	{
		this->adminFileIsEmpty = true;
		cout << "Admin文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "Admin文件为空！" << endl;
		this->adminFileIsEmpty = true;
		ifs.close();
		return;
	}

	this->adminFileIsEmpty = false;

	ifs.putback(ch);

	Admin temp;
	while (ifs >> temp.m_Num && ifs >> temp.m_Name && ifs >> temp.m_Password)
	{
		va.push_back(temp);
	}	
	
	ifs.close();
}

void SystemManager::saveStudent()
{
	ofstream ofs(STUDENTFILE, ios::out);
	for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Name << " " << it->m_Password << endl;
	}
	ofs.close();
}

void SystemManager::saveTeacher()
{
	ofstream ofs(TEACHERFILE, ios::out);
	for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Name << " " << it->m_Password << endl;
	}
	ofs.close();
}

void SystemManager::saveAdmin()
{
	ofstream ofs(ADMINFILE, ios::out);
	for (vector<Admin>::iterator it = va.begin(); it != va.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Name << " " << it->m_Password << endl;
	}
	ofs.close();
}

void SystemManager::saveRoom()
{
	sort(vr.begin(), vr.end(), r_Sort);		//有序存入

	ofstream ofs(ROOMFILE, ios::out);

	for (vector<Room>::iterator it = vr.begin(); it != vr.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Capacity << " " << it->m_Total << endl;
		for (map<int, bool>::iterator mit = it->m_Data.begin(); mit != it->m_Data.end(); mit++)
		{
			ofs << mit->first << " " << mit->second << endl;
		}
		cout << endl;
	}

	ofs.close();


}

bool r_Sort(const Room &r1, const Room &r2)
{
	if (r1.m_Num < r2.m_Num)
		return true;
	else 
		return false;
}
