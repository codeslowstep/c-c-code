#include"game.h"
void CherkerBoardInit(char Board[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			Board[i][j] = ' ';
		}
	}
}
void BoardPrint(char Board[ROW][COL])
{
	//printf("   |   |   \n");
	//printf("---|---|---\n");
	//printf("   |   |   \n");
	//printf("---|---|---\n");
	//printf("   |   |   \n");

	int i = 0;
	int j = 0;
	printf("��ң�#     ���ԣ�*\n");
	for (i = 0; i < 5 * COL - 1; i++)
	{
		if (i == 2)
			printf("��");
		else if (i >=4&&i%4==0)
			printf("%d",i/4);
		else
			printf(" ");
	}
	printf("\n");
	printf("��\n");
	for (i = 0; i < ROW; i++)
	{
		printf("%d   ", i + 1);
		for (j = 0; j < COL; j++)
		{
			if(j!=COL-1)
				printf(" %c |", Board[i][j]);
			else
				printf(" %c ", Board[i][j]);
		}
		printf("\n    ");
		for (j = 0; j < COL; j++)
		{
			if (j != COL - 1)
				printf("---|");
			else
				printf("---");
		}
		printf("\n");
	}
}
void Computerplay(char Board[ROW][COL])
{
	/*printf("������\n");*/
	srand((unsigned)time(NULL));
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = '*';
			break;
		}
	}
}
void Playerplay(char Board[ROW][COL])
{
	printf("�����\n");
	int x = 0;
	int y = 0;
	printf("����������(x,y)\n");
	start:
	scanf("%d,%d", &x, &y);
	if (x < 1 || x > ROW || y < 1 || y > COL)
	{
		printf("���������������\n");
		goto start;
	}
	if (Board[x - 1][y - 1] == ' ')
		Board[x - 1][y - 1] = '#';
	else
	{
		printf("���������������\n");
		goto start;
	}
}
int JudgeWin(char Board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		char tmp = Board[i][0];
		int count = 0;
		for (j = 0; j < COL; j++)
		{
			if (Board[i][j] == tmp)
				count++;
		}
		if (count == COL)
		{
			if (tmp == '#')
				return 1;//���Ӯ
			if (tmp == '*')
				return 2;//����Ӯ
		}
	}
	for (i = 0; i < COL; i++)
	{
		char tmp = Board[0][i];
		int count = 0;
		for (j = 0; j < ROW; j++)
		{
			if (Board[j][i] == tmp)
				count++;
		}
		if (count == COL)
		{
			if (tmp == '#')
				return 1;//���Ӯ
			if (tmp == '*')
				return 2;//����Ӯ
		}
	}
	int count2 = 0;
	int diagonal = 0;//���Խ��߼���
	for (i = 0, j = 0;i<ROW; i++, j++)
	{
		if (Board[i][j] == Board[0][0])
		{
			diagonal++;
		}
	}
	if (diagonal == ROW && Board[0][0] == '#')
	{
		return 1;//���Ӯ
	}
	if (diagonal == ROW && Board[0][0] == '*')
	{
		return 2;//����Ӯ
	}
	//���Խ���
	int diagonalz = 0;
	for (i = ROW-1, j = 0; j < COL; i--, j++)
	{
		if (Board[i][j] == Board[ROW/2][COL / 2 ])
		{
			diagonalz++;
		}
	}
	if (diagonalz == ROW && Board[ROW / 2][COL / 2] == '#')
	{
		return 1;//���Ӯ
	}
	if (diagonalz == ROW && Board[ROW / 2][COL / 2] == '*')
	{
		return 2;//����Ӯ
	}
	int draw = 0;//ͳ��ƽ��
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (Board[i][j] != ' ')
				draw++;
		}
	}
	if (draw == ROW * COL)
		return -1;//ƽ��
	return 0;//��������
}