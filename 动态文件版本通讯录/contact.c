#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void Addcapacity(Contact*ps)
{
	Linkman*tmp=(Linkman*)realloc((void*)ps->p,2*ps->capacity*sizeof(Linkman));
	if (!tmp)
	{
		printf("����ʧ�ܣ�\n");
	}
	else
	{
		ps->p = tmp;
		ps->capacity *= 2;
	}
	
}
void Addperson(Contact* ps)
{
	//����Ƿ�����
	if (ps->capacity > ps->size)
	{
		//���Լ���
		printf("����������\n");
		scanf("%s", ps->p[ps->size].name);
		printf("����������\n");
		scanf("%d", &ps->p[ps->size].age);
		printf("�������Ա�\n");
		scanf("%s", ps->p[ps->size].sex);
		printf("������绰����\n");
		scanf("%s", ps->p[ps->size].phone);
		printf("������סַ\n");
		scanf("%s", ps->p[ps->size].address);
		printf("��ӳɹ���\n");
		ps->size++;
	}
	else//����,��������
	{
		Addcapacity(ps);
		printf("����������\n");
		scanf("%s", ps->p[ps->size].name);
		printf("����������\n");
		scanf("%d", &ps->p[ps->size].age);
		printf("�������Ա�\n");
		scanf("%s", ps->p[ps->size].sex);
		printf("������绰����\n");
		scanf("%s", ps->p[ps->size].phone);
		printf("������סַ\n");
		scanf("%s", ps->p[ps->size].address);
		printf("��ӳɹ���\n");
		ps->size++;
	}
}
void ShowLinkman(const Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("������%-10s���䣺%-5d�绰��%-15sסַ��%-15s�Ա�%-5s\n", ps->p[i].name, ps->p[i].age, ps->p[i].phone, ps->p[i].address, ps->p[i].sex);
	}
}
void Deleteperson(Contact* ps)
{
	if (!ps->size)
	{
		printf("û����ϵ�ˣ��޷�ɾ��\n");
	}
	else
	{
		printf("��������Ҫɾ������ϵ�˵�����\n");
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
				printf("ɾ���ɹ�\n");
				break;
			}
		}
		if (i == ps->size)
		{
			printf("�Ҳ�����Ҫɾ������\n");
		}
	}
}
void Seekperson(const Contact* ps)
{
	printf("��������Ҫ���ҵ��˵�����\n");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->p[i].name, tmp))
		{
			printf("������Ϣ����\n");
			printf("������%-10s���䣺%-5d�绰��%-15sסַ��%-15s�Ա�%-5s\n", ps->p[i].name, ps->p[i].age, ps->p[i].phone, ps->p[i].address, ps->p[i].sex);
			break;
		}
	}
	if (i == ps->size)
	{
		printf("�Ҳ�����Ҫ���ҵ���\n");
	}
}
void Modifyperson(Contact* ps)
{
	printf("��������Ҫ�޸ĵ��˵�����\n");
	char tmp[NAME_MAX] = { 0 };
	scanf("%s", tmp);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->p[i].name, tmp))
		{
			
			printf("�����������������\n");
			scanf("%s", ps->p[i].name);
			printf("���������������������\n");
			scanf("%d", &(ps->p[i].age));
			printf("������������������Ա�\n");
			scanf("%s", ps->p[i].sex);
			printf("�����������������绰����\n");
			scanf("%s", ps->p[i].phone);
			printf("�����������������סַ\n");
			scanf("%s", ps->p[i].address);
			printf("�޸ĳɹ���\n");
			break;
		}
	}
	if (i == ps->size)
	{
		printf("�Ҳ�����Ҫ�޸ĵ���ϵ��\n");
	}
}
void Saveperson_tofile(const Contact* ps)
{
	FILE*pf=fopen("contact.txt", "wb");
	if (!pf)
	{
		printf("д�ļ�ʱ�ļ���ʧ�ܣ�%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//ע��ǿת��ע��ͨѶ¼Ҫ���ļ���д�����ݷ���ͨѶ¼��ʲôλ��
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
		printf("���ļ�ʱ�ļ���ʧ�ܣ�%s", strerror(errno));
		return;
	}
	int count = 0;
	while (fread((void*)(ps->p+count), sizeof(Linkman), 1, pf))//fread����ʵ�ʶ�ȡ����Ԫ�ظ���
	{
		//ע��ǿתΪvoid*,ע��������ݷ�����ͨѶ¼�е�λ��
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