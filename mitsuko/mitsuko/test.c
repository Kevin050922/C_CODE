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
		//��ʼ����
		playermove(board, ROW, LON);
		char n = is_win(board, ROW, LON);
		if (n != 'C')
		{
			if (n == '*')
			{
				print_board(board, ROW, LON);
				printf("���ʤ��\n");
				break;
			}
			if (n == '#')
			{
				print_board(board, ROW, LON);
				printf("����ʤ��\n");
				break;
			}
			if (n == 'Q')
			{
				print_board(board, ROW, LON);
				printf("ƽ����\n");
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
				printf("���ʤ��\n");
				break;
			}
			if (n == '#')
			{
				print_board(board, ROW, LON);
				printf("����ʤ��\n");
				break;
			}
			if (n == 'Q')
			{
				print_board(board, ROW, LON);
				printf("ƽ����\n");
				break;
			}
		}
		print_board(board, ROW, LON);
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//������������������
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ����\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}
