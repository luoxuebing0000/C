#include <stdio.h>
#include "seqqueue.h"
#include "seqlist.h"

PSeqQueue SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}
void SeqQueue_Destroy(PSeqQueue queue)
{
	SeqList_Destroy(queue);
	return;
}
void SeqQueue_Clear(PSeqQueue queue)
{
	SeqList_Clear(queue);
	return;
}
int SeqQueue_Append(PSeqQueue queue, void *item)
{
	return SeqList_Insert(queue,item,SeqList_Length(queue));
}
void* SeqQueue_Retrieve(PSeqQueue queue)
{
	return SeqList_Delete(queue, 0);
}
void* SeqQueue_Header(PSeqQueue queue)
{
	return SeqList_Get(queue,0);
}
int SeqQueue_Length(PSeqQueue queue)
{
	return SeqList_Length(queue);
}
int SeqQueue_Capacity(PSeqQueue queue)
{
	return SeqList_Capacity(queue);
}