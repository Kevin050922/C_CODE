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
			printf("��ѡ��:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("��ʼɨ�ף�\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������\n");
			}
	}
	while (input);
	return 0;
}