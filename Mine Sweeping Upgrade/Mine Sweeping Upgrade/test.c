#define _CRT_SECURE_NO_WARNINGS 1

#include "Mine sweep.h"

void meun()
{
	printf("*******************************\n");
	printf("******* 1.play   0.exit *******\n");
	printf("*******************************\n");
}

void game()
{
	char Mine_board[ROWS][COLS] = { 0 };
	char Show_board[ROWS][COLS] = { 0 };
	Init_board(Mine_board, ROWS, COLS, '0');
	Init_board(Show_board, ROWS, COLS, '*');
	Print_board(Show_board, ROW, COL);
	Put_mine(Mine_board, ROW, COL, MINE);
	Find_mine(Mine_board, Show_board, ROW, COL);
	//Print_board(Mine_board, ROW, COL);
}


void test()
{
	int getnum = 0;
	do {
		printf("请输入->");
		scanf("%d", &getnum);
		switch (getnum)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("非法输入！请重新输入！\n");
			break;
		}
	} while (getnum);
}

int main()
{
	srand((unsigned int)time(NULL));
	meun();
	test();
	return 0;
}