#define ROW 9
#define COL 9

#define ROWS  ROW+2
#define COLS  COL+2

#define MINE 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Init_board(char board[ROWS][COLS],int rows,int cols,char enchase);
void Print_board(char board[ROWS][COLS],int row,int col);
void Put_mine(char board[ROWS][COLS], int row, int col);
int Find_mine(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);