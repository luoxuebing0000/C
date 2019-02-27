#ifndef _DATA_STRUCTURE_LINKQUEUE_H_
#define _DATA_STRUCTURE_LINKQUEUE_H_
typedef void LinkQueue;
typedef void* PLinkQueue;

PLinkQueue LinkQueue_Create();
void LinkQueue_Destroy(PLinkQueue queue);
void LinkQueue_Clear(PLinkQueue queue);
int LinkQueue_Append(PLinkQueue queue, void *item);
void* LinkQueue_Header(PLinkQueue queue);
void* LinkQueue_Retrieve(PLinkQueue queue);
int LinkQueue_Size(PLinkQueue queue);
#endif // !_DATA_STRUCTURE_LINKQUEUE_H_
