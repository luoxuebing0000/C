#ifndef _DATA_STRUCTURE_SEQQUEUE_H_
#define _DATA_STRUCTURE_SEQQUEUE_H_

typedef void SeqQueue;
typedef void* PSeqQueue;

PSeqQueue SeqQueue_Create(int capacity);
void SeqQueue_Destroy(PSeqQueue queue);
void SeqQueue_Clear(PSeqQueue queue);
int SeqQueue_Append(PSeqQueue queue, void *item);
void* SeqQueue_Retrieve(PSeqQueue queue);
void* SeqQueue_Header(PSeqQueue queue);
int SeqQueue_Length(PSeqQueue queue);
int SeqQueue_Capacity(PSeqQueue queue);

#endif // !_DATA_STRUCTURE_SEQQUEUE_H_
