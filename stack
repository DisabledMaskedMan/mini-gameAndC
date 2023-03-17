#include <stdio.h>
#include <assert.h>


struct stack
{
	int top;
	int capacity;
	char s[];
};

struct stack* init(struct stack* ST)
{
	struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
	ST = tmp;
	ST->top = 0;
	ST->capacity = 0;
	return ST;
}

void push(struct stack** pST, char s)
{
	if ((*pST)->top == (*pST)->capacity)
	{
		(*pST)->capacity = ((*pST)->capacity == 0) ? 4 : (2 * (*pST)->capacity);
		*pST = (struct stack*)realloc(*pST, 8 + (*pST)->capacity);
	}
	((*pST)->s)[(*pST)->top] = s;
	(*pST)->top++;
}

int pop(struct stack** pST)
{
	if (0 == ((*pST)->top))
		return 0;
	(*pST)->top--;
	return 1;
}

char search(struct stack** pST)
{
	return ((*pST)->s)[(*pST)->top];
}

void destroy(struct stack* ST)
{
	free(ST);
}

bool isValid(char* s)
{
	if (*s == 0)
		return false;
	struct stack* ST = NULL;
	ST = init(ST);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			push(&ST, *s);
			s++;
		}
		else
		{
			if (0 == pop(&ST))
				return false;
			char tmp = search(&ST);
			if ((*s == ')' && tmp != '(')
				|| (*s == ']' && tmp != '[')
				|| (*s == '}' && tmp != '{'))
			{
				destroy(ST);
				ST = NULL;

				return false;
			}
			else
				s++;
		}
	}
	if (ST->top > 0)
	{
		destroy(ST);
		ST = NULL;
		return false;
	}
	destroy(ST);
	ST = NULL;
	return true;
}
