#define _CRT_SECURE_NO_WARNINGS
#include"Workmanager.h"
#include<Windows.h>
#include"Abstract worker.h"
#include"Boss.h"
#include"manager.h"
#include"Ordinary member.h"
int main()
{
	//����һ����Ĺ���ϵͳ�Ķ���
	Workmanager total_system;
	while (true)
	{
		total_system.menu();
		int select = 0;
		cout << "��ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 0://�˳�
			total_system.Write_to_file();
			total_system.Exitsystem();
			break;
		case 1://����
			total_system.Addperson();
			Sleep(1000);
			system("cls");
			break;
		case 2://��ʾ
			total_system.Showperson();
			Sleep(3000);
			system("cls");
			break;
		case 3://ɾ��
			total_system.Delperson();
			Sleep(1000);
			system("cls");
			break;
		case 4://�޸�
			total_system.Modify_person();
			Sleep(1000);
			system("cls");
			break;
		case 5://����
			total_system.Seekperson();
			system("cls");
			break;
		case 6://���ձ������
			total_system.Sorterson();
			Sleep(1000);
			system("cls");
			break;
		case 7://���
			total_system.Empty_person();
			Sleep(1000);
			system("cls");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			Sleep(1500);
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}