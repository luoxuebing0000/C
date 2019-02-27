#include <stdlib.h>
#include <stdio.h>
#include "linkqueue.h"

int main(void)
{
	int ret = 0;
	int arr[50];
	PLinkQueue queue = NULL;
	queue = LinkQueue_Create();
	if (queue == NULL)
		return -1;
	// 入队列
	for (int i = 0; i < 50; i++)
	{
		arr[i] = i + 1;
		ret = LinkQueue_Append(queue, &arr[i]);
	}

	// 打印队列的属性
	printf("queue len: %d\n", LinkQueue_Size(queue));
	printf("head element: %d\n", *((int *)LinkQueue_Header(queue)));

	// 出队列
	while (LinkQueue_Size(queue) > 0)
	{
		int tmp = *((int *)LinkQueue_Retrieve(queue));
		printf("tmp: %d\n", tmp);
	}

	LinkQueue_Destroy(queue);
	return 0;
}