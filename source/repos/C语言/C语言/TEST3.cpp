#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

double recursion(int n, int k)
{
	if (k < 0)
	{
		return (1.0 / n) * recursion(n, k + 1);
	}
	else if (k > 0)
	{
		return n * recursion(n, k - 1);
	}
	else
	{
		return 1.0;
	}
}

int main()
{
	int n = 0;
	int k = 0;
	printf("请输入->");
	scanf("%d%d", &n, &k);
	double ret = recursion(n, k);
	printf("%lf\n", ret);
	return 0;
}

//int DigitSum(unsigned int x)
//{
//	if (x != 0)
//	{
//		int y = x % 10;
//		return y + DigitSum(x / 10);
//	}
//	return 0;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	int a = 0;
//	printf("请输入一个非负整数->");
//	scanf("%d", &num);
//	a = DigitSum(num);
//	printf("%d\n", a);
//	return 0;
//}

//void reverse_string(char* string, int n)
//{
//	if (string < string + n - 1)
//	{
//		char* left = string;
//		char* right = string + n - 1;
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		reverse_string(string + 1, n - 2);
//	}
//}
//
//int count(char* p)
//{
//	if (*p != NULL)
//	{
//		return 1 + count(p + 1);
//	}
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	char arr[] = "abcdefg";
//	int num = count(arr);
//	reverse_string(arr, num);
//	for (i = 0; i < num; i++)
//	{
//		printf("%c\n", arr[i]);
//	}
//	return 0;
//}

//int fac(int n)
//{
//	if (n > 1)
//	{
//		return n * fac(n - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int num = 0;
//	int n = 0;
//	printf("请输入->");
//	scanf("%d", &n);
//	num = fac(n);
//	printf("%d\n", num);
//}

//int print(int x)
//{
//	if (x != 0)
//	{
//		print(x / 10);
//		printf("%d\n", x % 10);
//	}
//	return 0;
//}
//
//int main()
//{
//	int num = 0;
//	printf("请输入一个整数->");
//	scanf("%d", &num);
//	print(num);
//}

//void print(int x)
//{
//	int i = 0;
//	for (i = 1; i <= x; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			int z = i * j;
//			printf("%d*%d=%-3d", i, j, z);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int x = 0;
//	printf("请输入->");
//	scanf("%d", &x);
//	print(x);
//	return 0;
//}

//void print_prime(int x, int y)
//{
//
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d%d", &x, &y);
//	print_prime(x, y);
//	return 0;
//}

//void print_arr(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print_arr(arr, sz);
//	return 0;
//}

//int tje(int x)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		int a = x >> i;
//		if ((a | -2) == -2)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int main()
//{
//	int i = 0;
//	int num = 0;
//	printf("请输入->");
//	scanf("%d", &num);
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	for (i = 31; i > 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	return 0;
//}

//int tje(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		x = x & (x - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int z = 0;
//	int num = 0;
//	printf("请输入两个数进行比较！");
//	scanf("%d%d", &x, &y);
//	z = x ^ y;
//	num = tje(z);
//	printf("%d\n", num);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int num = 0;
//	printf("请输入->");
//	scanf("%d", &num);
//	a = tje(num);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = -5;
//	int b = a % 3;
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int x = 0;
//	int y = 0;
//	int i = 0;
//	int count = 0;
//	printf("请输入两个数来比较！");
//	scanf("%d%d", &x, &y);
//	for (i = 31; i >= 0; i--)
//	{
//		int a = x >> i;
//		int b = y >> i;
//		if (a%2 != b%2)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}

//void exchange(int arr1[], int arr2[], int sz)
//{
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//
//void print(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//
//` {
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 11,12,13,14,15,16,17,18,19,20 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	exchange(arr1, arr2, sz);
//	print(arr1, sz);
//	printf("\n");
//	print(arr2, sz);
//}

//void init(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void reverse(int arr[], int sz)
//{
//	int start = 0;
//	int end = sz - 1;
//	int tmp = 0;
//	while (start < end)
//	{
//		tmp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = tmp;
//		start++;
//		end--;
//	}
//}
//
//int main()
//{
//	int x = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, sz);
//	printf("您要初始化元素的个数，请输入->");
//	scanf("%d", &x);
//	init(arr, x);
//	printf("您要打印元素的个数，请输入->");
//	scanf("%d", &x);
//	print(arr, x);
//	return 0;
//}

//int main()
//{
//	int j = 0;
// 	int i = 0;
//	int tmp = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (sz)
//	{
//		for (i = 0; i < sz; i++)
//		{
//			if (arr[i] < arr[i + 1])
//			{
//				tmp = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//		sz--;
//	}
//	int sz1 = sizeof(arr) / sizeof(arr[0]) - 1;` 
//	for (j = 0; j <= sz1; j++)
//	{
//		printf("%d\n", arr[j]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int i = 0;
//	int* arr[3] = { &a, &b, &c };
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", arr[i]);
//		printf("%d\n", *arr);
//	}
//	printf("%d\n", **arr);
//	printf("%d\n", *arr[0]);
//	printf("%d\n", *arr[1]);
//	printf("%d\n", *arr[2]);
//	return 0;
//}

//int my_strlen(char arr1[])
//{
//	int i = 0;
//	int count = 0;
//	while (1)
//	{
//		if (arr1[i] != NULL)
//		{
//			count++;
//			i++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	return count;
//}

//int my_strlen(char arr[])
//{
//	if (arr[0] != NULL)
//	{
//		return 1 + my_strlen(&arr[0]+1);
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strlen(const char* s)
//{
//	if (*s != NULL)
//	{
//		return 1 + my_strlen(++s);
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != NULL)
//	{
//		end++;
//	}
//	return end - start;
//}
//
//int main()
//{
//	char arr[] = "abcdefg";
//	int num = my_strlen(arr);
//	printf("%d\n", num);
//	/*printf("%d\n", strlen(arr));*/
//	return 0;
//}

