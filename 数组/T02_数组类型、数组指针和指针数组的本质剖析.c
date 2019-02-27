#include <stdio.h>

// 定义一个数组类型， int[5]
typedef int ArrayType21[5];

// 定义一个数组指针类型（类型是一个数组类型的指针）
typedef int(*ArrayPointType21)[5];

// 定义一个指针数组类型，指向的数组类型为int[5]，该数组存储的内容为：int *
typedef int *PointArrayType21[5];

int main21(void)
{
	ArrayType21 arr;
	ArrayPointType21 arrp;
	PointArrayType21 parr;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

	// 数组类型和数组指针类型的关系
	arrp = &arr;
	for (int i = 0; i < len; i++)
		printf("%d  ", (*arrp)[i]);
	printf("\n");

	// 指针数组类型和数组类型的关系
	for (int i = 0; i < len; i++)
		parr[i] = &arr[i];
	for (int i = 0; i < len; i++)
		printf("%d  ", *parr[i]);
	printf("\n");
	return 0;
}

