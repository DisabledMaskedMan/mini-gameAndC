class My_String
{
private:
	char* str;
public:
	My_String();
	My_String(const char* str1);
	~My_String();
	int Find_Max_Str(My_String& str1, int* num);
};

int My_String::Find_Max_Str(My_String& str1, int* num)
{
	int length1 = strlen(str);
	int length2 = strlen(str1.str);
	int (*arr)[20] = new int[length1][20];

	int index1 = -1;
	int index2 = -1;

	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			if (str[i] == str1.str[j])
			{
				if (i == 0 || j == 0)
					arr[i][j] = 0;
				else
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
					if (arr[i][j] > *num)
					{
						*num = arr[i][j];
						index1 = i;
						index2 = j;
					}
				}
			}
			else
				arr[i][j] = 0;
		}
	}
	if ((index1 - *num) == 0 || (index2 - *num) == 0)
	{
		(*num)++;
		return index1;
	}
	return index1;
}

My_String::My_String()
{
	str = new char;
	str[0] = '\0';
}

My_String::My_String(const char* str1)
{
	str = new char[strlen(str1) + 1];
	strcpy(str, str1);
}

My_String::~My_String()
{
	delete[] str;
	std::cout << "delete OK" << std::endl;
}

int main()
{
	My_String str1 = { "aacbgfefgh" };
	My_String str2 = { "bbcbgfjl" };
	int num = 0;
	int index = str1.Find_Max_Str(str2, &num);
	std::cout << "index = " << index << "	" << "num = " << num << std::endl;
}
