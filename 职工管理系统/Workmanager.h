#pragma once
#include<iostream>
#include<fstream>
#include"Abstract worker.h"
#define FILENAME "test.txt"
using namespace std;
//�ܵĹ�����
//1.�˵�
//2.��ְ������ɾ���
//3.���ļ���д����
class Workmanager
{
public:
	//����
	Workmanager();

	//�˵�
	void menu();

	//��¼ְ������
	int m_person_num;

	//ְ������ָ��,����pp_person[]��ָ��һ�������ְ��
	//pp_person[]��һ��Abstract_worker*���ͣ���һ������ָ��
	Abstract_worker** pp_peron;

	//���ְ��
	void Addperson();
	//�ж�ְ���Ƿ�Ϊ��
	bool File_is_empty;
	//ͳ���ļ��е�����
	int Get_file_personnum();
	//��ʼ��Ա��
	void Initperson();
	//��ʾԱ����Ϣ
	void Showperson();
	//ʵ���˳�����
	void Exitsystem();
	//����Ա��Ϣд���ļ���
	void Write_to_file();
	//ɾ��ְ��
	void Delperson();
	//��������ɾ��
	void Deleteperson_by_name();
	//���ݱ��ɾ��
	void Deleteperson_by_personid();
	//������������
	int Seek_by_name(string name);
	//����id����
	int Seek_by_id(int id);
	//�޸�ְ����Ϣ
	void Modify_person();
	//���������޸�
	void Modifyperson_by_name();
	//����id�޸�
	void Modifyperson_by_personid();
	//����
	void Seekperson();
	//���
	void Empty_person();
	//����
	void Sorterson();
	//��������
	void Scending_sort();
	//��������
	void Descending_sort();
	//����
	~Workmanager();

	
};