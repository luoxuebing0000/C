#include <stdio.h>

void PrintArray31(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d  ", arr[i]);
	printf("\n");
}

int main31(void)
{
	int arr[5] = { 1,2,3,4,5 };
	PrintArray31((int *)arr, 5);

	int arr2d[2][3] = { {1,2,3},{4,5,6} };
	PrintArray31((int *)arr2d, 6);
	return 0;
}