#define _CRT_SECURE_NO_WARNINGS
#include"Workmanager.h"
#include"manager.h"
#include"Ordinary member.h"
#include"Boss.h"
#include<Windows.h>
Workmanager::Workmanager()
{
	//�����ļ��е�����,���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open())
	{
		/*cout << "�ļ�������" << endl;*/
		this->File_is_empty= true;
		this->m_person_num = 0;
		this->pp_peron = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڵ���Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())//ifs.eof()Ϊ��ͱ�ʾ�ļ�Ϊ��
	{
		/*cout << "�ļ�Ϊ��" << endl;*/
		this->File_is_empty = true;
		this->m_person_num = 0;
		this->pp_peron = NULL;
		ifs.close();
		return;
	}
	//�ļ������Ҳ�Ϊ��
	int num = this->Get_file_personnum();
	/*cout << "�ļ���ְ��������Ϊ" << num << endl;*/
	this->m_person_num = num;
	//���ٿռ�
	this->pp_peron = new Abstract_worker * [num];
	//�����ļ��е���
	this->Initperson();
}
Workmanager::~Workmanager()
{
	if (this->pp_peron != NULL)//����ʵ�֣���������
	{
		delete[] this->pp_peron;
		//delete[] this->pp_person�ȼ���
		//delete[] this->pp_person[i]
		this->pp_peron = NULL;
	}
}

