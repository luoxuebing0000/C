#include "seqlist.h"
#include <stdlib.h>

typedef struct _Teacher {
	int age;
	char name[64];
}Teacher;

int main(void)
{
	int ret = 0;
	SeqList *list = NULL;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err: ret = %d\n", ret);
		return ret;
	}
	// 采用头插法插入元素
	ret = SeqList_Insert(list, (SeqListNode *)&t1, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t3, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t4, 0);
	ret = SeqList_Insert(list, (SeqListNode *)&t5, 0);

	// 打印存储信息
	printf("length: %d\n", SeqList_Length(list));
	printf("capacity: %d\n", SeqList_Capacity(list));

	// 遍历
	for (int i = 0; i < SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			printf("func SeqList_Get() err: ret = %d\n", ret);
			// 存在内存泄漏隐患
			SeqList_Destroy(list);
			return ret;
		}
		printf("tmp->age: %d\n", tmp->age);
	}
	// 删除链表中的节点
	while (SeqList_Length(list) > 0)
		SeqList_Delete(list, 0);

	SeqList_Destroy(list);
	return 0;
}