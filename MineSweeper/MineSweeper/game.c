#define _CRT_SECURE_NO_WARNINGS//第一行
#include"game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < ROWS; i++)
	{
		int j = 0;
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 1;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void setmain(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_AMOUNT;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int sweep_main(char board[ROWS][COLS],int x,int y)
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
}
void find_main(char main[ROWS][COLS], char play[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_AMOUNT)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (play[x][y] == '*')
			{
				if (main[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					displayboard(main, ROW, COL);
					break;
				}
				else
				{
					int num = sweep_main(main, x, y);
					play[x][y] = num + '0';
					displayboard(play, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("坐标已经扫过了，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
	if (win == row * col - EASY_AMOUNT)
	{
		printf("恭喜你，游戏胜利！！！\n");
		displayboard(main, ROW, COL);
	}
}