//�˵�
void Workmanager::menu()
{
	cout << "**************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "**********0.�˳�����ϵͳ**************" << endl;
	cout << "**********1.����ְ����Ϣ**************" << endl;
	cout << "**********2.��ʾְ����Ϣ**************" << endl;
	cout << "**********3.ɾ����ְְ��**************" << endl;
	cout << "**********4.�޸�ְ����Ϣ**************" << endl;
	cout << "**********5.����ְ����Ϣ**************" << endl;
	cout << "**********6.���ձ������**************" << endl;
	cout << "**********7.��������ĵ�**************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//�˳�
void Workmanager::Exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(-1);
}
void Workmanager::Addperson()
{
	cout << "��������ӵ�ְ��������" << endl;
	int addnum=0;
	cin >> addnum;
	if (addnum > 0)
	{
		//�¿ռ�����
		int newsize = this->m_person_num + addnum;
		Abstract_worker **tmp=new Abstract_worker* [newsize];
		//��ԭ���ռ�����ݿ������µĿռ�
		
		//ԭ�����ˣ��Ϳ���
		int i = 0;
		for (int i = 0; i < this->m_person_num; i++)
		{
			tmp[i] = this->pp_peron[i];
		}
		//���
		int a = this->m_person_num;
		for (int i = 0; i < addnum; i++)
		{
		start:

			int personid=0;
			string name;
			int departmentid=0;
			cout << "�������" << i + 1 << "����Ա���ı��" << endl;
			cin >> personid;
			cout << "�������" << i + 1 << "����Ա��������" << endl;
			cin >> name;
			cout << "��ѡ��ְ���ĸ�λ:" << endl;
			cout << "1.��ͨԱ��  2.����  3.�ϰ�" << endl;
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
				cout << "ѡ�����������ѡ��" << endl;
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
			//�ͷ�ԭ�пռ�
			if (0 == i)
			{
				delete[] this->pp_peron;
			}
			//������൱���ͷ���pp_person[i],i��0��this->size
			//����pp_personû���ͷţ�pp_person����ָ��һ��ռ䣬�ռ����ж���Abstract_work*
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
		cout << "�ɹ����" << addnum << "��ְ��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
}
void Workmanager::Showperson()
{
	if (!this->m_person_num)
	{
		cout << "û����Ա" << endl;
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
	ifs.open(FILENAME, ios::in);//���ļ�
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
		if (1 == did)//��ͨԱ��
		{
			tmp = new Ordinary_member(id, name, did);
		}
		else if (2 == did)//����
		{
			tmp = new Manager(id, name, did);
		}
		else if (3 == did)//�ϰ�
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
	cout << "1.��������ɾ��   2.���ұ��ɾ��" << endl;
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
		cout << "�����������������" << endl;
		goto start;
		break;
	}
}
//��������ɾ��
void Workmanager::Deleteperson_by_name()
{
	string name;
	cout << "��������Ҫɾ����Person������" << endl;
	cin >> name;
	int tmp = this->Seek_by_name(name);
	if (tmp == -1)
	{
		cout << "��Ҫɾ����Person������" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
}
//���ݱ��ɾ��
void Workmanager::Deleteperson_by_personid()
{
	int personid;
	cout << "��������Ҫɾ����Person�ı��" << endl;
	cin >> personid;
	int tmp=this->Seek_by_id(personid);
	if (tmp == -1)
	{
		cout << "��Ҫɾ����Person������" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
}
//������������
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
//����id����
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
//���������޸�
void Workmanager::Modifyperson_by_name()
{
	string name;
	cout << "��������Ҫ�޸ĵ�Person������" << endl;
	cin >> name;
	string tname;
	int tpersonid=0;
	int tdepartid=0;
	int tmp = this->Seek_by_name(name);
	if (tmp == -1)
	{
		cout << "��Ҫ�޸ĵ�Person������" << endl;
	}
	else
	{
		//�޸�֮ǰҪ��ɾ��ԭ������Ϣ
		delete this->pp_peron[tmp];
		this->pp_peron[tmp] = NULL;
		cout << "�����������Ա���ı��" << endl;
		cin >> tpersonid;
		cout << "�����������Ա��������" << endl;
		cin >> tname;
		cout << "�����������Ա���ĸ�λ" << endl;
		start:
		cout << "1.��ͨԱ��  2.����  3.�ϰ�" << endl;
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
			cout << "�����������������" << endl;
			goto start;
			break;
		}
		cout << "�޸ĳɹ�" << endl;
	}
}
//����id�޸�
void Workmanager::Modifyperson_by_personid()
{
	int t;
	cout << "��������Ҫ�޸ĵ�Person��id" << endl;
	cin >> t;
	string tname;
	int tpersonid=0;
	int tdepartid=0;
	int tmp = this->Seek_by_id(t);
	if (tmp == -1)
	{
		cout << "��Ҫ�޸ĵ�Person������" << endl;
	}
	else
	{
		//�޸�֮ǰҪ��ɾ��ԭ������Ϣ
		delete this->pp_peron[tmp];
		this->pp_peron[tmp] = NULL;
		cout << "�����������Ա���ı��" << endl;
		cin >> tpersonid;
		cout << "�����������Ա��������" << endl;
		cin >> tname;
		cout << "�����������Ա���ĸ�λ" << endl;
	start:
		cout << "1.��ͨԱ��  2.����  3.�ϰ�" << endl;
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
			cout << "�����������������" << endl;
			goto start;
			break;
		}
		cout << "�޸ĳɹ�" << endl;
	}
}
void Workmanager::Modify_person()
{
	int select = 0;
	cout << "1.���������޸�   2.���ұ���޸�" << endl;
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
		cout << "�����������������" << endl;
		goto start;
		break;
	}
}
void Workmanager::Seekperson()
{
	int select = 0;
	cout << "1.������������   2.���ձ�Ų���" << endl;
start:
	cin >> select;
	switch (select)
	{
	case 1:
	{
		string name;
		cout << "��������Ҫ���ҵ��˵�����" << endl;
		cin >> name;
		int tmp = this->Seek_by_name(name);
		if (tmp == -1)
		{
			cout << "�Ҳ���Ҫ���ҵ���" << endl;
			Sleep(1000);
			return;
		}
		cout << "Ҫ���ҵ�����Ϣ����" << endl;
		this->pp_peron[tmp]->ShowInfo();
		Sleep(3000);
	}
		break;
	case 2:
	{
		int a;
		cout << "��������Ҫ���ҵ��˵ı��" << endl;
		cin >> a;
		int tmp = this->Seek_by_id(a);
		if (tmp == -1)
		{
			cout << "�Ҳ���Ҫ���ҵ���" << endl;
			Sleep(1000);
			return;
		}
		cout << "Ҫ���ҵ�����Ϣ����" << endl;
		this->pp_peron[tmp]->ShowInfo();
		Sleep(3000);
	}
		break;
	default:
		cout << "�����������������" << endl;
		Sleep(2000);
		goto start;
		break;
	}
}
void Workmanager::Empty_person()
{
	cout << "ȷ��Ҫ�����" << endl;
start:
	cout << "1.ȷ��    2.ȡ��" << endl;
	int tmp = 0;
	cin >> tmp;
	if (1 == tmp)
	{
		this->m_person_num = 0;
		cout << "��ճɹ�" << endl;
		return;
	}
	else if (2 == tmp)
	{
		return;
	}
	else
	{
		cout << "�����������������" << endl;
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
	cout << "1.��������   2.��������" << endl;
	int tmp = 0;
	cin >> tmp;
	if (1 == tmp)
	{
		//��������
		this->Scending_sort();
		cout << "�������" << endl;
	}
	else if (2 == tmp)
	{
		//��������
		this->Descending_sort();
		cout << "�������" << endl;
	}
	else
	{
		cout << "�����������������" << endl;
		goto start;
	}
}
