#include <stdlib.h> 
#include <stdio.h>
#include <memory.h>
#include "TreeStructs.h"

BiTree copyTree(BiTree root)
{
	BiNode *newLptr = NULL;
	BiNode *newRptr = NULL;
	BiNode *newNode = NULL;
	if (!root)
		return NULL;
	if (root->lchild)
		newLptr = copyTree(root->lchild);
	else
		newLptr = NULL;
	if (root->rchild)
		newRptr = copyTree(root->rchild);
	else
		newRptr = NULL;
	newNode = (BiNode *)malloc(sizeof(BiNode));
	if (newNode == NULL)
		return NULL;
	newNode->lchild = newLptr;
	newNode->rchild = newRptr;
	newNode->data = root->data;
	return newNode;
}

// 使用后序遍历释放创建树申请的内存
void freeTree(BiTree root)
{
	if (!root)
		return;
	freeTree(root->lchild);
	freeTree(root->rchild);
	free(root);
}

void preOrder31(BiTree root)
{
	if (!root)
		return;
	printf("%d ", root->data);
	preOrder31(root->lchild);
	preOrder31(root->rchild);
}

int main(void)
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

	// 拷贝树
	BiTree newTree = copyTree(&t1);

	// 通过先序遍历检测是否拷贝成功
	preOrder31(&t1);
	printf("\n");
	preOrder31(newTree);
	printf("\n");

	// 释放树的内存
	freeTree(newTree);

	return 0;
}