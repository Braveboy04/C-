#include "user.h"

//公共接口
void User::toDo()
{
	while (true)
	{
		this->userMenu();
		this->checkSel();
	}
}

void User::loadRoom(vector<Room> &vr)
{
	this->uvr = &vr;
	this->getMyReserve();
}

void User::getMyReserve()
{
	for (vector<Room>::iterator vit = uvr->begin(); vit != uvr->end(); vit++)
	{
		vit->m_Record.clear();
		for (multimap<int, pair<long, string>>::iterator it = vit->all_Record.begin(); it != vit->all_Record.end(); it++)
		{
			if (it->second.first == this->m_Num && it->second.second == this->m_Name)
			{
				vit->m_Record.insert(it->first);
			}
		}
	}
}

void User::saveRoom()
{
	ofstream ofs(ROOMFILE, ios::out);
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Capacity << " " << it->m_Total << endl;
		
		for (multimap<int, pair<long, string>>::iterator mit = it->all_Record.begin(); mit != it->all_Record.end(); mit++)
		{
			ofs << mit->first << " " << mit->second.first << " " << mit->second.second << endl;
		}
	}

	ofs.close();
}

void User::logout()
{
	cout << "即将退出登录！" << endl;
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		it->m_Record.clear();
	}
	pause();
	exit(0);
}

bool User::operator==(const User &u)
{
	if (this->m_Num == u.m_Num && this->m_Name == u.m_Name && this->m_Password == u.m_Password)
		return true;
	else 
		return false;
}

//学生类功能
void Student::userMenu()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "当前登录用户: " << this->m_Name << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1) 申请预约 " << endl;
	cout << "2) 查看自身的预约 " << endl;
	cout << "3) 查看所有预约 " << endl;
	cout << "4) 取消预约 " << endl;
	cout << "0) 注销登录 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "请选择操作内容: " << endl;
}

void Student::checkSel()
{
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 0:
		this->logout();

		break;

	case 1:
		this->doReserve();

		break;

	case 2:
		this->showMyReserve();
		
		break;

	case 3:
		this->showAllReserve();

		break;

	case 4: 
		this->cancleReserve();

		break;

	default:

		break;
	}
}

void Student::doReserve()
{
	cout << "请选择预约机房: " << endl;
	cout << "1) 1号机房" << endl;
	cout << "2) 2号机房" << endl;
	cout << "3) 3号机房" << endl;
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:
		{
			vector<Room>::iterator it = uvr->begin();
			it->all_Record.insert(make_pair(it->checkSel(), make_pair(this->m_Num, this->m_Name)));
			this->saveRoom();
			cout << "save test!" << endl;
		}


		break;

	case 2:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			it->all_Record.insert(make_pair(it->checkSel(), make_pair(this->m_Num, this->m_Name)));
			cout << "save test!" << endl;
		}

		break;

	case 3:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			it++;
			it->all_Record.insert(make_pair(it->checkSel(), make_pair(this->m_Num, this->m_Name)));
			cout << "save test!" << endl;
		}

		break;

	default:

		break;
	}
	pause();

}

void Student::showMyReserve()
{
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		it->showRoomHead();
		cout << "我的预约情况: " << endl;
		if (it->m_Record.size() == 0)
		{
			cout << "no data! " << endl;
		}
		for (set<int>::iterator sit = it->m_Record.begin(); sit != it->m_Record.end(); sit++)
		{
			int day = *sit / 2 + 1;
			int time = *sit % 2;
			if (time == MORNING)
			{
				cout << "day " << day << " morning is checking..." << endl;
			}
			else if (time == AFTERNOON)
			{
				cout << "day " << day << " afternoon is checking..." << endl;

			}
		}
	}
	pause();
}

void Student::showAllReserve()
{
	cout << "test for showAllReserve" << endl;
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		it->showRoom();
	}
	pause();
}

void Student::cancleReserve()
{
	int room;
	int day;
	int time;
	int realTime;
	cout << "请选择取消预约的机房号: " << endl;
	cout << "1) 1号机房" << endl;
	cout << "2) 2号机房" << endl;
	cout << "3) 3号机房" << endl;
	cin >> room;
	if (room != 1 && room != 2 && room != 3)
	{
		cout << "输入错误！请重新操作！" << endl;
		pause();
		return;
	}
	cout << "请选择取消预约的周次: " << endl;
	cout << "1) 周一" << endl;
	cout << "2) 周二" << endl;
	cout << "3) 周三" << endl;
	cout << "4) 周四" << endl;
	cout << "5) 周五" << endl;
	cin >> day;
	if (day != 1 && day != 2 && day != 3 && day !=4 && day !=5)
	{
		cout << "输入错误！请重新操作！" << endl;
		pause();
		return;
	}
	cout << "请选择取消预约的时间段: " << endl;
	cout << "1) 早上" << endl;
	cout << "2) 下午" << endl;
	cin >> time;
	if (time != 1 && time != 2)
	{
		cout << "输入错误！请重新操作！" << endl;
		pause();
		return;
	}
	realTime = ((day - 1) * 2) + time - 1;
	pair<int, pair<long, string>> tempPair = make_pair(realTime, make_pair(this->m_Num, this->m_Name));
	switch (room)
	{
	case 1:
		{
			vector<Room>::iterator it = uvr->begin();
			cout << "您当前选择的机房是 " << it->m_Num << " 号机房！" <<endl;
			delReserve(it, tempPair, realTime);
		}

		break;

	case 2:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			cout << "您当前选择的机房是 " << it->m_Num << " 号机房！" <<endl;
			delReserve(it, tempPair, realTime);

		}

		break;

	case 3:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			it++;
			cout << "您当前选择的机房是 " << it->m_Num << " 号机房！" <<endl;
			delReserve(it, tempPair, realTime);
		}

		break;

	default:

		break;
	}
	this->saveRoom();
	pause();
}

