#include <stdio.h>

void Print(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* b, int n, int x)
{
	int Parent = x;
	int Child = 2 * Parent + 1;
	while (Child < n)
	{
		if (Child + 1 < n && b[Child + 1] > b[Child])
		{
			Child++;
		}

		if (b[Child] > b[Parent])
		{
			swap(&b[Child], &b[Parent]);
			Parent = Child;
			Child = 2 * Parent + 1;
		}

		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	int Child = n - 1;
	int Parent = (Child - 1) / 2;
	while (Parent >= 0)
	{
		AdjustDown(a, n, Parent);
		Parent--;
	}

	while (n > 1)
	{
		int end = n - 1;
		swap(&a[n - 1], &a[0]);
		n--;
		AdjustDown(a, n, 0);
	}
	
}

int main()
{
	int b[] = { 27,15,19,18,28,34,65,49,25,37 };
	AdjustDown(b, sizeof(b) / sizeof(b[0]), 0);
	Print(b, sizeof(b) / sizeof(b[0]));
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
