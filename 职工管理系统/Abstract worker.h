#pragma once
#include<iostream>
#include<string>
using namespace std;
//抽象的职工类，基类
//该基类有三个子类：普通工人，经理，老板
//属性：职工姓名，职工编号，职工所在部门编号
//行为：岗位职责信息描述，获取岗位名称
class Abstract_worker
{
public:
	
	
	//获取个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string Get_department_name() = 0;

	string m_name;
	int m_person_id;//人员编号
	int m_department_id;//部门编号
};