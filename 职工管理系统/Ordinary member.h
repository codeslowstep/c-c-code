#pragma once
#include<iostream>
#include<string>
#include"Abstract worker.h"
using namespace std;
class Ordinary_member:public Abstract_worker
{
public:
	Ordinary_member(int personid, string name, int departmentid);

	//获取个人信息
	virtual void ShowInfo();
	
	//获取岗位名称
	virtual string Get_department_name();
};