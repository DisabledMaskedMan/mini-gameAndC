#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QueueType;

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


