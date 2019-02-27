#include <stdlib.h>
#include <stdio.h>
#include "linkstack.h"

int main(void)
{
	PLinkStack stack = LinkStack_Create();
	int arr[50];
	if (stack == NULL)
		return -1;

	// 压栈
	for (int i = 0; i < 50; i++)
	{
		arr[i] = i + 1;
		LinkStack_Push(stack, &arr[i]);
	}

	// 打印栈的长度信息
	printf("stack length: %d\n", LinkStack_Size(stack));
	printf("stack top item: %d\n", *((int *)LinkStack_Top(stack)));

	// 出栈
	printf("pop stack item: ");
	while (LinkStack_Size(stack) > 0)
	{
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("%d  ", tmp);
	}
	printf("\n");
	LinkStack_Destroy(stack);
	return 0;
}