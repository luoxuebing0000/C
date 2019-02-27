#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

// 三叉链表示法
typedef struct _tag_TriTNode
{
	int data;
	// 左右孩子指针
	struct _tag_TriTNode *lchild, *rchild;
	// 指向双亲的指针
	struct _tag_TriTNode *parent;
}TriTNode,*TriTree;

int main21(void)
{
	TriTNode t1, t2, t3, t4, t5;
	// 初始化内存
	memset(&t1, 0, sizeof(TriTNode));
	memset(&t2, 0, sizeof(TriTNode));
	memset(&t3, 0, sizeof(TriTNode));
	memset(&t4, 0, sizeof(TriTNode));
	memset(&t5, 0, sizeof(TriTNode));

	// 初始化data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	// 建立树的关系
	// t1的左孩子为t2
	t1.lchild = &t2;
	t2.parent = &t1;
	// t1的右孩子为t3
	t1.rchild = &t3;
	t3.parent = &t1;
	// t2的左孩子为t4
	t2.lchild = &t4;
	t4.parent = &t2;
	// t3的左孩子为t5
	t3.lchild = &t5;
	t5.parent = &t3;

	return 0;
	return 0;
}