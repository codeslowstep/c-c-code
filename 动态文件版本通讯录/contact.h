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
//联系人结构体
typedef struct Link
{
	int age;
	char sex[SEX_MAX];
	char name[NAME_MAX];
	char phone[PHONE_MAX];
	char address[ADDRESS_MAX];
}Linkman;
//整个通讯录
typedef struct Contact1
{
	int capacity;//通讯录容量
	int size;//实际联系人个数
	Linkman* p;//指针开辟一块堆区内存存放联系人信息
}Contact;
void Addperson(Contact* ps);
void ShowLinkman(const Contact* ps);
void Deleteperson(Contact* ps);
void Seekperson(const Contact* ps);
void Modifyperson(Contact* ps);
void Saveperson_tofile(const Contact* ps);
void Getfileperson(Contact* ps);