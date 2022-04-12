#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("***********0.退出通讯录************\n");
	printf("***********1.增加联系人************\n");
	printf("***********2.删除联系人************\n");
	printf("***********3.查找联系人************\n");
	printf("***********4.修改联系人************\n");
	printf("***********5.显示联系人************\n");
	printf("***********************************\n");
}
int main()
{
	Contact test;
	test.capacity = 1;
	test.p = calloc(1, sizeof(Linkman));//初始空间为2
	test.size = 0;
	//每次运行，都导入文件中的联系人
	Getfileperson(&test);
	while (1)
	{
		menu();//菜单
		int select = 0;
		printf("请选择：\n");
		scanf("%d", &select);
		switch (select)
		{
		case 0://退出通讯录
			printf("欢迎下次使用\n");
			//退出通讯录时，自动将联系人保存在文件中
			system("cls");
			Saveperson_tofile(&test);
			free(test.p);
			test.p = NULL;
			goto end;
			break;
		case 1://增加联系人
			Addperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 2://删除联系人
			Deleteperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 3://查找联系人
			Seekperson(&test);
			Sleep(3000);
			system("cls");
			break;
		case 4://修改联系人
			Modifyperson(&test);
			Sleep(1000);
			system("cls");
			break;
		case 5://显示联系人
			ShowLinkman(&test);
			Sleep(5000);
			system("cls");
			break;
		default:
			printf("选择错误，请重新选择\n");
			system("cls");
			break;
		}
	}
end:
	system("pause");
	return 0;
}