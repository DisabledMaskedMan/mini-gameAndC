#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void QueueInit(struct Queue* Q)
{
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
		Q->head = NULL;
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

int QueueSize(struct Queue* Q);
bool QueueEmpty(struct Queue* Q)
{
	assert(Q);
	return Q->head == NULL;
}