//int main()
//{
//	char a = 'c';
//	printf("%c\n", a);
//	printf("%d\n", strlen( & a));
//	return 0;
//}

//int my_strlen()
//{
//
//}

//int main()
//{
//	int num = 0;;
//	char arr[] = "bit";
//	printf("%d\n", strlen(arr));
//	/*num = my_strlen("abcdefg");*/
//	return 0;
//}

//int main()
//{
//	char arr[] = "bit";
//	printf("%c\n", arr[0]);
//	return 0;
//}

//int main()
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//
//	}
//	return 0;
//}


//int main()
//{
//	char a = 1;
//	printf("%u\n", sizeof(!a));
	/*int a = 0b1111;
	char b = 0b000000000111;
	printf("%d %d", a, b);*/
	//char a = 3;
	//char b = 127;
	//char c = a + b;
	//printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 12;
//	int c = 1;
//	if (a = b + 10, b = a - 5, c)
//	{
//		printf("%d\n", a);
//		printf("%d\n", b);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	for (i = 0; i < 32; i++)
//	{
//		//num = num >> 1;
//		if (1 == ((num>>i) & 1))
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//void scount()
//{
//	static int i = 9;
//	i--;
//	printf("%d", i);
//}
//
//int main()
//{
//	int j = 0;
//	for (j = 1; j <= 3; j++)
//	{
//		scount();
//	}
//	return 0;
//}

//int main()
//{
//	char a = '0';
//	char b = '1';
//	char c = a - b;
//	printf("%c", c);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//again:
//	scanf("%d", &a);
//	if (a > 5)
//	{
//		if (a > 10)
//		{
//			printf("%d", a);
//		}
//		else if (a < 10)
//		{
//			printf("请重新输入！\n");
//			goto again;
//		}
//	}
//	else
//	{
//		printf("请重新输入！\n");
//		goto again;
//	}
//	return 0;
//}


//int main()
//{
//	int a = 4;
//	int b = a >> 2;
//	printf("%d", b);
//	return 0;
//}

//void maopao_sort(int arr[], int n)
//{
//	int a = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				a = arr[j];
//				arr[j] = arr[i];
//				arr[i] = a;
//			}
//		}
//	}
//}
//
//void bubble_sort(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		int j = 0;
//		int flag = 1;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//			if (flag == 1)
//			{
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int sz = 0;
//	int num = 0;
//	int arr[] = {10,9,8,7,6,5,4,3,2,1};
//	sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for (num = 0; num < sz; num++)
//	{
//		printf("%d\n", arr[num]);
//	}
//	return 0;
//}


//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", strlen(arr));
//	return 0;
//}


//int frog(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	if (n == 2);
//	{
//		return 2;
//	}
//	if (n > 2)
//	{
//		return frog(n - 1) + frog(n - 2);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int num = 0;
//	scanf("%d", &n);
//	num = frog(n);
//	printf("一共有%d中跳法", num);
//	return 0;
//}


//int count = 0;
//
//void frog(int n)
//{
//	if (n == 0)
//	{
//		count++;
//	}
//	else if (n == 1)
//	{
//		frog(n - 1);
//	}
//	else
//	{
//		frog(n - 1);
//		frog(n - 2);
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	frog(n);
//	printf("一共有%d种跳法", count);
//	return 0;
//}


