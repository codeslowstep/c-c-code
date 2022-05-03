#include"game.h"
void Test()
{
	srand((unsigned int)time(0));
	char backstage[BROW][BCOL];//后台
	char board[BROW][BCOL];
	InitBoard(board, BROW, BCOL, '*');
	InitBoard(backstage, BROW, BCOL, '0');
	Setmines(backstage, ROW, COL, EASY_COUNT);
	PrintBoard(backstage, ROW, COL);
	while (1)
	{
		PrintBoard(board, ROW, COL);
		Mine_clearance(board, backstage, ROW, COL);//排雷
		if (Iswin(board, ROW, COL, EASY_COUNT))
		{
			printf("排雷成功\n");
			PrintBoard(backstage, ROW, COL);
			return;
		}
		system("cls");
	}
	
}
int main()
{
	Test();
	system("pause");
	return 0;
}