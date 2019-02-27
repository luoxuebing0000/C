#ifndef _DATA_STRUCTURE_TREE_STRUCTS_H
#define _DATA_STRUCTURE_TREE_STRUCTS_H


// 二叉链表示法
typedef struct _tag_BiNode {
	int data;
	struct _tag_BiNode *lchild, *rchild;
}BiNode, *BiTree;

#endif // !_DATA_STRUCTURE_TREE_STRUCTS_H
