#include "circlelist.h"
#include <stdlib.h>
#include <memory.h>

typedef struct _tag_CircleList
{
	CircleListNode header; // 头节点
	CircleListNode *slider; // 游标
	int length;
}TCircleList;

CircleList *CircleList_Create()
{
	TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret == NULL)
		return ret;
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}
void CircleList_Destroy(CircleList *list)
{
	if (list == NULL)
		return;
	free(list);
	return;
}
void CircleList_Clear(CircleList *list)
{
	if (list == NULL)
		return;
	TCircleList *tlist = (TCircleList *)list;
	tlist->header.next = NULL;
	tlist->length = 0;
	tlist->slider = NULL;
	return;
}
int CircleList_Length(CircleList *list)
{
	if (list == NULL)
		return -1;
	TCircleList *tlist = (TCircleList *)list;
	return tlist->length;
}
int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
		return -1;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &tlist->header;
	for (int i = 0; i < pos && current->next != NULL; i++)
		current = current->next;
	node->next = current->next;
	current->next = node;

	// 若是第一次插入
	if (tlist->length == 0)
		tlist->slider = node;
	tlist->length++;

	// 若头插法 current仍然指向头部(原因：跳0步，没有跳走)
	if (current == (CircleListNode *)tlist)
	{
		// 获取最后一个元素
		CircleListNode *last = CircleList_Get(tlist, tlist->length - 1);
		last->next = current->next;
	}

	return 0;
}
CircleListNode* CircleList_Get(CircleList *list, int pos)
{
	CircleListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode* current = &tlist->header;
	for (int i = 0; i < pos; i++)
		current = current->next;
	ret = current->next;
	return ret;
}
CircleListNode* CircleList_Delete(CircleList *list, int pos)
{
	CircleListNode* ret = NULL;
	if (list == NULL || pos < 0)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &tlist->header;
	CircleListNode *last = NULL;
	for (int i = 0; i < pos; i++)
		current = current->next;
	// 若删除第一个元素(头节点)
	if (current = &tlist->header)
		last = (CircleListNode *)CircleList_Get(tlist, tlist->length - 1);
	ret = current->next;
	current->next = ret->next;
	
	tlist->length--;
	// 判断链表是否为空
	if (last != NULL)
	{
		tlist->header.next = ret->next;
		last->next = ret->next;
	}

	// 若删除的元素为游标所指的元素
	if (tlist->slider == ret)
	{
		tlist->slider = ret->next;
	}

	// 若删除元素后，链表长度为0
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return ret;
}

// 直接指定删除链表中的某个数据元素
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode *node)
{
	CircleListNode *ret = NULL;
	if (list == NULL || node == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode* current = &tlist->header;
	for (int i = 0; i < tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			// 如果ret找到，根据i去删除
			CircleList_Delete(tlist, i);
			break;
		}
		current = current->next;
	}
	return ret;
}

// 将游标重置指向链表中的第一个数据元素
CircleListNode* CircleList_Reset(CircleList *list)
{
	CircleListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	tlist->slider = tlist->header.next;
	ret = tlist->slider;
	return ret;
}

// 获取当前游标指向的数据元素
CircleListNode* CircleList_Current(CircleList *list)
{
	if (list == NULL)
		return NULL;
	TCircleList *tlist = (TCircleList *)list;
	return tlist->slider;
}

// 将游标移动指向到链表中的下一个数据元素
CircleListNode* CircleList_Next(CircleList* list)
{
	CircleListNode* ret = NULL;
	if (list == NULL)
		return ret;
	TCircleList *tlist = (TCircleList *)list;
	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}

