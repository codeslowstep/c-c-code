#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void Addcapacity(Contact*ps)
{
	Linkman*tmp=(Linkman*)realloc((void*)ps->p,2*ps->capacity*sizeof(Linkman));
	if (!tmp)
	{
		printf("扩容失败！\n");
	}
	else
	{
		ps->p = tmp;
		ps->capacity *= 2;
	}
	
}
void Addperson(Contact* ps)
{
	//检查是否满了
	if (ps->capacity > ps->size)
	{
		//可以加人
		printf("请输入姓名\n");
		scanf("%s", ps->p[ps->size].name);
		printf("请输入年龄\n");
		scanf("%d", &ps->p[ps->size].age);
		printf("请输入性别\n");
		scanf("%s", ps->p[ps->size].sex);
		printf("请输入电话号码\n");
		scanf("%s", ps->p[ps->size].phone);
		printf("请输入住址\n");
		scanf("%s", ps->p[ps->size].address);
		printf("添加成功！\n");
		ps->size++;
	}
	else//满了,进行扩容
	{
		Addcapacity(ps);
		printf("请输入姓名\n");
		scanf("%s", ps->p[ps->size].name);
		printf("请输入年龄\n");
		scanf("%d", &ps->p[ps->size].age);
		printf("请输入性别\n");
		scanf("%s", ps->p[ps->size].sex);
		printf("请输入电话号码\n");
		scanf("%s", ps->p[ps->size].phone);
		printf("请输入住址\n");
		scanf("%s", ps->p[ps->size].address);
		printf("添加成功！\n");
		ps->size++;
	}
}
void ShowLinkman(const Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("姓名：%-10s年龄：%-5d电话：%-15s住址：%-15s性别：%-5s\n", ps->p[i].name, ps->p[i].age, ps->p[i].phone, ps->p[i].address, ps->p[i].sex);
	}
}
void Deleteperson(Contact* ps)
{
	if (!ps->size)
	{
		printf("没有联系人，无法删除\n");
	}
	else
	{
		printf("请输入想要删除的联系人的姓名\n");
		char tmp[NAME_MAX] = { 0 };
		scanf("%s", tmp);
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			if (!strcmp(ps->p[i].name, tmp))
			{
				int j = 0;
				for (j = i + 1; j < ps->size; j++)
				{
					ps->p[j - 1] = ps->p[j];
				}
				ps->size--;
				printf("删除成功\n");
				break;
			}
		}
		if (i == ps->size)
		{
			printf("找不到想要删除的人\n");
		}
	}
}
void Seekperson(const Contact* ps)
{
	printf("请输入想要查找的人的姓名\n");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->p[i].name, tmp))
		{
			printf("此人信息如下\n");
			printf("姓名：%-10s年龄：%-5d电话：%-15s住址：%-15s性别：%-5s\n", ps->p[i].name, ps->p[i].age, ps->p[i].phone, ps->p[i].address, ps->p[i].sex);
			break;
		}
	}
	if (i == ps->size)
	{
		printf("找不到想要查找的人\n");
	}
}
void Modifyperson(Contact* ps)
{
	printf("请输入想要修改的人的姓名\n");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->p[i].name, tmp))
		{
			
			printf("请重新输入此人姓名\n");
			scanf("%s", ps->p[i].name);
			printf("请重新输入此人输入年龄\n");
			scanf("%d", &(ps->p[i].age));
			printf("请重新输入此人输入性别\n");
			scanf("%s", ps->p[i].sex);
			printf("请重新输入此人输入电话号码\n");
			scanf("%s", ps->p[i].phone);
			printf("请重新输入此人输入住址\n");
			scanf("%s", ps->p[i].address);
			printf("修改成功！\n");
			break;
		}
	}
	if (i == ps->size)
	{
		printf("找不到想要修改的联系人\n");
	}
}
void Saveperson_tofile(const Contact* ps)
{
	FILE*pf=fopen("contact.txt", "wb");
	if (!pf)
	{
		printf("写文件时文件打开失败：%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//注意强转，注意通讯录要向文件中写的内容放在通讯录的什么位置
		fwrite((const void *)(ps->p+i), sizeof(Linkman), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
void Getfileperson(Contact* ps)
{
	FILE*pf=fopen("contact.txt", "rb");
	if (!pf)
	{
		printf("读文件时文件打开失败：%s", strerror(errno));
		return;
	}
	int count = 0;
	while (fread((void*)(ps->p+count), sizeof(Linkman), 1, pf))//fread返回实际读取到的元素个数
	{
		//注意强转为void*,注意读的内容放置在通讯录中的位置
		ps->size++;
		if (ps->size == ps->capacity)
		{
			Addcapacity(ps);
		}
		count++;
	}
	fclose(pf);
	pf = NULL;
}