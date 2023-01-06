#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Initcontact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

int Find_name( const struct Contact* ps)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入姓名:>");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp((ps->data[i]).name, name))
		{
			break;
		}
	}
	if (i == ps->size)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

void ADD_CONTACT(struct Contact* ps)
{
	if (MAX == ps->size)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", (ps->data[ps->size]).name);
		printf("请输入性别:>");
		scanf("%s", (ps->data[ps->size]).sex);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size]).age);
		printf("请输入地址:>");
		scanf("%s", (ps->data[ps->size].addr));
		printf("请输入电话:>");
		scanf("%s", (ps->data[ps->size].tele));
		printf("添加成功\n");
		ps->size++;
	}
}

void DELETE_CONTACT(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("通讯录已空\n");
	}
	else
	{
		int pos = Find_name(ps);
		if (-1 == pos)
		{
			printf("查找不到该联系人\n");
		}
		else
		{
			int i = 0;
			for (i = pos; i < ps->size - 1; i++)
			{
				ps->data[i] = ps->data[i + 1];
			}
			ps->size--;
			printf("删除成功\n");
		}
	}
}

void MODIFY_CONTACT(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("通讯录为空");
	}
	else
	{
		int pos = Find_name(ps);
		if (-1 == pos)
		{
			printf("查找不到该联系人\n");
		}
		else
		{
			printf("请输入姓名:>");
			scanf("%s", (ps->data[pos]).name);
			printf("请输入性别:>");
			scanf("%s", (ps->data[pos]).sex);
			printf("请输入年龄:>");
			scanf("%d", &(ps->data[pos]).age);
			printf("请输入地址:>");
			scanf("%s", (ps->data[pos].addr));
			printf("请输入电话:>");
			scanf("%s", (ps->data[pos].tele));
			printf("修改成功\n");
		}
	}
}

void SHOW_CONTACT(const struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-30s%-12s\n", "姓名", "性别", "年龄", "地址", "电话");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s", (ps->data[i]).name);
			printf("%-5s", (ps->data[i]).sex);
			printf("%-5d", (ps->data[i]).age);
			printf("%-30s", (ps->data[i]).addr);
			printf("%-12s\n", (ps->data[i]).tele);
		}
	}
}

void SEARCH_CONTACT(struct Contact* ps)
{
	int pos = Find_name(ps);
	if (-1 == pos)
	{
		printf("查找不到该联系人\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-30s%-12s\n", "姓名", "性别", "年龄", "地址", "电话");
		printf("%-20s", (ps->data[pos]).name);
		printf("%-5s", (ps->data[pos]).sex);
		printf("%-5d", (ps->data[pos]).age);
		printf("%-30s", (ps->data[pos]).addr);
		printf("%-12s\n", (ps->data[pos]).tele);
	}
}

void meun2()
{
	printf("***********************************\n");
	printf("******** 1.姓名     2.年龄 ********\n");
	printf("******** 3.退出            ********\n");
	printf("***********************************\n");
}

void name_sort(struct Contact* ps)
{
	int j = 0;
	for (j = 0; j < ps->size - 1; j++)
	{
		int i = 0;
		for (i = 0; i < ps->size - 1 - j; i++)
		{
			if (1 == strcmp((ps->data[i]).name, (ps->data[i + 1].name)))
			{
				struct Userinf tmp = ps->data[i];
				ps->data[i] = ps->data[i + 1];
				ps->data[i + 1] = tmp;
			}
		}
	}
}

void age_sort(struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if ((ps->data[j]).age > (ps->data[j + 1]).age)
			{
				struct Userinf tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
}

void SORT_CONTACT(struct Contact* ps)
{
	meun2();
	int input = 0;
	printf("通过哪种方式排序？请输入:>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		name_sort(ps);
		break;
	case 2:
		age_sort(ps);
		break;
	case 0:
		printf("退出排序");
		break;
	default:
		printf("输入错误");
		break;
	}
}