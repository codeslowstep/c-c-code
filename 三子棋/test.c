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
	//	;//继续下棋
	//}
	//else if (ret == 1)
	//{
	//	printf("玩家赢\n");
	//	return;
	//}
	//else if (ret == 2)
	//{
	//	printf("电脑赢\n");
	//	return;
	//}
	//else
	//{
	//	printf("平局\n");
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
			;//继续下棋
		}
		else if (ret == 1)
		{
			printf("玩家赢\n");
			return;
		}
		else if (ret == 2)
		{
			printf("电脑赢\n");
			return;
		}
		else
		{
			printf("平局\n");
			return;
		}
		system("cls");
		Computerplay(Board);
		BoardPrint(Board);
		ret = JudgeWin(Board);
		if (ret == 0)
		{
			;//继续下棋
		}
		else if (ret == 1)
		{
			printf("玩家赢\n");
			return;
		}
		else if (ret == 2)
		{
			printf("电脑赢\n");
			return;
		}
		else
		{
			printf("平局\n");
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