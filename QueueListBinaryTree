
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct BinaryTreeNode;

typedef struct BinaryTreeNode* QueueType;

struct QueueNode
{
	QueueType val;
	struct QueueNode* next;
};

struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

void QueueInit(struct Queue* Q);
void QueueDestroy(struct Queue* Q);
void QueuePush(struct Queue* Q, QueueType x);
void QueuePop(struct Queue* Q);
QueueType QueueFront(struct Queue* Q);
QueueType QueueBack(struct Queue* Q);
int QueueSize(struct Queue* Q);
bool QueueEmpty(struct Queue* Q);

void QueueInit(struct Queue* Q)
{
	assert(Q);
	Q->head = NULL;
	Q->tail = NULL;
}

void QueueDestroy(struct Queue* Q)
{
	assert(Q);
	while (Q->head)
	{
		struct QueueNode* Tmp = Q->head->next;
		free(Q->head);
		Q->head = Tmp;
	}
}

void QueuePush(struct Queue* Q, QueueType x)
{
	assert(Q);
	struct QueueNode* NewNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	NewNode->val = x;
	NewNode->next = NULL;
	if (Q->head == NULL)
		Q->head = Q->tail = NewNode;
	else
	{
		Q->tail->next = NewNode;
		Q->tail = NewNode;
	}
}

void QueuePop(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));

	struct QueueNode* Tmp = Q->head->next;
	free(Q->head);
	Q->head = NULL;
	Q->head = Tmp;
	if (Q->head == NULL)
		Q->tail = NULL;
}

QueueType QueueFront(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));
	return Q->head->val;
}

QueueType QueueBack(struct Queue* Q)
{
	assert(Q);
	assert(!(QueueEmpty(Q)));
	return Q->tail->val;
}

int QueueSize(struct Queue* Q)
{
	assert(Q);
	int n = 0;
	struct QueueNode* cur = Q->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

bool QueueEmpty(struct Queue* Q)
{
	assert(Q);
	return Q->head == NULL;
}

int size;

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* Left;
	struct BinaryTreeNode* Right;
	BTDataType data;
}BTNode;

void BTsize(BTNode* Root)
{
	if (Root == NULL)
	{
		return;
	}
	size++;

	BTsize(Root->Left);
	BTsize(Root->Right);
}

void BTsize2(BTNode* Root, int* size2)
{
	if (Root == NULL)
	{
		return;
	}
	*size2++;

	BTsize2(Root->Left, size2);
	BTsize2(Root->Right, size2);
}

int BTsize3(BTNode* Root)
{
	if (Root == NULL)
		return 0;
	return  1 + BTsize3(Root->Left) + BTsize3(Root->Right);
}

int BTsize4(BTNode* Root)
{
	if (Root == NULL)
		return 0;
	return  BTsize4(Root->Left) + 1 + BTsize4(Root->Right);
}

int BTsize5(BTNode* Root)
{
	if (Root == NULL)
		return 0;
	return  BTsize5(Root->Left) +  BTsize5(Root->Right) + 1;
}


void PrevBT(BTNode* Root)
{
	if (Root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", Root->data);

	PrevBT(Root->Left);
	PrevBT(Root->Right);
}

void MidBT(BTNode* Root)
{
	if (Root == NULL)
	{
		printf("NULL ");
		return;
	}
	MidBT(Root->Left);

	printf("%c ", Root->data);

	MidBT(Root->Right);
}

void BackBT(BTNode* Root)
{
	if (Root == NULL)
	{
		printf("NULL ");
		return;
	}
	BackBT(Root->Left);

	BackBT(Root->Right);

	printf("%c ", Root->data);
}

int STLeafSize(BTNode* Root)
{
	if (Root == NULL)
		return 0;
	if (Root->Left == NULL && Root->Right == NULL)
		return 1;
	return STLeafSize(Root->Left) + STLeafSize(Root->Right);
}

void QueueErgST(BTNode* Root)
{
	struct Queue Q;
	QueueInit(&Q);

	if(Root)
		QueuePush(&Q, Root);
	while (!QueueEmpty(&Q))
	{
		BTNode* Front = QueueFront(&Q);
		printf("%c ", Front->data);
		QueuePop(&Q);

		if(Front->Left)
			QueuePush(&Q, Front->Left);

		if(Front->Right)
			QueuePush(&Q, Front->Right);
	}

	QueueDestroy(&Q);
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->Left = NULL;
	A->Right = NULL;
	A->data = 'A';

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->Left = NULL;
	B->Right = NULL;
	B->data = 'B';

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->Left = NULL;
	C->Right = NULL;
	C->data = 'C';

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->Left = NULL;
	D->Right = NULL;
	D->data = 'D';

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->Left = NULL;
	E->Right = NULL;
	E->data = 'E';

	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	F->Left = NULL;
	F->Right = NULL;
	F->data = 'F';

	A->Left = B;
	A->Right = C;
	B->Left = D;
	B->Right = E;
	D->Right = F;

	PrevBT(A);
	printf("\n");
	MidBT(A);
	printf("\n");
	BackBT(A);
	printf("\n");
	
	BTsize(A);
	printf("%d %d %d ", BTsize3(A), BTsize4(A), BTsize5(A));

	printf("%d ", STLeafSize(A));

	QueueErgST(A);
}
