#ifndef _ALGORITHM_SORTHELPTOOLS_H
#define _ALGORITHM_SORTHELPTOOLS_H
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include "commonTools.h"

typedef void(*sortFuncDT)(int arr[], int n);

// 随机生成int型数组，范围：[l,r]
int generatorRandomIntArray(int **arr/*out*/, int n, int l, int r)
{
	assert(n > 0 && r >= l);
	int *intArr = (int *)malloc(sizeof(int) * n);
	if (NULL == intArr)
		return -1;
	// 初始化申请的内存
	memset(intArr, 0, sizeof(int) * n);
	// 使用时间设置随机种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		intArr[i] = rand() % (r - l + 1) + l;
	*arr = intArr;
	return 0;
}

// 生成近乎有序的整形数组
int generatorNearlyOrderedArray(int **arr/*out*/, int n, int swaptimes)
{
	assert(n > 0 && swaptimes >= 0);
	// 申请内存
	int *intArr = (int *)malloc(sizeof(int)*n);
	if (NULL == intArr)
		return -1;
	// 初始化申请的内存
	memset(intArr, 0, sizeof(int)*n);

	// 使用时间作为随机种子
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		intArr[i] = i;
	for (int i = 0; i < swaptimes; i++)
	{
		int posX = rand() % n;
		int posY = rand() % n;
		swap(&intArr[posX], &intArr[posY]);
	}
	*arr = intArr;
	return 0;
}

// 判断是否有序，返回0则代表有序，-1代表无序
int isSorted(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			return -1;
	return 0;
}

// 检测排序时间
void Sort(const char *sortName, sortFuncDT sortFunc, int arr[], int n)
{
	assert(sortName != NULL && sortFunc != NULL && arr != NULL && n > 0);
	clock_t startTime, endTime;
	startTime = clock();
	sortFunc(arr, n);
	endTime = clock();
	if (isSorted(arr, n) == 0)
		printf("%s: sort success... times: %lf s\n", sortName, (double)(endTime - startTime) / CLOCKS_PER_SEC);
	else
		printf("%s: sort failed!!!\n");
}

#endif // !_ALGORITHM_SORTHELPTOOLS_H
