#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkQueueNode {
	LinkListNode node;
	void *item;
}LinkQueueNode;

PLinkQueue LinkQueue_Create()
{
	return LinkList_Create();
}
void LinkQueue_Destroy(PLinkQueue queue)
{
	LinkQueue_Clear(queue);
	return;
}
void LinkQueue_Clear(PLinkQueue queue)
{
	if (queue == NULL)
		return;
	while (LinkList_Length(queue) > 0)
		LinkQueue_Retrieve(queue);
	return;
}
int LinkQueue_Append(PLinkQueue queue, void *item)
{
	int ret = 0;
	if (queue == NULL || item == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Append() err: %d\n", ret);
		return ret;
	}
	LinkQueueNode *node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (node == NULL)
	{
		ret = -2;
		printf("malloc memory err: %d\n", ret);
		return ret;
	}
	// 初始化申请的内存
	memset(node, 0, sizeof(LinkQueueNode));
	node->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)node, 0);
	return ret;
}
void* LinkQueue_Header(PLinkQueue queue)
{
	LinkQueueNode *ret = NULL;
	if (queue == NULL)
	{
		printf("func LinkQueue_Header(queue == NULL) err.\n");
		return ret;
	}
	ret = (LinkQueueNode*)LinkList_Get(queue, LinkList_Length(queue) - 1);
	return ret->item;
}
void* LinkQueue_Retrieve(PLinkQueue queue)
{
	LinkQueueNode *tmp = NULL;
	void* ret = NULL;
	if (queue == NULL)
	{
		printf("func LinkQueue_Header(queue == NULL) err.\n");
		return ret;
	}
	tmp = (LinkQueueNode*)LinkList_Delete(queue, LinkList_Length(queue) - 1);
	ret = tmp->item;
	free(tmp);
	return ret;
}
int LinkQueue_Size(PLinkQueue queue)
{
	return LinkList_Length(queue);
}