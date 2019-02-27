#include <stdio.h>
// 定义一个数组类型
typedef int ArrayType11[5];

int main11(void)
{
	ArrayType11 arr;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
		arr[i] = i;
	for (int i = 0; i < len; i++)
		printf("%d  ", arr[i]);
	printf("\n");
	return 0;
}