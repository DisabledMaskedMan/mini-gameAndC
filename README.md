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