void Student::delReserve(vector<Room>::iterator &it, pair<int, pair<long, string>> &tempPair, int realTime)
{
	if (binary_search(it->all_Record.begin(), it->all_Record.end(), tempPair, myRecordCompare))
	{
		//删除取消预约的元素
		multimap<int, pair<long, string>>::iterator map_it = it->all_Record.find(realTime);
		pair<multimap<int, pair<long, string>>::iterator, multimap<int, pair<long, string>>::iterator> pos = it->all_Record.equal_range(map_it->first);
		while (pos.first != pos.second)
		{
			if (pos.first->second.first == this->m_Num && pos.first->second.second == this->m_Name)
			{
				cout << pos.first->first << " " << pos.first->second.first << " " << pos.first->second.second << endl;
				pos.first = it->all_Record.erase(pos.first);
				
			}
			else
				++pos.first;
		}

		//删除自身预约的记录
		it->m_Record.erase(realTime);

		cout << "取消预约成功！" << endl;
		it->m_Total--;
		pause();
	}
}

//教师类功能
void Teacher::userMenu()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "当前登录用户: " << this->m_Name << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1) 查看所有预约 " << endl;
	cout << "2) 审核预约 " << endl;
	cout << "0) 注销登录 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "请选择操作内容: " << endl;

}

void Teacher::checkSel()
{
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 0:
		this->logout();

		break;

	case 1:
		this->showAllReserve();

		break;

	case 2:
		this->checkReserve();

		break;

	default:

		break;
	}
}

void Teacher::showAllReserve()
{
	cout << "test for showAllReserve" << endl;
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		it->showRoom();
	}
	pause();
}

void Teacher::checkReserve()
{

}

//管理员类功能
void Admin::userMenu()
{
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "当前登录用户: " << this->m_Name << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1) 添加账号 " << endl;
	cout << "2) 查看账号 " << endl;
	cout << "3) 查看机房 " << endl;
	cout << "4) 清空预约 " << endl;
	cout << "0) 退出登录 " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "请选择操作内容: " << endl;

}

void Admin::checkSel()
{
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 0:
		this->logout();

		break;

	case 1:
		this->addUser();

		break;

	case 2:
		this->showUsers();
		
		break;

	case 3:
		this->showRoom();

		break;

	case 4: 
		this->delAllReserve();

		break;

	default:

		break;
	}
}

void Admin::loadBool(bool &sb, bool &tb, bool &ab)
{
	this->sbp = &sb;
	this->tbp = &tb;
	this->abp = &ab;
}

void Admin::loadUsers(vector<Student> &vs, vector<Teacher> &vt, vector<Admin> &va)
{
	this->vsp = &vs;
	this->vtp = &vt;
	this->vap = &va;
}

void Admin::addUser()
{
	int sel;
	long num;
	string name;
	string password;
	int makeSure;
	cout << "请选择添加账号类型: " << endl;
	cout << "1) 学生代表 " << endl;
	cout << "2) 老师 " << endl;
	cin >> sel;
	if (sel != 1 && sel != 2)
	{
		cout << "输入错误！请重新添加账号！" << endl;
		return;
	}
	cout << "学号/职工号: " ;
	cin >> num;
	cout << "姓名: " ;
	cin >> name;
	cout << "密码: " ;
	cin >> password;

	cout << "您所添加的账号类型为 " << (sel == 1 ? "学生" : "教师") << endl;
	cout << "学号/职工号: " << num << endl;
	cout << "姓名: " << name << endl;
	cout << "密码: " << password << endl;
	cout << "请确认！" << endl;
	cout << "1) 确认" << endl;
	cout << "2) 取消" << endl;
	cin >> makeSure;
	if (makeSure == 1)
	{
		if (sel == 1)
		{
			Student s;
			s.m_Num = num;
			s.m_Name = name;
			s.m_Password = password;
			this->vsp->push_back(s);
		}
		else if (sel == 2)
		{
			Teacher t;
			t.m_Num = num;
			t.m_Name = name;
			t.m_Password = password;
			this->vtp->push_back(t);
		}
	}
	else if (makeSure == 2)
	{
		cout << "已取消操作！" << endl;
		pause();
		return;
	}
	else
	{
		cout << "输入错误！请重新添加账号！" << endl;
		return;
	}

	pause();
}

void Admin::showUsers()
{
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "学生代表: " << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	this->showStudent();
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "教师: " << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	this->showTeacher();
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "管理员: " << endl;
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	this->showAdmin();
	cout << endl;
}

void Admin::showStudent()
{

}

void Admin::showTeacher()
{

}

void Admin::showAdmin()
{

}

void Admin::saveUser()
{

}

void Admin::showRoom()
{

}

void Admin::delAllReserve()
{

}

bool myRecordCompare(const pair<int, pair<long, string>> &p1, const pair<int, pair<long, string>> &p2)
{
	if (p1.first == p2.first && p1.second.first == p2.second.first && p1.second.second == p2.second.second)
		return true;
	else 
		return false;
}
