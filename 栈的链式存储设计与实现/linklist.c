#include "linklist.h"
#include <stdlib.h>
#include <memory.h>

typedef struct _tag_LinkList 
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList *LinkList_Create()
{
	TLinkList *ret = NULL;
	ret = (TLinkList *)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;
	return ret;
}
void LinkList_Destroy(LinkList *list)
{
	if (list != NULL)
		free(list);
	return;
}
void LinkList_Clear(LinkList *list)
{
	if (list == NULL)
		return;
	TLinkList *tlist = (TLinkList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	return;
}
int LinkList_Length(LinkList *list)
{
	if (list == NULL)
		return -1;
	TLinkList *tlist = (TLinkList *)list;
	return tlist->length;
}
int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
		return -1;
	TLinkList *tlist = (TLinkList *)list;
	LinkListNode *current = &tlist->header;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return 0;
}
LinkListNode* LinkList_Get(LinkList *list, int pos)
{
	if (list == NULL || pos < 0)
		return NULL;
	TLinkList *tlist = (TLinkList *)list;
	LinkListNode *current = &tlist->header;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	return current->next;
}
LinkListNode* LinkList_Delete(LinkList *list, int pos)
{
	LinkListNode *ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TLinkList *tlist = (TLinkList *)list;
	LinkListNode *current = &tlist->header;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	// 缓存要删除节点的位置
	ret = current->next;
	current->next = ret->next;
	tlist->length--;
	return ret;
}