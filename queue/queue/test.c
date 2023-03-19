#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void text()
{
	struct Queue Q;
	QueueType x = 0;
	QueueInit(&Q);

	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);

	x = QueueBack(&Q);
	printf("%d ", x);
	x = QueueFront(&Q);
	printf("%d ", x);

	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);

	x = QueueBack(&Q);
	printf("%d ", x);
	x = QueueFront(&Q);
	printf("%d ", x);

	QueueDestroy(&Q);
}

int main()
{
	text();
}
