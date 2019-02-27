#ifndef _ALGORITHM_COMMONSORTFUNCS_H_
#define _ALGORITHM_COMMONSORTFUNCS_H_
#include <stdio.h>
#include "commonTools.h"

// 冒泡排序
void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

// 选择排序
void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		swap(&arr[i], &arr[minIndex]);
	}
}

// 插入排序
void InsertionSort(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	for (int i = 1; i < n; i++)
	{
		int j = i;
		int e = arr[i];
		for (; j > 0 && arr[j-1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

// 分治
void __Merge(int arr[], int l, int mid, int r)
{
	int *aux = (int *)malloc(sizeof(int)*(r - l + 1));
	if (NULL == aux)
		abort(); // 终止
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] > aux[j - l])
		{
			arr[k] = aux[j - l];
			j++;
		}
		else
		{
			arr[k] = aux[i - l];
			i++;
		}
	}
	if(aux != NULL)
		free(aux);
}

// 范围：[l...r]
void __MergeSort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int mid = l + (r - l) / 2;
	__MergeSort(arr, l, mid);
	__MergeSort(arr, mid + 1, r);
	__Merge(arr, l, mid, r);
}

// 分治排序 自上而下
void MergeSort(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	__MergeSort(arr, 0, n - 1);
}

// 分治排序  自下而上
void MergeSortBU(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	for (int sz = 1; sz <= n; sz += sz)
		for (int i = 0; i < n - sz; i += sz + sz)
			if (arr[i+sz-1] > arr[i + sz])
				__Merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

int __partition(int arr[], int l, int r)
{
	swap(&arr[l], &arr[rand() % (r - l + 1) + l]);
	int j = l;
	int v = arr[l];
	for (int i = l; i <= r; i++)
	{
		if (arr[i] < v)
		{
			j++;
			if (j != i)
				swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[l], &arr[j]);
	return j;
}

int __partition2(int arr[], int l, int r)
{
	swap(&arr[l], &arr[rand() % (r - l + 1) + l]);
	int v = arr[l];
	int i = l + 1, j = r;
	while (1)
	{
		while (i <= r && arr[i] < v)
			i++;
		while (j > l && arr[j] > v)
			j--;
		if (i >= j)
			break;
		swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	swap(&arr[l], &arr[j]);
	return j;
}

void __QuickSort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int p = __partition2(arr, l, r);
	__QuickSort(arr, l, p - 1);
	__QuickSort(arr, p + 1, r);
}

// 快速排序
void QuickSort(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	// 以时间作为时间种子
	srand((unsigned int)time(NULL));
	__QuickSort(arr, 0, n - 1);
}


// 最大二叉堆排序
// TODO

#endif // !_ALGORITHM_COMMONSORTFUNCS_H_