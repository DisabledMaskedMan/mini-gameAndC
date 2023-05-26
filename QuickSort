#include <stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Print(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int GetMidValue(int* a, int left, int right)
{
	int Mid = (left + right) >> 1;
	if (a[left] < a[Mid])
	{
		if (a[Mid] < a[right])
			return Mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[Mid] > a[right])
			return Mid;
		else if (a[right] < a[left])
			return right;
		else
			return left;
	}
}

int PartSort1(int* a, int left, int right)
{
	int MidVal = GetMidValue(a, left, right);
	Swap(&a[left], &a[MidVal]);

	int Start = left;
	int End = right;
	int Hole = Start;
	int Key = a[Hole];

	while (Start < End)
	{
		while (Start < End && a[End] >= Key)
		{
			End--;
		}
		if (Start < End)
		{
			a[Hole] = a[End];
			Hole = End;
		}

		while (Start < End && a[Start] <= Key)
		{
			Start++;
		}
		if (Start < End)
		{
			a[Hole] = a[Start];
			Hole = Start;
		}
	}
	a[Hole] = Key;
	return Hole;
}

int PartSort2(int* a, int left, int right)
{
	int MidVal = GetMidValue(a, left, right);
	Swap(&a[left], &a[MidVal]);

	int Start = left;
	int End = right;
	int Key = Start;
	while (Start < End)
	{
		while (Start < End && a[End] >= a[Key])
		{
			End--;
		}

		while (Start < End && a[Start] <= a[Key])
		{
			Start++;
		}
		Swap(&a[Start], &a[End]);
	}
	Swap(&a[Key], &a[Start]);
	return Start;
}

int PartSort3(int* a, int left, int right)
{
	int MidVal = GetMidValue(a, left, right);
	Swap(&a[left], &a[MidVal]);

	int Prev = left;
	int Cur = left + 1;
	int Key = left;

	while (Cur <= right)
	{
		if (a[Cur] < a[Key] && ++Prev != Cur)
		{
			Swap(&a[Prev], &a[Cur]);
		}
		Cur++;
	}
	Swap(&a[Prev], &a[Key]);
	return Prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//int Hole = PartSort1(a, left, right);
	//int Hole = PartSort2(a, left, right);
	int Hole = PartSort3(a, left, right);
	
	if ((Hole - left) > 10)
		QuickSort(a, left, Hole - 1);
	else
		InsertSort(a + left, Hole - left);
	if((right - Hole) > 10)
		QuickSort(a, Hole + 1, right);
	else
		InsertSort(a + Hole + 1, right - Hole);
	/*QuickSort(a, left, Hole - 1);
	QuickSort(a, Hole + 1, right);*/
}

void BubbleSort(int* a, int n)
{
	int Tmp = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < Tmp - 1; j++)
		{
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
		Tmp--;
	}
}

void Text1()
{
	int a[10] = { 3, 7, 1, 4, 2, 6, 9, 8, 0, 5 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	Text1();


}