//void move(char from, char dest)
//{
//	printf("从%c -> %c\n", from, dest);
//}
//
//void hanoi(char A, char B, char C, int n)
//{
//	if (n == 1)
//	{
//		move(A, C);
//	}
//	else
//	{
//		hanoi(A, C, B, n - 1);
//		move(A, C);
//		hanoi(B, A, C, n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	char A = 'A';
//	char B = 'B';
//	char C = 'C';
//	scanf("%d", &n);
//	hanoi(A, B, C, n);
//	return 0;
//}


//int fib(int x)
//{
//	int num = 0;
//	int num1 = 1;
//	int num2 = 1;
//	int num3 = 0;
//	if (x <= 2)
//	{
//		return 1;
//	}
//	for (num = 3; num <= x; num++)
//	{
//		num3 = num1;
//		num1 = num1 + num2;
//		num2 = num3;
//	}
//	return num1;
//}
//
//int main()
//{
//	int ret = 0;
//	int a = 0;
//	scanf("%d", &a);
//	ret = fib(a);
//	printf("%d\n", ret);
//	return 0;
//}


//int fac(int x)
//{
//	if (x > 1)
//	{
//		return x * fac(x - 1);
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int a = 0;
//	int ret = 0;
//	scanf("%d", &a);
//	ret = fac(a);
//	printf("%d\n", ret);
//	return 0;
//}


//int my_str(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_str(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int a = 0;
//	char arr[] = "bit";
//	a = my_str(arr);
//	printf("%d\n", a);
//	return 0;
//}


//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d\n", x % 10);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}


//void one_by_one_print(int x)
//{
//	int a = 0;
//	int b = 0;
//	a = x % 10;
//	b = (x - a) / 10;
//	if (a == 0)
//	{
//		goto again;
//	}
//	one_by_one_print(b);
//	again: printf("%d\n", a);
//
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	one_by_one_print(num);
//	return 0;
//}


//void one_by_one_printf(int x)
//{
//	int i = 0;
//	int a = 0;
//	for (i = 1; x / i > 9; i = i * 10)
//	{
//		;
//	}
//	while (i >= 1)
//	{
//		a = x / i;
//		printf("%d\n", a);
//		x = x % i;
//		i = i / 10;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	one_by_one_printf(num);
//	return 0;
//}


//int seek(int arr[], int y, int z)
//{
//	int mid = 0;
//	int left = 0;
//	int right = z;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (y < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (y > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int sz = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	printf("请输入您要查找的数");
//	b = scanf("%d", &a);
//	c = seek(arr, a, sz);
//	if (b == 0)
//	{
//		printf("不存在");
//	}
//	else
//	{
//		printf("存在，下标为：%d", c);
//	}
//	return 0;
//}


//int is_leapy(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//	printf("请输入您的年份");
//	scanf("%d", &year);
//	if (is_leapy(year) == 1)
//	{
//		printf("%d", year);
//	}
//	return 0;
//}


//int get_prime(int x)
//{
//	int y = sqrt(x);
//	int z = 0;
//	int num = 0;
//	if (x == 1)
//	{
//		return num;
//	}
//	for (z = 2; z <= y; z++)
//	{
//		if (x % z == 0)
//		{
//			printf("不是素数\n");
//			return num;
//			break;
//		}
//	}
//	if (z == y + 1)
//	{
//		printf("是素数\n");
//		num = 1;
//			return num;
//	}
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入您的数->");
//	scanf("%d", &a);
//	b = get_prime(a);
//	if (b == 1)
//	{
//		printf("%d", a);
//	}
//	return 0;
//}

//void get_prime(int x)
//{
//	int y = sqrt(x);
//	int z = 0;
//	int num = 0;
//	if (x == 1)
//	{
//		printf("不是素数\n");
//		goto again;
//	}
//	for (z = 2; z <= y; z++)
//	{
//		if (x % z == 0)
//		{
//			printf("不是素数\n");
//			break;
//		}
//	}
//	if (z == y + 1)
//	{
//		printf("是素数\n");
//	}
//again: printf("鉴定完毕");
//}
//
//int main()
//{
//	int a = 0;
//	printf("请输入您的数->");
//	scanf("%d", &a);
//	get_prime(a);
//	return 0;
//}


