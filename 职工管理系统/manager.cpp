#define _CRT_SECURE_NO_WARNINGS
#include"manager.h"
Manager::Manager(int personid, string name, int departmentid)
{
	this->m_name = name;
	this->m_department_id = departmentid;
	this->m_person_id = personid;
}
string Manager::Get_department_name()
{
	return string("经理");
}
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_person_id;
	cout << "\t姓名：" << this->m_name;
	cout << "\t岗位：" << this->Get_department_name();
	cout << "\t岗位职责：" << "完成老板交给的任务" << endl;
}