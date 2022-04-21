#define _CRT_SECURE_NO_WARNINGS
#include"Workmanager.h"
#include"manager.h"
#include"Ordinary member.h"
#include"Boss.h"
#include<Windows.h>
Workmanager::Workmanager()
{
	//导入文件中的内容,读文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		/*cout << "文件不存在" << endl;*/
		this->File_is_empty= true;
		this->m_person_num = 0;
		this->pp_peron = NULL;
		ifs.close();
		return;
	}
	//文件存在但是为空
	char ch;
	ifs >> ch;
	if (ifs.eof())//ifs.eof()为真就表示文件为空
	{
		/*cout << "文件为空" << endl;*/
		this->File_is_empty = true;
		this->m_person_num = 0;
		this->pp_peron = NULL;
		ifs.close();
		return;
	}
	//文件存在且不为空
	int num = this->Get_file_personnum();
	/*cout << "文件中职工的人数为" << num << endl;*/
	this->m_person_num = num;
	//开辟空间
	this->pp_peron = new Abstract_worker * [num];
	//导入文件中的人
	this->Initperson();
}
Workmanager::~Workmanager()
{
	if (this->pp_peron != NULL)//析构实现，对象销毁
	{
		delete[] this->pp_peron;
		//delete[] this->pp_person等价于
		//delete[] this->pp_person[i]
		this->pp_peron = NULL;
	}
}

