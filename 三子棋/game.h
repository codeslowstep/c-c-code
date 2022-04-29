#include<stdio.h>
#include<Windows.h>
#include<time.h>
#pragma warning(disable:4996)
#define ROW 5
#define COL 5
void CherkerBoardInit(char Board[ROW][COL]);
void BoardPrint(char Board[ROW][COL]);
void Computerplay(char Board[ROW][COL]);
void Playerplay(char Board[ROW][COL]);
int JudgeWin(char Board[ROW][COL]);