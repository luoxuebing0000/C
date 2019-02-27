#include "dlinklist.h"
#include <stdio.h>

typedef struct _tag_Value
{
	DLinkListNode node;
	int v;
}TValue;

int main(void)
{
	int ret = 0;
	DLinkList *list = DLinkList_Create();
	TValue v1, v2, v3, v4, v5;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	
	// 向链表中插入元素
	ret = DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	printf("list length: %d\n", DLinkList_Length(list));

	// 遍历
	for (int i = 0; i < DLinkList_Length(list); i++)
	{
		TValue *pv = (TValue *)DLinkList_Get(list, i);
		printf("pv: %d\n", pv->v);
	}
	DLinkList_Delete(list, DLinkList_Length(list));
	DLinkList_Delete(list, 0);

	printf("after delete, list length: %d\n", DLinkList_Length(list));
	DLinkList_Destroy(list);

	return ret;
}