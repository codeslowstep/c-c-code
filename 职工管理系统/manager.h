#pragma once
#include<iostream>
#include<string>
#include"Abstract worker.h"
using namespace std;
class Manager :public Abstract_worker
{
public:
	Manager(int personid, string name, int departmentid);

	//��ȡ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string Get_department_name();
};