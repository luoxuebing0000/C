#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode
{
	LinkListNode node;
	void* item;
}TLinkStackNode;

PLinkStack LinkStack_Create()
{
	return LinkList_Create();
}
void LinkStack_Destroy(PLinkStack stack)
{
	LinkStack_Clear(stack);
	return;
}
void LinkStack_Clear(PLinkStack stack)
{
	if (stack == NULL)
		return;
	while (LinkList_Length(stack) > 0)
	{
		// 释放节点的内存
		LinkStack_Pop(stack);
	}
	return;
}
int LinkStack_Push(PLinkStack stack, void *item)
{
	TLinkStackNode *node = NULL;
	node = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (node == NULL)
		return -1;
	memset(node, 0, sizeof(TLinkStackNode));
	node->item = item;
	int ret = LinkList_Insert(stack,(LinkListNode*)node,0);
	if (ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		if (node != NULL)
			free(node);
		return ret;
	}
	return ret;
}
void* LinkStack_Pop(PLinkStack stack)
{
	TLinkStackNode *node = NULL;
	node = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (node == NULL)
		return NULL;
	void *item = node->item;
	// 释放LinkList_Insert的时候分配的内存
	free(node);
	return item;
}
void* LinkStack_Top(PLinkStack stack)
{
	TLinkStackNode *node = NULL;
	node = (TLinkStackNode *)LinkList_Get(stack, 0);
	if (node == NULL)
		return NULL;
	return node->item;
}
int LinkStack_Size(PLinkStack stack)
{
	return LinkList_Length(stack);
}
