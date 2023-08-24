#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addSN(void)
{
	struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
	l->val = 1;
	l->next = NULL;
	return l;
}

int cmpSN(struct ListNode* l1, struct ListNode* l2) {
	int num = 0;
	while (l1 != NULL && l2 != NULL)
	{
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1 == NULL)
		return 1;
	else
		return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	assert(l1 != NULL);
	assert(l2 != NULL);
	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;
	int flag = 1;
	if (cmpSN(l1, l2))
	{
		cur1 = l2;
		cur2 = l1;
		flag = 0;
	}
	int tmp = 0;
	do
	{
		tmp = cur1->val + cur2->val;
		if (tmp >= 10)
		{
			cur1->val = tmp % 10;
			if (cur1->next != NULL)
				cur1->next->val++;
			else
				cur1->next = addSN();
		}
		else
			cur1->val = tmp;
		cur1 = cur1->next;
		cur2 = cur2->next;
	} while (cur2 != NULL);

	while (cur1 != NULL && cur1->val >= 10)
	{
		cur1->val = cur1->val % 10;
		if (cur1->next == NULL)
			cur1->next = addSN();
		else
			cur1->next->val++;
		cur1 = cur1->next;
	}
	if(flag)
		return l1;
	return l2;
}

void My_printf(struct ListNode* l)
{
	while (l != NULL)
	{
		printf("%d ", l->val);
		l = l->next;
	}
	printf("\n");
}

void FreeLN(struct ListNode* l)
{
	struct ListNode* cur = NULL;
	while (l != NULL)
	{
		cur = l->next;
		free(l);
		l = cur;
	}
}

struct ListNode* Creat_LN(int num)
{
	if (num == 0)
		return NULL;
	srand(time(NULL));
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* cur = head;
	cur->val = rand() % 10;
	cur->next = NULL;
	for (int i = 0; i < num - 1; i++)
	{
		struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
		l->val = rand() % 10;
		l->next = NULL;
		cur->next = l;
		cur = cur->next;
	}
	return head;
}

int main(void)
{
	struct ListNode* l1 = Creat_LN(2);
	My_printf(l1);
	struct ListNode* l2 = Creat_LN(2);
	My_printf(l2);
	My_printf(addTwoNumbers(l1, l2));

	FreeLN(l1);
	l1 = NULL;
	FreeLN(l2);
	l2 = NULL;
	return 0;
}
