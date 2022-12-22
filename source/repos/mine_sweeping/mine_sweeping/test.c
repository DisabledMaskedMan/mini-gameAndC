#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"

void meun()
{
	printf("***************************\n");
	printf("*****1.play   0.exit * ****\n");
	printf("***************************\n");
}

void game2()
{
	char Mine_board[ROWS][COLS] = { 0 };
	char Show_board[ROWS][COLS] = { 0 };
	Init_board(Mine_board, ROWS, COLS, '0');
	Init_board(Show_board, ROWS, COLS, '*');
	Print_board(Show_board, ROW, COL);
	Put_mine(Mine_board, ROW, COL);
	//Print_board(Mine_board, ROW, COL);
	int resl = Find_mine(Mine_board, Show_board, ROW, COL);
	if (resl == 0)
	{
		printf("您踩到了雷，游戏结束！");
	}
	if (resl == 1)
	{
		printf("恭喜您！扫雷成功！");
	}
}

void test()
{
	int getnum = 0;
	do
	{
		printf("请输入->");
		scanf("%d", &getnum);
		switch (getnum) {
		case 1:
			game2();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("非法输入，请重新输入！\n");
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