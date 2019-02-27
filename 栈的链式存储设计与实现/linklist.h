#ifndef _DATA_STRUCTURE_LINKLIST_H_
#define _DATA_STRUCTURE_LINKLIST_H_

/*
	优点：
		1. 无需一次性定制链表的容量
		2. 插入和删除操作无需移动数据元素

	缺点：
		1. 数据元素必须保存后继元素的位置信息
		2. 获取指定数据的元素操作需要循序访问之前的元素
*/

typedef void LinkList;
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

LinkList *LinkList_Create();
void LinkList_Destroy(LinkList *list);
void LinkList_Clear(LinkList *list);
int LinkList_Length(LinkList *list);
int LinkList_Insert(LinkList *list, LinkListNode *node,int pos);
LinkListNode* LinkList_Get(LinkList *list, int pos);
LinkListNode* LinkList_Delete(LinkList *list, int pos);



#endif // !_DATA_STRUCTURE_LINKLIST_H_