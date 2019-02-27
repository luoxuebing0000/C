#include <stdlib.h>
#include <stdio.h>
#include "linkstack.h"

int isLeft(char c)
{
	int ret = 0;
	switch (c)
	{
		case '<':
		case '(':
		case '[':
		case '{':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}
int isRight(char c)
{
	int ret = 0;
	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}
int match(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}
int scanner(const char* code)
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
	while (code[i] != '\0')
	{
		if (isLeft(code[i]))
		{
			LinkStack_Push(stack, (void*)(code + i));
		}
		else if (isRight(code[i]))
		{
			char* c = (char *)LinkStack_Pop(stack);
			if (c == NULL || !match(*c, code[i]))
			{
				printf("\'%c\' does not match!\n", *c);
				ret = 0;
				break;
			}
		}
		i++;
	}
	if (LinkStack_Size(stack) == 0 && code[i] == '\0')
		printf("Successful!!!\n");
	else
		printf("Invalid...");
	return ret;
}
int main(void)
{
	const char *testStr = "()jfkldsj{jfdkls]}";
	// ≤‚ ‘
	scanner(testStr);
	return 0;
}