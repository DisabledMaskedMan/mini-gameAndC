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