//int main()
//{
//	char arr[20] = { 0 };
//	system("shoutdown - s - t 60");
//again:
//	printf("请打出“我是猪”不然你的电脑将在一分钟内关机\n");
//	scanf("%s", arr);
//	int a = strcmp(arr, "我是猪");
//	if (a == 0)
//	{
//		system("shoutdown - a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//void game()
//{
//	int b = 0;
//	int c = 0;
//	b = rand()%100 + 1;
//	while (1)
//	{
//		printf("请输入您所猜的数字");
//		scanf("%d", &c);
//		if (c > b)
//		{
//			printf("数值大了\n");
//		}
//		else if (c < b)
//		{
//			printf("数值小了\n");
//		}
//		else
//		{
//			printf("恭喜，正确！\n");
//			break;
//		}
//	}
//}
//
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int a = 0;
//	do
//	{
//		printf("*****************************\n");
//		printf("*** 1.play  **** 0.close ****\n");
//		printf("*****************************\n");
//		printf("请输入选项前的数字->");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//		}
//	} while (a);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int d = 1;
//	int x = 0;
//	int c = 0;
//		scanf("%d", &x);
//	for (a = 2; a <= x; a++)
//	{
//		c = 1;
//		for (b = 1; b <= a; b++)
//		{
//			c *= b;
//		}
//		d += c;
//	}
//	printf("%d\n", d);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			c = b * a;
//			if (b == a)
//			{
//				printf("%d*%d=%d\n", a, b, c);
//				break;
//			}
//			printf("%d*%d=%d  ", a, b, c);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int max = 0;
//	int b = 0;
//	int arr[] = { 16,21,37,42,35,69,17,8,29,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (max = 0; max < sz; max++)
//	{
//		int c = 0;
//		 b = 0;
//		for (a = 1; a < sz; a++)
//		{
//			if (c==0)
//			{
//				a = a + max;
//				c++;
//			}
//			if (arr[max] < arr[a])
//			{
//				b = arr[max];
//				arr[max] = arr[a];
//				arr[a] = b;
//			}
//		}
//		printf("%d\n", arr[max]);
//	}
//	return 0;
//}


//int main()
//{
//	int a, b, c, d, e, f, g, h, i, j;
//	printf("请输入十个整数");
//	scanf("%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
//	
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 1; b <= 9; b++)
//		{
//			if (b == 9)
//			{
//				printf("%d*%d\n", a, b);
//				break;
//			}
//			printf("%d*%d  ", a, b);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 10 == 9)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//		if (a / 10 == 9)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if ((a + 1) % 10 == 0)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//	return 0;
//}
// 
// 


//int main()
//{
//	int a = 0;
//	float b = 0.0;
//	int flag = 1;
//	for (a = 1; a <= 100; a++)
//	{
//		b += flag * 1.0 / a;
//		flag = -flag;
//	}
//	printf("%f\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	float b = 0.0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 2 == 0)
//		{
//			b -= 1.0 / a;
//		}
//		else if (a % 2 == 1)
//		{
//			b += 1.0 / a;
//		}
//	}
//	printf("%f\n", b);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 9 == 0)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int count = 0;
//	for (a = 100; a <= 200; a++)
//	{
//		for (b = 2; b <= sqrt(a); b++)
//		{
//			if (a % b == 0)
//				break;
//		}
//		if (b > sqrt(a))
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int count = 0;
//	for (a = 100; a <= 200; a++)
//	{
//		for (b = 2; b < a; b++)
//		{
//			if (a % b == 0)
//				break;
//		}
//		if (a == b)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1000; a <= 2000; a++)
//	{
//		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1000; a <= 2000; a++)
//	{
//		if (a % 4 == 0 && a % 100 != 0)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//		else if (a % 400 == 0)
//		{
//			printf("%d\n", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	scanf("%d%d", &a, &b);
//	while (a%b)
//	{
//		c = a % b;
//		d = a;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}
// 
// 
//int main()
//{
//	int a = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 3 == 0)
//		{
//			printf("%d\n", a);
//		}
//	}
//	return 0;
//}
// 
// 
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		d = a;
//		a = b;
//		b = d;
//	}
//	else if (a < c)
//	{
//		d = a;
//		a = c;
//		c = d;
//	}
//	else if(b<c)
//	{
//		d = b;
//		b = c;
//		c = b;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//int main()
//{
//	int left = 0;
//	int right = 0;
//	int x = 0;
//	int mid = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15 };
//	right = (sizeof(arr) / sizeof(arr[0])) - 1;
//	printf("请输入您想查询的数");
//	scanf("%d", &x);
//	while (left<=right)
//	{
//		mid = (right + left) / 2;
//		if (x < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (x > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("您想查询的数在数组中，下标是%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("未查询到此数");
//	}
//	return 0;
//}


