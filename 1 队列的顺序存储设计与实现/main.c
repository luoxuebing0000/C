#include <stdlib.h>
#include <stdio.h>
#include "seqqueue.h"

int main(void)
{
	int ret = 0;
	int arr[10];
	PSeqQueue queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL)
		return -1;
	// 入队列
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i + 1;
		ret = SeqQueue_Append(queue, &arr[i]);
	}

	// 打印队列的属性
	printf("queue len: %d\n", SeqQueue_Length(queue));
	printf("queue capacity: %d\n", SeqQueue_Length(queue));
	printf("head element: %d\n", *((int *)SeqQueue_Header(queue)));

	// 出队列
	while (SeqQueue_Length(queue) > 0)
	{
		int tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp: %d\n", tmp);
	}

	SeqQueue_Destroy(queue);
	return 0;
}