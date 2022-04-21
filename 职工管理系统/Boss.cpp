#define _CRT_SECURE_NO_WARNINGS
#include"Boss.h"
Boss::Boss(int personid, string name, int departmentid)
{
	this->m_name = name;
	this->m_department_id = departmentid;
	this->m_person_id = personid;
}
string Boss::Get_department_name()
{
	return string("老板");
}
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_person_id;
	cout << "\t姓名：" << this->m_name;
	cout << "\t岗位：" << this->Get_department_name();
	cout << "\t岗位职责：" << "管理公司所有事务" << endl;
}