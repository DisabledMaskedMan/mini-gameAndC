#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void LOAD_CONTACT(struct Contact* ps)
{
	struct Userinf tmp = { 0 };
	FILE* fp = fopen("contact.txt", "rb");
	if (fp == NULL)
	{
		printf("LOAD_CONTACT: %s\n", strerror(errno));
		return;
	}
	else
	{
		while (fread(&tmp, sizeof(struct Userinf), 1, fp))
		{
			struct Userinf* ptr = (struct Userinf*)realloc(ps->data, (ps->capacity + 1) * sizeof(struct Userinf));
			if (ptr != NULL)
			{
				ps->data = ptr;
				ps->data[ps->size] = tmp;
				ps->capacity++;
				ps->size++;
			}
		}
		fclose(fp);
		fp = NULL;
	}
}
void Initcontact(struct Contact* ps)
{
	struct Userinf* ptr = (struct Userinf*)malloc(INITIAL * sizeof(struct Userinf));
	if (ptr != NULL)
	{
		ps->data = ptr;
		ps->capacity = INITIAL;
		ps->size = 0;
	}
	else
	{
		printf("�����ڴ治�㣬ͨѶ¼����ʧ��");
		return;
	}
	LOAD_CONTACT(ps);
}

int Find_name( const struct Contact* ps)
{
	char name[NAME_MAX] = { 0 };
	printf("����������:>");
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
	if (ps->capacity == ps->size)
	{
		struct Userinf* ptr = (struct Userinf*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct Userinf));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
	if (ps->capacity != ps->size)
	{
		printf("����������:>");
		scanf("%s", (ps->data[ps->size]).name);
		printf("�������Ա�:>");
		scanf("%s", (ps->data[ps->size]).sex);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size]).age);
		printf("�������ַ:>");
		scanf("%s", (ps->data[ps->size].addr));
		printf("������绰:>");
		scanf("%s", (ps->data[ps->size].tele));
		printf("��ӳɹ�\n");
		ps->size++;
	}
}

void DELETE_CONTACT(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼�ѿ�\n");
	}
	else
	{
		int pos = Find_name(ps);
		if (-1 == pos)
		{
			printf("���Ҳ�������ϵ��\n");
		}
		else
		{
			int i = 0;
			for (i = pos; i < ps->size - 1; i++)
			{
				ps->data[i] = ps->data[i + 1];
			}
			ps->size--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void MODIFY_CONTACT(struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ��");
	}
	else
	{
		int pos = Find_name(ps);
		if (-1 == pos)
		{
			printf("���Ҳ�������ϵ��\n");
		}
		else
		{
			printf("����������:>");
			scanf("%s", (ps->data[pos]).name);
			printf("�������Ա�:>");
			scanf("%s", (ps->data[pos]).sex);
			printf("����������:>");
			scanf("%d", &(ps->data[pos]).age);
			printf("�������ַ:>");
			scanf("%s", (ps->data[pos].addr));
			printf("������绰:>");
			scanf("%s", (ps->data[pos].tele));
			printf("�޸ĳɹ�\n");
		}
	}
}

void SHOW_CONTACT(const struct Contact* ps)
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-30s%-12s\n", "����", "�Ա�", "����", "��ַ", "�绰");
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
		printf("���Ҳ�������ϵ��\n");
	}
	else
	{
		printf("%-20s%-5s%-5s%-30s%-12s\n", "����", "�Ա�", "����", "��ַ", "�绰");
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
	printf("******** 1.����     2.���� ********\n");
	printf("******** 0.�˳�            ********\n");
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
	printf("ͨ�����ַ�ʽ����������:>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		name_sort(ps);
		printf("����ɹ�");
		break;
	case 2:
		age_sort(ps);
		printf("����ɹ�");
		break;
	case 0:
		printf("�˳�����");
		break;
	default:
		printf("�������");
		break;
	}
}

void SAVE_CONTACT(struct Contact* ps)
{
	FILE *fp = fopen("contact.txt", "wb");
	if (fp == NULL)
	{
		printf("SAVE_CONTACT: %s\n", strerror(errno));
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct Userinf), 1, fp);
		}
		fclose(fp);
		fp = NULL;
	}
}

void DESTROY_CONTACT(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
