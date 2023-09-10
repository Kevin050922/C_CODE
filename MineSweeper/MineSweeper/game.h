#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_AMOUNT 10
void init_board(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmain(char board[ROWS][COLS], int row, int col);
void find_main(char main[ROWS][COLS], char play[ROWS][COLS], int rows, int cols);