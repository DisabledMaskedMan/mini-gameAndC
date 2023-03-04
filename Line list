include<stdio.h>
include<assert.h>

struct LList
{
	int data;
	struct LList* next;
};

struct LList* plist = NULL;

void SListPopFront(struct LList** pphead)
{
	assert(*pphead != NULL);

	struct LList* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

void SListPushBack(struct LList** pphead,int x)
{
	struct LList* NewNode = (struct LList*)malloc(sizeof(struct LList));
	if (NewNode == NULL)
		return;
	NewNode->data = x;
	NewNode->next = NULL;
	struct LList* tail = *pphead;

	if ((*pphead) == NULL)
	{
		*pphead = NewNode;
		return;
	}
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = NewNode;
}

void SListPrint(struct LList** pphead)
{
	struct LList* tail = *pphead;
	if (*pphead == NULL)
		return;
	while (tail != NULL)
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}

void test1()
{
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPopFront(&plist);


	SListPrint(&plist);
}

int main()
{
	test1();
	return 0;
}

struct ListNode {
    int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* trail = head;
	struct ListNode* trail2 = NULL;
	struct ListNode* tmp = NULL;
	if (head == NULL)
		return head;
	while (trail)
	{
		if (head->val == val)
		{
			tmp = head->next;
			free(head);
			head = tmp;
			trail = head;
		}
		else
		{
			if (trail->val != val)
			{
				trail2 = trail;
				trail = trail->next;
			}
			else
			{
				trail2->next = trail->next;
				free(trail);
				trail = trail2->next;
			}
		}
	}
	return head;
}

int main()
{
	struct ListNode* plist = (struct ListNode*)malloc(sizeof(struct ListNode));
	removeElements(plist, 0);
	free(plist);
	plist == NULL;
}
