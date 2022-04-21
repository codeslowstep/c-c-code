#pragma once
#include<iostream>
#include<fstream>
#include"Abstract worker.h"
#define FILENAME "test.txt"
using namespace std;
//总的管理类
//1.菜单
//2.对职工的增删查改
//3.与文件读写交互
class Workmanager
{
public:
	//构造
	Workmanager();

	//菜单
	void menu();

	//记录职工人数
	int m_person_num;

	//职工数组指针,利用pp_person[]来指向一个具体的职工
	//pp_person[]是一个Abstract_worker*类型，是一个父类指针
	Abstract_worker** pp_peron;

	//添加职工
	void Addperson();
	//判断职工是否为空
	bool File_is_empty;
	//统计文件中的人数
	int Get_file_personnum();
	//初始化员工
	void Initperson();
	//显示员工信息
	void Showperson();
	//实现退出功能
	void Exitsystem();
	//把人员信息写到文件中
	void Write_to_file();
	//删除职工
	void Delperson();
	//根据姓名删除
	void Deleteperson_by_name();
	//根据编号删除
	void Deleteperson_by_personid();
	//按照姓名查找
	int Seek_by_name(string name);
	//按照id查找
	int Seek_by_id(int id);
	//修改职工信息
	void Modify_person();
	//查找姓名修改
	void Modifyperson_by_name();
	//查找id修改
	void Modifyperson_by_personid();
	//查找
	void Seekperson();
	//清空
	void Empty_person();
	//排序
	void Sorterson();
	//升序排序
	void Scending_sort();
	//降序排序
	void Descending_sort();
	//析构
	~Workmanager();

	
};