//int factorial(int x)
//{
//	int a = 0;
//		int b = 1;
//	for (a = 1; a <= x; a++)
//	{
//		b *= a;
//	}
//	return b;
//}
//
//int main()
//{
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	int f = 0;
//	scanf("%d", &d);
//	for (e = 1; e<=d; e++)
//	{
//		f = factorial(e);
//		c += f;
//	}
//	printf("%d\n", c);
//	return 0;
//}



//int main()
//{
//	int a = 0;
//	int b = 1;
//	for (a = 1; a < 11; a++)
//	{
//		if (a == 1)
//		{
//			b *= a;
//			continue;
//		}
//		else if (a == 2)
//		{
//			b
//		}
//	}
//	return 0;
//}
// 
// 
//int main2()
//{
//	int a;
//	int b;
//	char password[20] = { 0 };
//	printf("请输入密码");
//	scanf("%s", password);
//	printf("请确认Y/N");
//	getchar();
//	b = getchar();
//	if (b == 'Y')
//	{
//		printf("确认成功");
//	}	
//	else if (b == 'N')
//	{
//		printf("取消确认");
//	}
//	else
//	{
//		printf("输入错误");
//	}	
//	return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (a % 2 == 1)
//		printf("奇数");
//	else
//		printf("偶数");
//	return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (a < 18)
//		printf("未成年人");
//	else if (a < 17 & a < 30)
//		printf("成年人");
//	else if (a > 29 & a < 60)
//		printf("中年人");
//	else
//			printf("老年人");
//	return 0;
//}
//struct student
//{
//	char name[20];
//	int age;
//	char sex[20];
//};
//
//int main()
//{
//	struct student s1 = { "张震", 20, "男" };
//	printf("学生姓名:%s\n", s1.name);
//	s1.age = 30;
//	strcpy(s1.name, "张振业");
//	printf("%d\n", s1.age);
//	struct student* z = &s1;
//	printf("%s\n", *z);
//	return 0;
//}
//int main() 
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short));
//	return 0;
//}
////int main()
//{
//	int a = 10;
//	int* b = &a;
//	printf("%p\n", b);
//	*b = 20;
//	printf("%d\n", a);
//	char c = 'abc';
//	char* ab = &c;
//	printf("%p\n", ab);
//	printf("%d\n", sizeof ab);
//	return 0;
//}
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d\n", a);
//	//while (a < 5)
//	//{
//	//	a++;
//	//	printf("%d\n", a);
//	//}
//}
//int main()
//{
//	int i = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[11] = { 'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,0};
//	int arr3[7] = { 1 ,2 ,3 ,4 ,5 ,'\0'};
//	int q = sizeof(arr1);
//	int p = sizeof(arr2);
//	int x = sizeof(arr3);
//	printf("%d\n", q);
//	printf("%d\n", p);
//	printf("%d\n", strlen(arr2));
//	printf("%d\n", x);
//	return 0;
//}
//int Max(int x, int y)
//{
//	if (x < y)
//		return y;
//	else
//		return x;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Max(a, b);
//	printf("%d\n", c);
//	return 0;
//}
//int main()
//{
//	char a;
//	scanf("%c", &a);
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1 ,2 , 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 };
//	printf("%d\n", sizeof arr);
//	int a = sizeof(arr) / sizeof(arr[1]);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 10; // = 指赋值      ==指判断相等
//	int b = 5; 
//	//a += b; -= ,/= ,*= ,%= ,^= ,|= ,<<= ,>>=
//	a -= b;
//	printf("%d\n", a);
//	return 0;
//}

// & | ^ 位操作符
// ^ 按位异或
//对应的二进制位相同则为 0
//对应的二进制位不同则为 1
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a ^ b;
//	printf("%d", c);
//	return 0;
//}


// | 按位或
//int main()
//{
//	int a = 6;
//	int b = 8;
//	int c = a | b;
//	printf("%d", c);
//	return 0;
//}
// 
// 
// & 按位与
//{
//	int a = 6;
//	int b = 8;
//	int c = a & b;
//	printf("%d", c);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1 ,2 ,3 ,4 ,5 , 6 , 7 , 8 , 9 , 10 };
//	int i = 0;
//	while(i<10)
//	{
//			printf("%d ", arr[i]);
//			i++;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 5 % 2;
//	printf("%d\n", i);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	int a = i << 3;
//	printf("%d\n" ,i);
//	printf("%d\n", a);
//	return 0;
//}