#include <stdlib.h>
#include <stdio.h>
#include "linkstack.h"

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int priority(char c)
{
	int ret = 0;
	if ((c == '+') || (c == '-'))
		ret = 1;
	else if ((c == '*') || (c == '/'))
		ret = 2;
	return ret;
}

void output(char c)
{
	if (c != '\0')
		printf("%c", c);
}

int transform(const char *exp)
{
	int ret = 0;
	PLinkStack stack = LinkStack_Create();
	if (stack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Create() err: %d\n", ret);
		return ret;
	}
	int i = 0;
	while (exp[i] != '\0')
	{
		if (isNumber(exp[i]))
		{
			output(exp[i]);
		}
		else if (isOperator(exp[i]))
		{
			while (priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)))
				output((char)((int)LinkStack_Pop(stack)));
			LinkStack_Push(stack, (void*)(int)exp[i]);
		}
		else if (isLeft(exp[i]))
		{
			LinkStack_Push(stack, (void*)(int)exp[i]);
		}
		else if (isRight(exp[i]))
		{
			//char c = '\0';
			while (!isLeft((char)(int)LinkStack_Top(stack)))
			{
				output((char)(int)LinkStack_Pop(stack));
			}
			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}
		i++;
	}

	while ((LinkStack_Size(stack) > 0) && (exp[i] == '\0'))
	{
		output((char)(int)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
	return ret;
}

int main11(void)
{
	transform("8+(3-1)*5+(30+32)*40");
	printf("\n");
	return 0;
}