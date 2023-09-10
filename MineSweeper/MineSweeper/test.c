#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("***************************************\n");
	printf("*************    1.play    ************\n");
	printf("*************    0.exit    ************\n");
	printf("***************************************\n");
}
void game()
{
	char main[ROWS][COLS] = { 0 };
	char play[ROWS][COLS] = { 0 };
	init_board(main, ROWS, COLS, '0');
	init_board(play, ROWS, COLS, '*');
	setmain(main, ROW, COL);
	displayboard(play, ROW, COL);
	find_main(main,play,ROW,COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
			printf("请选择:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("开始扫雷！\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
			}
	}
	while (input);
	return 0;
}