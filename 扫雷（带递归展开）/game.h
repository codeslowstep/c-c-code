#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)
#define ROW 9
#define COL 9
#define BROW ROW+2
#define BCOL COL+2
#define EASY_COUNT 10
void InitBoard(char arr[BROW][BCOL], int brow, int bcol, char dst);
void PrintBoard(char arr[BROW][BCOL], int row, int col);
void Setmines(char arr[BROW][BCOL], int row, int col, int minecount);
void Mine_clearance(char board[BROW][BCOL],char backstage[BROW][BCOL], int row, int col);
bool Iswin(char board[BROW][BCOL], int row, int col,int minecount);