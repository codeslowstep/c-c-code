#define _CRT_SECURE_NO_WARNINGS
#include"Ordinary member.h"
Ordinary_member::Ordinary_member(int personid, string name, int departmentid)
{
	this->m_name = name;
	this->m_department_id = departmentid;
	this->m_person_id = personid;
}
string Ordinary_member::Get_department_name()
{
	return string("普通员工");
}
void Ordinary_member:: ShowInfo()
{
	cout << "职工编号：" << this->m_person_id;
	cout << "\t姓名："<< this->m_name;
	cout << "\t岗位：" << this->Get_department_name();
	cout << "\t岗位职责：" << "完成经理交给的任务" << endl;
}