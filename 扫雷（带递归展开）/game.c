#include"game.h"
void InitBoard(char arr[BROW][BCOL], int brow, int bcol, char dst)
{
	int i = 0;
	for (i = 0; i < brow; i++)
	{
		int j = 0;
		for (j = 0; j < bcol; j++)
		{
			arr[i][j] = dst;
		}
	}
}
void PrintBoard(char arr[BROW][BCOL], int row, int col)
{
	int i = 1;
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 1;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void Setmines(char arr[BROW][BCOL], int row, int col,int minecount)
{
	int x, y;
	int count = minecount;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
int CountMinesize(char backstage[BROW][BCOL], int x, int y)
{
	int i = 0, j = 0,count=0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
			count += backstage[i][j];
	}
	return count - 9 * '0';
}
//利用' '防止死递归 
void Recursive_statistics(char board[BROW][BCOL], char backstage[BROW][BCOL], int x, int y,int row, int col)
{

	board[x][y] = CountMinesize(backstage, x, y) + '0';
	if (board[x][y] == '0')
	{
		board[x][y] = ' ';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if ((i != x || j != y) && board[i][j] != ' ')
				{
					board[i][j] = CountMinesize(backstage, i, j) + '0';
				}
			}
		}
	}
	if (board[x][y] == ' '&&x>1&&x<ROW&&y>1&&y<COL)
	{
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if ((i != x || j != y)&&board[i][j]!=' ')
				{
					Recursive_statistics(board, backstage, i, j, row, col);
				}
			}
		}
	}
}
void Mine_clearance(char board[BROW][BCOL],char backstage[BROW][BCOL], int row, int col)
{
	printf("输入排雷坐标\n");
	int x = 0,y=0;
	start:
	scanf("%d %d", &x, &y);
	if(x < 1 || x > row || y < 1 || y > col)
	{
		printf("坐标有误，重新输入\n");
		goto start;
	}
	else
	{
		if (backstage[x][y] == '1')
		{
			printf("被炸死\n");
			PrintBoard(backstage, row, col);
			exit(0);
		}
		else
		{
			//Recursive_statistics(board, backstage, x, y);
			//board[x][y] = CountMinesize(backstage, x, y) + '0';
			//if (board[x][y] == '0')
			//{
			//	Recursive_statistics(board, backstage, x, y);
			//}
			Recursive_statistics(board, backstage, x, y, row, col);
		}
		
	}
}
bool Iswin(char board[BROW][BCOL], int row, int col, int minecount)
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] == '*')
				count++;
		}
	}
	if (count == minecount)
		return true;
	return false;
}