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
	return string("�ϰ�");
}
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_person_id;
	cout << "\t������" << this->m_name;
	cout << "\t��λ��" << this->Get_department_name();
	cout << "\t��λְ��" << "����˾��������" << endl;
}