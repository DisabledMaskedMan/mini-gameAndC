#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void printMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);

		printf("\n");
	}
	printf("\n");
}

void creatMatrix(int** matrix, int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 1000;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	if (*matrixColSize <= 1)
		return;

	int tmp = sqrt(matrixSize);
	int n = *matrixColSize;
	int offset = (tmp - n) / 2;
	int x = 0;
	int y = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		x = n - i - 1;
		y = n - 1;		//例(4, 4)
		
		tmp1 = matrix[y + offset][n - x - 1 + offset];	//(4, 0)
		matrix[y + offset][n - x - 1 + offset] = matrix[x + offset][y + offset];
		//printf("%d\n", matrix[x + offset][y + offset]);

		tmp3 = x;
		x = y;
		y = n - tmp3 - 1;	//(4, 0)
		tmp2 = matrix[y + offset][n - x - 1 + offset];	//(0, 0)
		matrix[y + offset][n - x - 1 + offset] = tmp1;
		//printf("%d\n", tmp1);

		tmp3 = x;
		x = y;
		y = n - tmp3 - 1;	//(0,0)
		tmp1 = matrix[y + offset][n - x - 1 + offset];	//(0, 4)
		//printf("%d\n", tmp1);
		matrix[y + offset][n - x - 1 + offset] = tmp2;
		//printf("%d\n", tmp2);
		
		tmp3 = x;
		x = y;
		y = n - tmp3 - 1;	//(0, 4)
		matrix[y + offset][n - x - 1 + offset] = tmp1;	//(4, 4)
		//printf("%d\n", tmp1);
		//(4, 4)
	}

	//return;
	*matrixColSize = *matrixColSize - 2;
	rotate(matrix, matrixSize, matrixColSize);
}

int main()
{
	int n = 7;
	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
	}
	//int arr[5][5] = { 0 };		//问题出现在将arr数组作为参数传递给creatMatrix函数时。这是因为arr是一个具有固定大小的二维数组，而creatMatrix函数期望一个指向指针的指针。
	//int n = 5;
	creatMatrix(arr, n);
	printMatrix(arr, n);

	int tmp = n;
	rotate(arr, n*n, &tmp);
	printMatrix(arr, n);

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	arr = NULL;
	return 0;
}