//菜单
void Workmanager::menu()
{
	cout << "**************************************" << endl;
	cout << "********欢迎使用职工管理系统**********" << endl;
	cout << "**********0.退出管理系统**************" << endl;
	cout << "**********1.增加职工信息**************" << endl;
	cout << "**********2.显示职工信息**************" << endl;
	cout << "**********3.删除离职职工**************" << endl;
	cout << "**********4.修改职工信息**************" << endl;
	cout << "**********5.查找职工信息**************" << endl;
	cout << "**********6.按照编号排序**************" << endl;
	cout << "**********7.清空所有文档**************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//退出
void Workmanager::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(-1);
}
void Workmanager::Addperson()
{
	cout << "请输入添加的职工数量：" << endl;
	int addnum=0;
	cin >> addnum;
	if (addnum > 0)
	{
		//新空间人数
		int newsize = this->m_person_num + addnum;
		Abstract_worker **tmp=new Abstract_worker* [newsize];
		//把原来空间的数据拷贝到新的空间
		
		//原来有人，就拷贝
		int i = 0;
		for (int i = 0; i < this->m_person_num; i++)
		{
			tmp[i] = this->pp_peron[i];
		}
		//添加
		int a = this->m_person_num;
		for (int i = 0; i < addnum; i++)
		{
		start:

			int personid=0;
			string name;
			int departmentid=0;
			cout << "请输入第" << i + 1 << "个新员工的编号" << endl;
			cin >> personid;
			cout << "请输入第" << i + 1 << "个新员工的姓名" << endl;
			cin >> name;
			cout << "请选择职工的岗位:" << endl;
			cout << "1.普通员工  2.经理  3.老板" << endl;
			cin >> departmentid;
			Abstract_worker* work;
			switch (departmentid)
			{
			case 1:
				work = new Ordinary_member(personid, name, departmentid);
				break;
			case 2:
				work = new Manager(personid, name, departmentid);
				break;
			case 3:
				work = new Boss(personid, name, departmentid);
				break;
			default:
				cout << "选择错误，请重新选择" << endl;
				goto start;
				break;
			}
			if (i == 0)
			{
				tmp[a + i] = work;
			}
			else
			{
				this->pp_peron[a + i] = work;
			}
			//释放原有空间
			if (0 == i)
			{
				delete[] this->pp_peron;
			}
			//这个就相当于释放了pp_person[i],i从0到this->size
			//但是pp_person没有释放，pp_person还是指向一块空间，空间中有都是Abstract_work*
			if (0 == i)
			{
				this->pp_peron = tmp;
				this->m_person_num = newsize;
			}
			tmp = NULL;
			work = NULL;
			system("pause");
		}
		this->File_is_empty = false;
		cout << "成功添加" << addnum << "名职工" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
}
void Workmanager::Showperson()
{
	if (!this->m_person_num)
	{
		cout << "没有人员" << endl;
		return;
	}
	int i = 0;
	for (i = 0; i < this->m_person_num; i++)
	{
		this->pp_peron[i]->ShowInfo();
	}
}
void Workmanager::Write_to_file()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	int i = 0;
	for (i = 0; i<this->m_person_num; i++)
	{

		ofs << this->pp_peron[i]->m_person_id
			<< "  " << this->pp_peron[i]->m_name
			<< "  " << this->pp_peron[i]->m_department_id << endl;
	}
	ofs.close();
}
int Workmanager::Get_file_personnum()
{
	int count = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	int personid;
	string name;
	int departmentid;
	while (ifs >> personid && ifs >> name && ifs >> departmentid)
	{
		count++;
	}
	return count;
}
void Workmanager::Initperson()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int did;
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Abstract_worker* tmp = NULL;
		if (1 == did)//普通员工
		{
			tmp = new Ordinary_member(id, name, did);
		}
		else if (2 == did)//经理
		{
			tmp = new Manager(id, name, did);
		}
		else if (3 == did)//老板
		{
			tmp = new Boss(id, name, did);
		}
		this->pp_peron[index] = tmp;
		index++;
	}
	ifs.close();
}
void Workmanager::Delperson()
{
	int select = 0;
	cout << "1.查找姓名删除   2.查找编号删除" << endl;
start:
	cin >> select;
	switch (select)
	{
	case 1:
		this->Deleteperson_by_name();
		
		break;
	case 2:
		this->Deleteperson_by_personid();
		
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		goto start;
		break;
	}
}
//根据姓名删除
void Workmanager::Deleteperson_by_name()
{
	string name;
	cout << "请输入想要删除的Person的姓名" << endl;
	cin >> name;
	int tmp = this->Seek_by_name(name);
	if (tmp == -1)
	{
		cout << "想要删除的Person不存在" << endl;
	}
	else
	{
		delete this->pp_peron[tmp];
		int i = 0;
		for (i = 0;i<this->m_person_num-tmp-1; i++)
		{
			this->pp_peron[tmp + i] = this->pp_peron[tmp + i + 1];
		}
		this->pp_peron[this->m_person_num - 1] = NULL;
		this->m_person_num--;
		cout << "删除成功" << endl;
	}
}
//根据编号删除
void Workmanager::Deleteperson_by_personid()
{
	int personid;
	cout << "请输入想要删除的Person的编号" << endl;
	cin >> personid;
	int tmp=this->Seek_by_id(personid);
	if (tmp == -1)
	{
		cout << "想要删除的Person不存在" << endl;
	}
	else
	{
		delete this->pp_peron[tmp];
		int i = 0;
		for (i = 0; i < this->m_person_num - tmp - 1; i++)
		{
			this->pp_peron[tmp + i] = this->pp_peron[tmp + i + 1];
		}
		this->pp_peron[this->m_person_num - 1] = NULL;
		this->m_person_num--;
		cout << "删除成功" << endl;
	}
}
//按照姓名查找
int Workmanager::Seek_by_name(string name)
{
	int i = 0;
	for (i = 0; i < this->m_person_num; i++)
	{
		if (name == this->pp_peron[i]->m_name)
		{
			return i;
		}
	}
	return -1;

}
//按照id查找
int Workmanager::Seek_by_id(int id)
{
	int i = 0;
	for (i = 0; i < this->m_person_num; i++)
	{
		if (id == this->pp_peron[i]->m_person_id)
		{
			return i;
		}
	}
	return -1;
}
//查找姓名修改
void Workmanager::Modifyperson_by_name()
{
	string name;
	cout << "请输入想要修改的Person的姓名" << endl;
	cin >> name;
	string tname;
	int tpersonid=0;
	int tdepartid=0;
	int tmp = this->Seek_by_name(name);
	if (tmp == -1)
	{
		cout << "想要修改的Person不存在" << endl;
	}
	else
	{
		//修改之前要先删除原来的信息
		delete this->pp_peron[tmp];
		this->pp_peron[tmp] = NULL;
		cout << "请重新输入该员工的编号" << endl;
		cin >> tpersonid;
		cout << "请重新输入该员工的姓名" << endl;
		cin >> tname;
		cout << "请重新输入该员工的岗位" << endl;
		start:
		cout << "1.普通员工  2.经理  3.老板" << endl;
		cin >> tdepartid;
		switch (tdepartid)
		{
		case 1:
			this->pp_peron[tmp] = new Ordinary_member(tpersonid, tname, tdepartid);
			break;
		case 2:
			this->pp_peron[tmp] = new Manager(tpersonid, tname, tdepartid);
			break;
		case 3:
			this->pp_peron[tmp] = new Boss(tpersonid, tname, tdepartid);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			goto start;
			break;
		}
		cout << "修改成功" << endl;
	}
}
//查找id修改
void Workmanager::Modifyperson_by_personid()
{
	int t;
	cout << "请输入想要修改的Person的id" << endl;
	cin >> t;
	string tname;
	int tpersonid=0;
	int tdepartid=0;
	int tmp = this->Seek_by_id(t);
	if (tmp == -1)
	{
		cout << "想要修改的Person不存在" << endl;
	}
	else
	{
		//修改之前要先删除原来的信息
		delete this->pp_peron[tmp];
		this->pp_peron[tmp] = NULL;
		cout << "请重新输入该员工的编号" << endl;
		cin >> tpersonid;
		cout << "请重新输入该员工的姓名" << endl;
		cin >> tname;
		cout << "请重新输入该员工的岗位" << endl;
	start:
		cout << "1.普通员工  2.经理  3.老板" << endl;
		cin >> tdepartid;
		switch (tdepartid)
		{
		case 1:
			this->pp_peron[tmp] = new Ordinary_member(tpersonid, tname, tdepartid);
			break;
		case 2:
			this->pp_peron[tmp] = new Manager(tpersonid, tname, tdepartid);
			break;
		case 3:
			this->pp_peron[tmp] = new Boss(tpersonid, tname, tdepartid);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			goto start;
			break;
		}
		cout << "修改成功" << endl;
	}
}
void Workmanager::Modify_person()
{
	int select = 0;
	cout << "1.查找姓名修改   2.查找编号修改" << endl;
start:
	cin >> select;
	switch (select)
	{
	case 1:
		this->Modifyperson_by_name();
		break;
	case 2:
		this->Modifyperson_by_personid();
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		goto start;
		break;
	}
}
void Workmanager::Seekperson()
{
	int select = 0;
	cout << "1.按照姓名查找   2.按照编号查找" << endl;
start:
	cin >> select;
	switch (select)
	{
	case 1:
	{
		string name;
		cout << "请输入想要查找的人的姓名" << endl;
		cin >> name;
		int tmp = this->Seek_by_name(name);
		if (tmp == -1)
		{
			cout << "找不到要查找的人" << endl;
			Sleep(1000);
			return;
		}
		cout << "要查找的人信息如下" << endl;
		this->pp_peron[tmp]->ShowInfo();
		Sleep(3000);
	}
		break;
	case 2:
	{
		int a;
		cout << "请输入想要查找的人的编号" << endl;
		cin >> a;
		int tmp = this->Seek_by_id(a);
		if (tmp == -1)
		{
			cout << "找不到要查找的人" << endl;
			Sleep(1000);
			return;
		}
		cout << "要查找的人信息如下" << endl;
		this->pp_peron[tmp]->ShowInfo();
		Sleep(3000);
	}
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		Sleep(2000);
		goto start;
		break;
	}
}
void Workmanager::Empty_person()
{
	cout << "确定要清空吗？" << endl;
start:
	cout << "1.确认    2.取消" << endl;
	int tmp = 0;
	cin >> tmp;
	if (1 == tmp)
	{
		this->m_person_num = 0;
		cout << "清空成功" << endl;
		return;
	}
	else if (2 == tmp)
	{
		return;
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		goto start;
	}
}
void Workmanager::Scending_sort()
{
	for (int i = 0;i<this->m_person_num; i++)
	{
		int min = i;
		for (int j = i + 1; j < this->m_person_num; j++)
		{
			if (this->pp_peron[j]->m_person_id< this->pp_peron[min]->m_person_id)
			{
				min = j;
			}
		}
		if (min != i)
		{
			Abstract_worker*tmp=this->pp_peron[i];
			this->pp_peron[i] = this->pp_peron[min];
			this->pp_peron[min] = tmp;
		}
	}
}
void Workmanager::Descending_sort()
{
	for (int i = 0; i < this->m_person_num; i++)
	{
		int max = i;
		for (int j = i + 1; j < this->m_person_num; j++)
		{
			if (this->pp_peron[j]->m_person_id > this->pp_peron[max]->m_person_id)
			{
				max = j;
			}
		}
		if (max != i)
		{
			Abstract_worker* tmp = this->pp_peron[i];
			this->pp_peron[i] = this->pp_peron[max];
			this->pp_peron[max] = tmp;
		}
	}
}
void Workmanager::Sorterson()
{
start:
	cout << "1.升序排序   2.降序排序" << endl;
	int tmp = 0;
	cin >> tmp;
	if (1 == tmp)
	{
		//升序排序
		this->Scending_sort();
		cout << "排序完成" << endl;
	}
	else if (2 == tmp)
	{
		//降序排序
		this->Descending_sort();
		cout << "排序完成" << endl;
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		goto start;
	}
}
