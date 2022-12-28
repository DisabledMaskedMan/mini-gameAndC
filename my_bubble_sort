#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* p1, char* p2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

void bubble_sort(void* base, int sz, int width, int (*compare)(const void*, const void*))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1, const void* e2)
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

struct stu
{
	char name[20];
	int age;
};

int cmp_struct_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	float arr1[10] = { 1.9, 1.3, 3.1, 4.4, 9.9, 0.9, 2.2, 3.1, 4.4, 5.0 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	struct stu s[3] = { {"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10} };
	int sz2 = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz2, sizeof(s[0]), cmp_struct_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f\n", arr1[i]);
	}
	return 0;
}
