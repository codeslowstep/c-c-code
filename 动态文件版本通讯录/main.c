#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("***********0.�˳�ͨѶ¼************\n");
	printf("***********1.������ϵ��************\n");
	printf("***********2.ɾ����ϵ��************\n");
	printf("***********3.������ϵ��************\n");
	printf("***********4.�޸���ϵ��************\n");
	printf("***********5.��ʾ��ϵ��************\n");
	printf("***********************************\n");
}
int main()
{
	Contact test;
	test.capacity = 1;
	test.p = calloc(1, sizeof(Linkman));//��ʼ�ռ�Ϊ2
	test.size = 0;
	//ÿ�����У��������ļ��е���ϵ��
	Getfileperson(&test);
	while (1)
	{
		menu();//�˵�
		int select = 0;
		printf("��ѡ��\n");
		scanf("%d", &select);
		switch (select)
		{
		case 0://�˳�ͨѶ¼
			printf("��ӭ�´�ʹ��\n");
			//�˳�ͨѶ¼ʱ���Զ�����ϵ�˱������ļ���
			system("cls");
			Saveperson_tofile(&test);
			free(test.p);
			test.p = NULL;
			goto end;
			break;
		case 1://������ϵ��
			Addperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 2://ɾ����ϵ��
			Deleteperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 3://������ϵ��
			Seekperson(&test);
			Sleep(3000);
			system("cls");
			break;
		case 4://�޸���ϵ��
			Modifyperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 5://��ʾ��ϵ��
			ShowLinkman(&test);
			Sleep(5000);
			system("cls");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			system("cls");
			break;
		}
	}
end:
	system("pause");
	return 0;
}