#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define LON 3

//��ʼ������
void init_board(char board[ROW][LON],int row,int lon);

//��ӡ����
void print_board(char board[ROW][LON], int row, int lon);

//�������
void playermove(char board[ROW][LON], int row, int lon);

//��������
void computermove(char board[ROW][LON]);

//�ж���Ӯ
char is_win(char board[ROW][LON], int row, int lon);


