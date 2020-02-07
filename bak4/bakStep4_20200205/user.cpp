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
}

void User::saveRoom()
{
	ofstream ofs(ROOMFILE, ios::out);
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Capacity << " " << it->m_Total << endl;
		//for (multimap<pair<long, string>, map<int, bool>>::iterator mit = it->all_Record.begin(); mit != it->all_Record.end(); mit++)
		//{
		//	ofs << mit->first->first << " " << mit->first->second << " " << mit->second->first << " " << mit->second->second << endl;
		//}
		
		for (multimap<pair<long, string>, pair<int, bool>>::iterator mit = it->all_Record.begin(); mit != it->all_Record.end(); mit++)
		{
			ofs << mit->first.first << " " << mit->first.second << " " << mit->second.first << " " << mit->second.second << endl;
		}
	}

	ofs.close();
}

void User::logout()
{
	cout << "即将退出登录！" << endl;
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
			it->checkSel();
			//it->m_Record.insert(make_pair(make_pair(m_Num, m_Name), it->m_Data));
			for (map<int, bool>::iterator mit = it->m_Data.begin(); mit != it->m_Data.end(); mit++)
			{
				it->all_Record.insert(make_pair(make_pair(m_Num, m_Name), *mit));		//此处有bug
				it->m_Total++;
			}
			this->saveRoom();
			cout << "save test!" << endl;
		}


		break;

	case 2:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			it->checkSel();
			for (map<int, bool>::iterator mit = it->m_Data.begin(); mit != it->m_Data.end(); mit++)
			{
				it->all_Record.insert(make_pair(make_pair(m_Num, m_Name), *mit));
				it->m_Total++;

			}
			cout << "save test!" << endl;
		}

		break;

	case 3:
		{
			vector<Room>::iterator it = uvr->begin();
			it++;
			it++;
			it->checkSel();
			for (map<int, bool>::iterator mit = it->m_Data.begin(); mit != it->m_Data.end(); mit++)
			{
				it->all_Record.insert(make_pair(make_pair(m_Num, m_Name), *mit));
				it->m_Total++;

			}
		}
			cout << "save test!" << endl;

		break;

	default:

		break;
	}

}

void Student::showMyReserve()
{

}

void Student::showAllReserve()
{
	cout << "test for showAllReserve" << endl;
	for (vector<Room>::iterator it = uvr->begin(); it != uvr->end(); it++)
	{
		it->showRoom();
	}
}

void Student::cancleReserve()
{

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
	while (true)
	{
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
}

void Teacher::showAllReserve()
{

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
		
		break;

	case 3:

		break;

	case 4: 

		break;

	default:

		break;
	}
}

void Admin::addUser()
{
	cout << "请选择添加账号类型: " << endl;
	cout << "1) 学生代表 " << endl;
	cout << "2) 老师 " << endl;
	//int sel;
	//cin >> sel;

	cout << "添加账号功能测试" << endl;
	pause();
	//exit(0);

}

void Admin::showUsers()
{

}

void Admin::showRoom()
{

}

void Admin::delAllReserve()
{

}
