#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_arr(char GongGe[ROW][COL],int row,int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			GongGe[i][j] = ' ';
		}
	}
}

void print_GongGe(char GongGe[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", GongGe[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void playr_move(char GongGe[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入您要下的坐标->\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3 && GongGe[x-1][y-1] == ' ')
		{
			GongGe[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("非法输入，请重新输入！\n");
		}
	}
}

void computer_move(char GongGe[ROW][COL], int row, int col)
{
	printf("电脑下->\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && GongGe[x][y] == ' ')
		{
			GongGe[x][y] = '#';
			break;
		}
	}
}

char is_winer(char GongGe[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (GongGe[i][0] == GongGe[i][1] && GongGe[i][1] == GongGe[i][2] && GongGe[i][1] != ' ')
		{
			return GongGe[i][1];
		}
	}
	for (j = 0; j < col; j++)
	{
		if (GongGe[0][j] == GongGe[1][j] && GongGe[1][j] == GongGe[2][j] && GongGe[1][j] != ' ')
		{
			return GongGe[1][j];
		}
	}
	if (GongGe[0][2] == GongGe[1][1] && GongGe[1][1] == GongGe[2][0] && GongGe[1][1] != ' ')
	{
		return GongGe[1][1];
	}
	if (GongGe[0][0] == GongGe[1][1] && GongGe[1][1] == GongGe[2][2] && GongGe[1][1] != ' ')
	{
		return GongGe[1][1];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (GongGe[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 'p';
}