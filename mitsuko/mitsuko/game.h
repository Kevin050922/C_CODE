#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define LON 3

//初始化棋盘
void init_board(char board[ROW][LON],int row,int lon);

//打印棋盘
void print_board(char board[ROW][LON], int row, int lon);

//玩家下棋
void playermove(char board[ROW][LON], int row, int lon);

//电脑下棋
void computermove(char board[ROW][LON]);

//判断输赢
char is_win(char board[ROW][LON], int row, int lon);


