#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_arr(char GongGe[ROW][COL], int row, int col);
void print_GongGe(char GongGe[ROW][COL], int row, int col);
void playr_move(char GongGe[ROW][COL], int row, int col);
void computer_move(char GongGe[ROW][COL], int row, int col);
char is_winer(char GongGe[ROW][COL], int row, int col);