#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<Windows.h>
#define SEX_MAX 10
#define NAME_MAX 30
#define PHONE_MAX 20
#define ADDRESS_MAX 40
//��ϵ�˽ṹ��
typedef struct Link
{
	int age;
	char sex[SEX_MAX];
	char name[NAME_MAX];
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
}Linkman;
//����ͨѶ¼
typedef struct Contact1
{
	int capacity;//ͨѶ¼����
	int size;//ʵ����ϵ�˸���
	Linkman* p;//ָ�뿪��һ������ڴ�����ϵ����Ϣ
}Contact;
void Addperson(Contact* ps);
void ShowLinkman(const Contact* ps);
void Deleteperson(Contact* ps);
void Seekperson(const Contact* ps);
void Modifyperson(Contact* ps);
void Saveperson_tofile(const Contact* ps);
void Getfileperson(Contact* ps);