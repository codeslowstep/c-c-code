#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include"Abstract worker.h"
using namespace std;
class Boss :public Abstract_worker
{
public:
	Boss(int personid, string name, int departmentid);

	//��ȡ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string Get_department_name();
};