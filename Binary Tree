#include <stdio.h>
#include <stdlib.h>

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

	A->Left = B;
	A->Right = C;
	B->Left = D;
	B->Right = E;

	PrevBT(A);
	printf("\n");
	MidBT(A);
	printf("\n");
	BackBT(A);
	printf("\n");
	
	BTsize(A);
	printf("%d %d %d", BTsize3(A), BTsize4(A), BTsize5(A));
}
