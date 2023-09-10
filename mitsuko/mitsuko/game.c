#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void init_board(char board[ROW][LON], int row, int lon)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < lon; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][LON],int row,int lon)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < lon; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < lon - 1)
				printf("|");
		}
		printf("\n");
        if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < lon; j++)
			{
				printf("---");
				if (j < LON - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][LON], int row, int lon)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= lon)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入");
		}
		else
			printf("位置非法，请重新输入！");
	}
}
void computermove(char board[ROW][LON],int row,int lon)
{
	int x = 0;
	int y = 0;
	while (1)
	{
	    x = rand() % row;
	    y = rand() % lon;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int isfull(char board[ROW][LON],int row ,int lon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < lon; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char is_win(char board[ROW][LON], int row, int lon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (j = 0; j < lon; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (isfull(board,ROW,LON))
		return 'Q';
}
