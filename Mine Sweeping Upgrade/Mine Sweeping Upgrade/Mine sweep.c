#define _CRT_SECURE_NO_WARNINGS 1

#include "Mine sweep.h"

void Init_board(char board[ROWS][COLS],int rows,int cols,int get)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = get;
		}
	}
}

void Print_board(char board[ROWS][COLS], int row, int col)
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

void Put_mine(char mine_board[ROWS][COLS], int row, int col,int mine)
{
	while (mine >= 1)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		mine_board[x][y] = '1';
		mine--;
	}
}

int Count_mine(char mine_board[ROWS][COLS], int x, int y)
{
	int num = 0;
	num = mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + mine_board[x][y - 1] + mine_board[x][y + 1] + mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 8 * '0';
	return num;
}

void Expand(char mine_board[ROWS][COLS],char show_board[ROWS][COLS], int x, int y, int* win)
{
	int ret = Count_mine(mine_board, x, y);
	if (ret == 0)
	{
		show_board[x][y] = ' ';
		(*win)++;
		if (show_board[x - 1][y - 1] == '*' && x - 1 >= 1 && x - 1 <= ROW && y - 1 >= 1 && y - 1 <= COL)
		{
			Expand(mine_board, show_board, x - 1, y - 1, win);
		}
		if (show_board[x - 1][y] == '*' && x - 1 >= 1 && x - 1 <= ROW && y >= 1 && y <= COL)
		{
			Expand(mine_board, show_board, x - 1, y , win);
		}
		if (show_board[x - 1][y + 1] == '*' && x - 1 >= 1 && x - 1 <= ROW && y + 1 >= 1 && y + 1 <= COL)
		{
			Expand(mine_board, show_board, x - 1, y + 1, win);
		}
		if (show_board[x][y - 1] == '*' && x >= 1 && x <= ROW && y - 1 >= 1 && y - 1 <= COL)
		{
			Expand(mine_board, show_board, x, y - 1, win);
		}
		if (show_board[x][y + 1] == '*' && x >= 1 && x <= ROW && y + 1 >= 1 && y + 1 <= COL)
		{
			Expand(mine_board, show_board, x, y + 1, win);
		}
		if (show_board[x + 1][y - 1] == '*' && x + 1 >= 1 && x + 1 <= ROW && y - 1 >= 1 && y - 1 <= COL)
		{
			Expand(mine_board, show_board, x + 1, y - 1, win);
		}
		if (show_board[x + 1][y] == '*' && x + 1 >= 1 && x + 1 <= ROW && y >= 1 && y <= COL)
		{
			Expand(mine_board, show_board, x + 1, y, win);
		}
		if (show_board[x + 1][y + 1] == '*' && x + 1 >= 1 && x + 1 <= ROW && y + 1 >= 1 && y + 1 <= COL)
		{
			Expand(mine_board, show_board, x + 1, y + 1, win);
		}
	}
	else
	{
		show_board[x][y] = ret + '0';
		(*win)++;
	}
}

void Find_mine(char mine_board[ROWS][COLS],char show_board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int input = 0;
	int mark = 0;
	int ret = 0;
	int flag = 1;
	while ((win < row * col - MINE)&&flag)
	{
		printf("******* 1.插旗子（在插了旗子的坐标上插旗子会撤销该坐标上的旗子）   0.扫雷 *******\n");
		printf("请输入->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		again:
			printf("请输入坐标->");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show_board[x][y] == 'P')
				{
					printf("旗子被撤去！\n");
					show_board[x][y] = '*';
					mark--;
					Print_board(show_board, row, col);
				}
				else
				{
					if (mark < MINE)
					{
						if (show_board[x][y] == '*');
						{
							show_board[x][y] = 'P';
							mark++;
							Print_board(show_board, row, col);
						}
					}
					else
					{
						printf("旗子已插完！\n");
						break;
					}
				}
			}
			else
			{
				printf("非法输入！请重新输入\n");
				goto again;
			}
			break;
		case 0:
		again1:
			printf("请输入坐标->");
			scanf("%d%d", &x, &y);
			ret = Count_mine(mine_board, x, y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show_board[x][y] != '*' && show_board[x][y] != 'P')
				{
					printf("该坐标已被排查，请重新输入！");
					goto again1;
				}
				else
				{
					if (mine_board[x][y] == '1')
					{
						flag = 0;
					}
					else
					{
						Expand(mine_board, show_board, x, y, &win);
						Print_board(show_board, row, col);
					}
				}
			}
			else
			{
				printf("非法输入！请重新输入！");
				goto again1;
			}
			break;
		default:
			printf("非法输入！请重新输入！");
		}
	}
	if (win == row * col - MINE)
	{
		printf("恭喜您！扫雷成功！");
	}
	else
	{
		printf("踩到了雷，游戏结束！");
		Print_board(mine_board, ROW, COL);
	}
}