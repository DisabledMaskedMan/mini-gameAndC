#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void meun()
{
	printf("***************************\n");
	printf("***** 1.play   0.exit *****\n");
	printf("***************************\n");
}

void chess()
{
	char GongGe[ROW][COL] = { 0 };
	init_arr(GongGe, ROW, COL);
	print_GongGe(GongGe, ROW, COL);
	while (1)
	{
		playr_move(GongGe, ROW, COL);
		print_GongGe(GongGe, ROW, COL);
		char ret = is_winer(GongGe, ROW, COL);
		if (ret == '*')
		{
			printf("玩家赢\n");
			break;
		}
		else if (ret == 'p')
		{
			printf("平局\n");
			break;
		}
		computer_move(GongGe, ROW, COL);
		print_GongGe(GongGe, ROW, COL);
		ret = is_winer(GongGe, ROW, COL);
		if (ret == '#')
		{
			printf("电脑赢\n");
			break;
		}
		else if (ret == 'p')
		{
			printf("平局\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		meun();
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			chess();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}