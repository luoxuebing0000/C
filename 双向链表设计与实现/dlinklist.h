#ifndef _DATA_STRUCTURE_DOUBLELINKLIST_H
#define _DATA_STRUCTURE_DOUBLELINKLIST_H

/*
	优点：
		1. 双向链表在单链表的基础上增加了指向前驱的指针
		2. 功能上双向链表可以完全取代单链表的使用
		3. 双向链表的Next、Pre和Current操作可以高效的遍历链表中的所有元素
	缺点：
		1. 代码复杂

*/

typedef void DLinkList;
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

DLinkList *DLinkList_Create();
void DLinkList_Destroy(DLinkList *list);
void DLinkList_Clear(DLinkList *list);
int DLinkList_Length(DLinkList *list);
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);
DLinkListNode* DLinkList_Get(DLinkList *list, int pos);
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node);

// 将游标重置指向链表的第一个数据元素
DLinkListNode* DLinkList_Reset(DLinkList *list);

// 获取当前游标指向的数据元素
DLinkListNode* DLinkList_Current(DLinkList *list);
// 将游标移动指向到链表中的下一个数据元素
DLinkListNode* DLinkList_Next(DLinkList* list);

// 将游标移动指向到链表的上一个数据元素
DLinkListNode* DLinkList_Pre(DLinkList* list);

#endif // !_DATA_STRUCTURE_DOUBLELINKLIST_H
