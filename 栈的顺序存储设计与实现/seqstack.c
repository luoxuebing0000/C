#include "seqlist.h"
#include "seqstack.h"
#include <stdlib.h>

PSeqStack SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}
void SeqStack_Destroy(PSeqStack stack)
{
	SeqList_Destroy(stack);
}
void SeqStack_Clear(PSeqStack stack)
{
	SeqList_Clear(stack);
}
int SeqStack_Push(PSeqStack stack, PItem item)
{
	return SeqList_Insert(stack,(SeqListNode*)item,SeqList_Length(stack));
}
PItem SeqStack_Pop(PSeqStack stack)
{
	return SeqList_Delete(stack,SeqList_Length(stack)-1);
}
PItem SeqStack_Top(PSeqStack stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}
int SeqStack_Size(PSeqStack stack)
{
	return SeqList_Length(stack);
}
int SeqStack_Capacity(PSeqStack stack)
{
	return SeqList_Capacity(stack);
}
