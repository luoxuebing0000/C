#include "seqlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>

typedef unsigned int uint;

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	uint *node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	assert(capacity > 0);
	int ret = 0;
	TSeqList *tmp = NULL;
	// 申请内存
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (NULL == tmp)
	{
		ret = -1;
		printf("func SeqList_Create() err: %d\n", ret);
		return NULL;
	}
	// 初始化申请的内存
	memset(tmp, 0, sizeof(TSeqList));
	tmp->capacity = capacity;
	tmp->length = 0;

	// 根据capacity的大小分配节点的空间
	tmp->node = (uint *)malloc(sizeof(uint *)*capacity);
	if (NULL == tmp->node)
	{
		ret = -2;
		printf("func SeqList_Create() err: %d\n", ret);
		return NULL;
	}
	memset(tmp->node, 0, sizeof(uint *)*capacity);
	return tmp;
}

void SeqList_Destroy(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
		return;
	tlist = (TSeqList *)list;
	if (tlist->node != NULL)
		free(tlist->node);
	free(tlist);
	return;
}
void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
		return;
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return;
}
int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
		return -1;
	tlist = (TSeqList *)list;
	return tlist->length;
}
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
		return -1;
	tlist = (TSeqList *)list;
	return tlist->capacity;
}
int SeqList_Insert(SeqList *list, SeqListNode* node, int pos)
{
	int ret = 0;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err(list == NULL || node == NULL || pos < 0) %d\n", ret);
		return ret;
	}
	TSeqList *tlist = (TSeqList *)list;
	// 判断是不是满了
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() err(length >= capacity): %d\n", ret);
		return ret;
	}
	// 容错纠正
	if (pos >= tlist->length)
		pos = tlist->length;
	// 元素后移
	for (int i = tlist->length; i > pos; i--)
		tlist->node[i] = tlist->node[i - 1];
	tlist->node[pos] = (uint *)node;
	tlist->length++;
	return 0;
}
SeqListNode *SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Get() err(list == NULL || pos < 0): %d\n", ret);
		return NULL;
	}
		
	TSeqList *tlist = (TSeqList *)list;
	if (tlist->length == 0)
	{
		ret = -2;
		printf("func SeqList_Get() err(length): %d\n", ret);
		return NULL;
	}
	// 容错处理，大于length的默认取最后一个元素
	if (pos >= tlist->length)
		pos = tlist->length - 1;
	return (void *)tlist->node[pos];
}
SeqListNode *SeqList_Delete(SeqList* list, int pos)
{
	SeqListNode *ret = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Delete() err(list == NULL || pos < 0): -1\n");
		return ret;
	}
	TSeqList *tlist = (TSeqList *)list;

	// 容错处理，如果超过节点个数，默认删除最后一个
	if (pos >= tlist->length)
		pos = tlist->length - 1;

	ret = (SeqListNode *)tlist->node[pos]; // 保留要删除的节点内容

	for (int i = pos + 1; i < tlist->length; i++)
		tlist->node[i - 1] = tlist->node[i];

	tlist->length--;
	return ret;
}