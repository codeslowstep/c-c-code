#define _CRT_SECURE_NO_WARNINGS
#include"Workmanager.h"
#include<Windows.h>
#include"Abstract worker.h"
#include"Boss.h"
#include"manager.h"
#include"Ordinary member.h"
int main()
{
	//创建一个大的管理系统的对象
	Workmanager total_system;
	while (true)
	{
		total_system.menu();
		int select = 0;
		cout << "请选择" << endl;
		cin >> select;
		switch (select)
		{
		case 0://退出
			total_system.Write_to_file();
			total_system.Exitsystem();
			break;
		case 1://增加
			total_system.Addperson();
			Sleep(1000);
			system("cls");
			break;
		case 2://显示
			total_system.Showperson();
			Sleep(3000);
			system("cls");
			break;
		case 3://删除
			total_system.Delperson();
			Sleep(1000);
			system("cls");
			break;
		case 4://修改
			total_system.Modify_person();
			Sleep(1000);
			system("cls");
			break;
		case 5://查找
			total_system.Seekperson();
			system("cls");
			break;
		case 6://按照编号排序
			total_system.Sorterson();
			Sleep(1000);
			system("cls");
			break;
		case 7://清空
			total_system.Empty_person();
			Sleep(1000);
			system("cls");
			break;
		default:
			printf("选择错误，请重新选择\n");
			Sleep(1500);
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}