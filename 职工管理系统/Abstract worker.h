#pragma once
#include<iostream>
#include<string>
using namespace std;
//�����ְ���࣬����
//�û������������ࣺ��ͨ���ˣ������ϰ�
//���ԣ�ְ��������ְ����ţ�ְ�����ڲ��ű��
//��Ϊ����λְ����Ϣ��������ȡ��λ����
class Abstract_worker
{
public:
	
	
	//��ȡ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string Get_department_name() = 0;

	string m_name;
	int m_person_id;//��Ա���
	int m_department_id;//���ű��
};