#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

// 双亲链表
#define MAX_TREE_SIZE 100
typedef struct _tag_BPTNode
{
	int data;
	//int *parent; // 指向双亲的指针
	int prarentPos; // 指向双亲的下标
	char LRTag; // 左右孩子标志域，0表示无左右孩子，1表示为左孩子，2表示为右孩子
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[MAX_TREE_SIZE]; // 因为节点之间是分散的，需要把节点存储到数组中
	int num_node; // 节点数目
	int root; // 根节点位置 // 注意此域存储的是父节点在数组的下标
}BPTree;

int main(void)
{
	// 创建树并初始化内存
	BPTree tree;
	memset(&tree, 0, sizeof(BPTree));

	BPTNode t1, t2, t3, t4, t5;
	// 初始化内存
	memset(&t1, 0, sizeof(BPTNode));
	memset(&t2, 0, sizeof(BPTNode));
	memset(&t3, 0, sizeof(BPTNode));
	memset(&t4, 0, sizeof(BPTNode));
	memset(&t5, 0, sizeof(BPTNode));

	// 初始化data
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	tree.nodes[0] = t1;
	tree.nodes[1] = t2;
	tree.nodes[2] = t3;
	tree.nodes[3] = t4;
	tree.nodes[4] = t5;
	tree.num_node = 5;
	tree.root = 0; // t1为树的根

	// 建立树的关系
	// t1的左孩子为t2
	tree.nodes[1].prarentPos = 0;
	tree.nodes[1].LRTag = 1;
	// t1的右孩子为t3
	tree.nodes[2].prarentPos = 0;
	tree.nodes[2].LRTag = 2;
	// t2的左孩子为t4
	tree.nodes[3].prarentPos = 1;
	tree.nodes[3].LRTag = 1;
	// t3的左孩子为t5
	tree.nodes[4].prarentPos = 2;
	tree.nodes[4].LRTag = 1;

	return 0;
}