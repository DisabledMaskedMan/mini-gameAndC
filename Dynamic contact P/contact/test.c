#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void meun()
{
	printf("*******************************************\n");
	printf("********* 1.Add            2.Del **********\n");
	printf("********* 3.Modify         4.Show**********\n");
	printf("********* 5.Search         6.Sort**********\n");
	printf("********* 0.Exit                 **********\n");
	printf("*******************************************\n");

}

int main()
{
	int input = 0;
	struct Contact con;
	Initcontact(&con);
	if (con.capacity != INITIAL)
	{
		goto end;
	}
	do
	{
		meun();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			ADD_CONTACT(&con);
			break;
		case Del:
			DELETE_CONTACT(&con);
			break;
		case Modify:
			MODIFY_CONTACT(&con);
			break;
		case Show:
			SHOW_CONTACT(&con);
			break;
		case Search:
			SEARCH_CONTACT(&con);
			break;
		case Sort:
			SORT_CONTACT(&con);
			break;
		case Exit:
			DESTROY_CONTACT(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	end: return 0;
}