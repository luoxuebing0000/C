#ifndef _DATA_STRUCTURE_LINKSTACK_H_
#define _DATA_STRUCTURE_LINKSTACK_H_

typedef void LinkStack;
typedef void* PLinkStack;

PLinkStack LinkStack_Create();
void LinkStack_Destroy(PLinkStack stack);
void LinkStack_Clear(PLinkStack stack);
int LinkStack_Push(PLinkStack stack, void *item);
void* LinkStack_Pop(PLinkStack stack);
void* LinkStack_Top(PLinkStack stack);
int LinkStack_Size(PLinkStack stack);

#endif // !_DATA_STRUCTURE_LINKSTACK_H_
