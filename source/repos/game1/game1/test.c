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
			printf("���Ӯ\n");
			break;
		}
		else if (ret == 'p')
		{
			printf("ƽ��\n");
			break;
		}
		computer_move(GongGe, ROW, COL);
		print_GongGe(GongGe, ROW, COL);
		ret = is_winer(GongGe, ROW, COL);
		if (ret == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		else if (ret == 'p')
		{
			printf("ƽ��\n");
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
		printf("������->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			chess();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}