# store
void my_strcpy(char* dest, char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		*dest = *src;
	}
}

void my_strcpy(char* dest, char* src)
{
		while (*dest++ = *src++)
		{
			;
		}
}

void my_strcpy(char* dest, char* src)
{
	if (dest != NULL && src != NULL)
	{
		while (*dest++ = *src++)
		{
			;
		}
	}
}

#include <assert.h>
void my_strcpy(char* dest, char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}

#include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	int n = 9;
	float* pfloat = (float*)&n;
	float m = 9.0;
	int* pint = (int*)&m;
	return 0;
}

unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}

int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
		Sleep(500);
	}
	return 0;
}

int main()
{
	int a = -20;
	unsigned int b = 10;
	printf("%d\n", a + b);
	return 0;
}

int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d", a, b, c);
	return 0;
}

int main()
{
	int a = 10;
	float b = 10.0;
	int c = -10;
	int d = 0x11223344;
	int f = 1;
	char arr[] = "abcdef";
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char* p = (char*)&f;
	*p = 0;
	switch (f)
	{
	case 1:
		printf("大端");
		break;
	case 0:
		printf("小端");
		break;
	}
	return 0;
}

void test(int(**p)[5])
{
	;
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int arr3[5] = { 11,12,13,14,15 };
	int* parr[3] = { arr1, arr2, arr3 };
	printf("%d\n", **parr);
	int(*parr1[3])[5] = {&arr1, &arr2, &arr3};
	printf("%d\n", ***parr1);
	test(parr1);
	void (*p1)(int(**)[5]) = test;
	return 0;
}

void my_strcpy(char* dest, const char* src)
{
	while(*dest++ = *src++)
	{
		;
	}
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "###";
	void(*pf)(char*, const char*) = my_strcpy;
	void(*pfArr[4])(char*, const char*) = { my_strcpy };
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

int cmp_f(const void* e1, const void* e2)
{
	float num = *(float*)e1 - *(float*)e2;
	if (num > 0)
	{
		return 1;
	}
	else if (num == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int main()
{
	float arr[10] = { 1.9, 1.3, 3.1, 4.4, 9.9, 0.9, 2.2, 3.1, 4.4, 5.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_f);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f\n", arr[i]);
	}
	return 0;
}

int main()
{
	int a = 0x11223344;
	int* p = &a;
	int arr[4] = { 1,2,3,4 };
	printf("%d\n", arr[-1]);
	return 0;
}

int main()
{
	int arr[3][4] = { 0 };
	printf("%p\n", &arr[0] + 1);
	printf("%p\n", arr + 1);
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr[0]));
	printf("%d\n", sizeof(&arr[0]));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(arr[0] + 1));
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", sizeof(arr + 1));
	return 0;
}

void move(int* p, int sz)
{
	int tmp = 0;
	int left = 1;
	int right = sz - 1;
	if (sz % 2 == 0)
	{
		right = sz - 2;
		while (left < right)
		{
			tmp = *(p + left);
			*(p + left) = *(p + right);
			*(p + right) = tmp;
			right -= 2;
			left += 2;
		}
	}
	else
	{
		while (left < right)
		{
			tmp = *(p + left);
			*(p + left) = *(p + right);
			*(p + right) = tmp;
			left += 2;
			right -= 2;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}

int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	return 0;
}

int main()
{
	int x = 0;
	int y = 1;
	again: printf("请输入一个奇数:>");
	scanf("%d", &x);
	if (x % 2 != 1)
	{
		printf("输入错误，请重新输入！\n");
		goto again;
	}
	int n = (x - 1) / 2;
	while(n)
	{
		printf("%*s", n, " ");
		int i = 0;
		for (i = 0; i < y; i++)
		{
			printf("%c", '*');
		}
		printf("\n");
		n--;
		y += 2;
	}
	while (y > 0)
	{
		int i = 0;
		if (n != 0)
		{
			printf("%*s", n, " ");
		}
		for (i = 0; i < y; i++)
		{
			printf("%c", '*');
		}
		printf("\n");
		y -= 2;
		n++;
	}
	return 0;
}

int cal_digit(int x)
{
	if (x != 0)
	{
		return 1 + cal_digit(x / 10);
	}
	else
	{
		return 0;
	}
}

int fact(int x, int n)
{
	if (n != 0)
	{
		return x * fact(x, n - 1);
	}
	else
	{
		return 1;
	}
}

int main()
{
	int i = 0;
	for (i = 1; i <= 100000; i++)
	{
		int sum = 0;
		int n = cal_digit(i);
		int j = 0;
		for (j = 0; j < n; j++)
		{
			sum += fact((i / fact(10, j)) % 10, n);
		}
		if (sum == i)
		{
			printf("%d  ", sum);
		}
	}
	return 0;
}

int main()
{
	int x = 0;
	int y = 0;
	int num = 0;
	scanf("%d%d", &x, &y);
	int z = x;
	int i = 0;
	for (i = 1; i <= y; i++)
	{
		num = num + x;
		x = 10 * x + z;
	}
	printf("%d\n", num);
	return 0;
}

int func(int x, int y, int z)
{
	if (y != 0)
	{
		return x + func(10 * x + z, y - 1, z);
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);
	int ret = func(x, y, x);
	printf("%d\n", ret);
	return 0;
}

void inversion_str(char* p)
{
	assert(p);

	int count = 0;
	char* p1 = p;
	while (*p1)
	{
		if (*p1 != NULL)
		{
			count++;
		}
		p1++;
	}
	char* start = p;
	char* end = p + count - 1;
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}

}

int main()
{
	char arr[256] = {0};
	fgets(arr, 20, stdin);
	inversion_str(arr);
	printf("%s\n", arr);
	return 0;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	char arr1[] = "abcde";
	printf("%d\n", &arr[4] - &arr[0]);
	printf("%d\n", &arr1[4] - &arr1[0]);
	return 0;
}

int main()
{
	const char* p = "hello";
	const char* a[] = { "work", "at", "alibaba" };
	return 0;
}

#define MYOFFSETOF(type, x) (int)&(((type*)0)->x)

struct S
{
	char a;
	int b;
	char c;
};

int main()
{
	printf("%d\n", MYOFFSETOF(struct S, a));
	printf("%d\n", MYOFFSETOF(struct S, b));
	printf("%d\n", MYOFFSETOF(struct S, c));
	return 0;
}
