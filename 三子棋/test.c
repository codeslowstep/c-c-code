#include"game.h"
void Test()
{
	char Board[ROW][COL] =
	{
		"## ",
		"#* ",
		"** "
	};
	//int ret = JudgeWin(Board);
	//if (ret == 0)
	//{
	//	;//��������
	//}
	//else if (ret == 1)
	//{
	//	printf("���Ӯ\n");
	//	return;
	//}
	//else if (ret == 2)
	//{
	//	printf("����Ӯ\n");
	//	return;
	//}
	//else
	//{
	//	printf("ƽ��\n");
	//	return;
	//}
	CherkerBoardInit(Board);
	BoardPrint(Board);
	while (1)
	{
		Playerplay(Board);
		BoardPrint(Board);
		int ret = JudgeWin(Board);
		if (ret == 0)
		{
			;//��������
		}
		else if (ret == 1)
		{
			printf("���Ӯ\n");
			return;
		}
		else if (ret == 2)
		{
			printf("����Ӯ\n");
			return;
		}
		else
		{
			printf("ƽ��\n");
			return;
		}
		system("cls");
		Computerplay(Board);
		BoardPrint(Board);
		ret = JudgeWin(Board);
		if (ret == 0)
		{
			;//��������
		}
		else if (ret == 1)
		{
			printf("���Ӯ\n");
			return;
		}
		else if (ret == 2)
		{
			printf("����Ӯ\n");
			return;
		}
		else
		{
			printf("ƽ��\n");
			return;
		}
	}
	
}
int main()
{
	Test();
	system("pause");
	return 0;
}