#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

// 二叉链表示法
typedef struct _tag_BiNode {
	int data;
	struct _tag_BiNode *lchild, *rchild;
}BiNode,*BiTree;

int main11(void)
{
	BiNode t1, t2, t3, t4, t5;
	// 初始化内存
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	// 初始化data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	// 建立树的关系
	// t1的左孩子为t2
	t1.lchild = &t2;
	// t1的右孩子为t3
	t1.rchild = &t3;
	// t2的左孩子为t4
	t2.lchild = &t4;
	// t3的左孩子为t5
	t3.lchild = &t5;

	return 0;
}
