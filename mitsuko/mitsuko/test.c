#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>
void menu()
{
	printf("**************************\n");
	printf("******1.play  0.exit******\n");
	printf("**************************\n");
}
void game()
{
	char board[ROW][LON] = { 0 };
	init_board(board,ROW,LON);
	print_board(board, ROW, LON);
	while (1)
	{
		//开始下棋
		playermove(board, ROW, LON);
		char n = is_win(board, ROW, LON);
		if (n != 'C')
		{
			if (n == '*')
			{
				print_board(board, ROW, LON);
				printf("玩家胜利\n");
				break;
			}
			if (n == '#')
			{
				print_board(board, ROW, LON);
				printf("电脑胜利\n");
				break;
			}
			if (n == 'Q')
			{
				print_board(board, ROW, LON);
				printf("平局了\n");
				break;
			}
		}
		print_board(board, ROW, LON);
		computermove(board,ROW,LON);
		if (n != 'C')
		{
			if (n == '*')
			{
				print_board(board, ROW, LON);
				printf("玩家胜利\n");
				break;
			}
			if (n == '#')
			{
				print_board(board, ROW, LON);
				printf("电脑胜利\n");
				break;
			}
			if (n == 'Q')
			{
				print_board(board, ROW, LON);
				printf("平局了\n");
				break;
			}
		}
		print_board(board, ROW, LON);
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始！！\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
