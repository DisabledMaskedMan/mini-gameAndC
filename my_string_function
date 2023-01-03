#include <stdio.h>
#include <string.h>
#include <assert.h>

char* strncpyn(char* str1, char* str2, size_t count)
{
	char* start = str1;
	while (count && (*str1++ = *str2++))
	{
		count--;
	}
	if (count)
	{
		while (--count)
		{
			*str1 = '\0';
		}
	}
	return start;
}

char* my_strncpy(char* str1, char* str2, size_t n)
{
	assert(str1 && str2);
	char* p = str1;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (*str2 != NULL)
		{
			*str1 = *str2;
			str1++;
			str2++;
		}
		else
		{
			*str1 = '\0';
		}
	}
	return p;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "hello";
	int n = 6;
	my_strncpy(arr1, arr2, n);
	printf("%s\n", arr1);
}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

int main()
{
	const char* str1 = "abcdef";
	const char* str2 = "ab";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* p = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return p;
}

char* my_strncat(char* str1, const char* str2, size_t count)
{
	char* start = str1;
	while (*str1)
		str1++;
	while (count--)
		if (!(*str1++ = *str2++))
			return start;
	*str1 = '\0';
	return start;
}

int main()
{
	char arr1[30] = "abcdefg\0xxxxxxxx";
	char arr2[] = "bit";
	int n = 2;
	my_strncat(arr1, arr2, n);
	printf("%s\n", arr1);
	return 0;
}

int main()
{
	FILE* fp = fopen("test.txt", "r");
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("打开成功！");
	}
	return 0;
}

const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	if (*str2 == '\0')
	{
		return str1;
	}
	const char* end = str2;
	while (*end)
	{
		end++;
	}
	int num = end - str2;
	while (*str1)
	{
		int count = 0;
		int i = 0;
		for (i = 0; i < num; i++)
		{
			if (*(str1 + i) == *(str2 + i))
			{
				if (*(str1 + i) == '\0')
				{
					return NULL;
				}
				count++;
			}
		}
		if (count == num)
		{
			return str1;
		} 
		str1++;
	}
	return NULL;
}

int main()
{
	const char* arr1 = "abcbbbcghj";
	const char* arr2 = "bbc";
	const char* ret = my_strstr(arr1, arr2);
	if (ret == NULL)
	{
		printf("找不到");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}

int my_strncmp(const char* str1, const char* str2, size_t count)
{
	while ((*str1++ == *str2++) && (--count));
	str1--;
	str2--;
	return *str1 - *str2;
}

int main()
{
	int n = 5;
	const char* arr1 = "abcdef";
	const char* arr2 = "abqwer";
	int ret = my_strncmp(arr1, arr2, n);
	printf("%d\n", ret);
	return 0;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	if (src > dest)
	{
		char* start = (char*)dest;
		const char* end = (const char*)src;
		while (num)
		{
			*start++ = *end++;
			num--;
		}
		return dest;
	}
	else
	{
		char* start = (char*)dest + num - 1;
		const char* end = (const char*)src + num - 1;
		while (num)
		{
			*start-- = *end--;
			num--;
		}
		return dest;
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr1[5] = { 0 };
	int arr2[] = { 1,2,3,4,5 };
	my_memmove(arr + 2, arr, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
