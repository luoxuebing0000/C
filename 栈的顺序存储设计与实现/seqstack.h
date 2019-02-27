#ifndef _DATA_STRUCTURE_SEQSTACK_H_
#define _DATA_STRUCTURE_SEQSTACK_H_

typedef void SeqStack;
typedef void* PSeqStack;
typedef void* PItem;

PSeqStack SeqStack_Create(int capacity);
void SeqStack_Destroy(PSeqStack stack);
void SeqStack_Clear(PSeqStack stack);
int SeqStack_Push(PSeqStack stack, PItem item);
PItem SeqStack_Pop(PSeqStack stack);
PItem SeqStack_Top(PSeqStack stack);
int SeqStack_Size(PSeqStack stack);
int SeqStack_Capacity(PSeqStack stack);
#endif // !_DATA_STRUCTURE_SEQLIST_H_
