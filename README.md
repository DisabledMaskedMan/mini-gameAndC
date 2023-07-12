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

void my_strcpy(char* dest, char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
}


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

void my_strcpy(char* dest, const char* src)
{
	while(*dest++ = *src++)
	{
		;
	}
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


#define MYOFFSETOF(type, x) (int)&(((type*)0)->x)

int add()
{
	return 2;
}

int (*s_add(int(*p)()))()
{
	return p;
}

