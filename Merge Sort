#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void TextBubbleSort()
{
	int a[10] = { 3, 7, 1, 4, 2, 6, 9, 8, 0, 5 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void MergeSort(int* a, int left, int right, int* tmp)
{
	/*assert(a == NULL);
	assert(tmp == NULL);*/

	if (left >= right)
		return;

	int Mid = (left + right) >> 1;
	MergeSort(a, left, Mid, tmp);
	MergeSort(a, Mid + 1, right, tmp);

	int Start1 = left;
	int End1 = Mid;
	int Start2 = Mid + 1;
	int End2 = right;
	int i = left;
	while (Start1 <= End1 && Start2 <= End2)
	{
		tmp[i++] = a[Start1] >= a[Start2] ? a[Start2++] : a[Start1++];
	}
	while (Start1 <= End1)
	{
		tmp[i++] = a[Start1];
		Start1++;
	}
	while (Start2 <= End2)
	{
		tmp[i++] = a[Start2];
		Start2++;
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void TextMergeSort()
{
	int a[10] = { 3, 7, 1, 4, 2, 6, 9, 8, 0, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	int* tmp = (int*)malloc(sizeof(int) * n);
	MergeSort(a, 0, n - 1, tmp);
	Print(a, n);
	free(tmp);
}
