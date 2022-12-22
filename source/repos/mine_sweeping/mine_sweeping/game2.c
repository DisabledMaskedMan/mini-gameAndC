#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"

void Init_board(char board[ROWS][COLS],int rows,int cols,char enchase)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = enchase;
		}
	}
}

void Print_board(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Put_mine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 1; i <= MINE; i++)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		board[x][y] = '1';
	}
}

int countmine(char mine_board[ROWS][COLS], int x, int y)
{
	int num = mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + mine_board[x][y - 1] + mine_board[x][y + 1] + mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 8 * '0';
	return num;
}

void Expand_board(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col, int x,int y)
{
	int ret = 0;
	if (show_board[x - 1][y - 1] == '*' && x - 1 >= 1 && x - 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		ret = countmine(mine_board, x - 1, y - 1);
		if (ret != 0)
		{
			show_board[x - 1][y - 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x - 1, y - 1);
		}
	}
	if (show_board[x - 1][y] == '*' && x - 1 >= 1 && x - 1 <= row && y >= 1 && y <= col)
	{
		ret = countmine(mine_board, x - 1, y);
		if (ret != 0)
		{
			show_board[x - 1][y] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x - 1, y);
		}
	}
	if (show_board[x - 1][y + 1] == '*' && x - 1 >= 1 && x - 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		ret = countmine(mine_board, x - 1, y + 1);
		if (ret != 0)
		{
			show_board[x - 1][y + 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x - 1, y + 1);
		}
	}
	if (show_board[x][y - 1] == '*' && x >= 1 && x <= row && y - 1 >= 1 && y - 1 <= col)
	{
		ret = countmine(mine_board, x, y - 1);
		if (ret != 0)
		{
			show_board[x][y - 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x, y - 1);
		}
	}
	if (show_board[x][y + 1] == '*' && x >= 1 && x <= row && y + 1 >= 1 && y + 1 <= col)
	{
		ret = countmine(mine_board, x, y + 1);
		if (ret != 0)
		{
			show_board[x][y + 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x - 1, y - 1);
		}
	}
	if (show_board[x + 1][y - 1] == '*' && x + 1 >= 1 && x + 1 <= row && y - 1 >= 1 && y - 1 <= col)
	{
		ret = countmine(mine_board, x + 1, y - 1);
		if (ret != 0)
		{
			show_board[x + 1][y - 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x + 1, y - 1);
		}
	}
	if (show_board[x = 1][y] == '*' && x + 1 >= 1 && x + 1 <= row && y >= 1 && y <= col)
	{
		ret = countmine(mine_board, x + 1, y);
		if (ret != 0)
		{
			show_board[x + 1][y] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x + 1, y);
		}
	}
	if (show_board[x + 1][y + 1] == '*' && x + 1 >= 1 && x + 1 <= row && y + 1 >= 1 && y + 1 <= col)
	{
		ret = countmine(mine_board, x + 1, y + 1);
		if (ret != 0)
		{
			show_board[x + 1][y + 1] = ret + '0';
		}
		else
		{
			Expand_board(mine_board, show_board, row, col, x + 1, y = 1);
		}
	}
}

int Count_mine(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	while (1)
	{
		printf("请输入的坐标->");
		int x = 0;
		int y = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine_board[x][y] != '1')
			{
				int num = 0;
				num = mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + mine_board[x][y - 1] + mine_board[x][y + 1] + mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 8 * '0';
				show_board[x][y] = num + '0';
				if (num == 0)
				{
					Expand_board(mine_board, show_board, ROW, COL, x, y);
					Print_board(show_board, row, col);
				}
				if (num != 0)
				{
					Print_board(show_board, row, col);
				}
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			printf("非法输入，请重新输入！\n");
		}
	}
}

int Judge(char show_board[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			if (show_board[i][j] != '*' && show_board[i][j] != 'P')
			{
				count++;
			}
		}
	}
	return count;
}

void Plant_flag(char show_board[ROWS][COLS],int row,int col)
{
	int z = 1;
	static int sflag = MINE;
	do
	{
		printf("请输入您想要插下小旗子的坐标->");
		int x = 0;
		int y = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show_board[x][y] == 'P')
			{
				printf("取消标记成功！\n");
				show_board[x][y] = '*';
				Print_board(show_board, row, col);
			again1:
				printf("***** 1.再次插旗子/撤去小旗子   0.不再插旗子 *****\n");
				printf("请输入->");
				scanf("%d", &z);
				if (z != 1 && z != 0)
				{
					printf("非法输入，请重新输入！\n");
					goto again1;
				}
			}
			else if (show_board[x][y] == '*')
			{
				show_board[x][y] = 'P';
				Print_board(show_board, row, col);
				sflag--;
			again:
				printf("***** 1.再次插旗子/撤去小旗子   0.不再插旗子 *****\n");
				printf("请输入->");
				scanf("%d", &z);
				if (z != 1 && z != 0)
				{
					printf("非法输入，请重新输入！\n");
					goto again;
				}
			}
			else
			{
				printf("非法输入，请重新输入！\n");
			}
		}
		else
		{
			printf("非法输入，请重新输入！\n");
		}
	} while (z);
}

int Find_mine(char mine_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	while (1)
	{
		int num = Judge(show_board, row, col);
		if (num < row * col - MINE)
		{
			printf("******* 1.插小旗子/撤去小旗子  0.扫雷 *******\n");
			int get = 0;
		again: 
			printf("请输入->");
			scanf("%d", &get);
			switch (get)
			{
			case 1:
				Plant_flag(show_board, row, col);
				break;
			case 0:
				int ret = Count_mine(mine_board, show_board, row, col);
				if (ret == -1)
				{
					return 0;
				}
				break;
			default:
				printf("非法输入，请重新输入！");
				goto again;
			}
		}
		else
		{
			return 1;
		}
	}
 }