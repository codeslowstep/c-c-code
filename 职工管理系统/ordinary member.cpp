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
	return string("��ͨԱ��");
}
void Ordinary_member:: ShowInfo()
{
	cout << "ְ����ţ�" << this->m_person_id;
	cout << "\t������"<< this->m_name;
	cout << "\t��λ��" << this->Get_department_name();
	cout << "\t��λְ��" << "��ɾ�����������" << endl;
}