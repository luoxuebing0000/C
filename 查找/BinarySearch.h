#ifndef __ALGORITHM_BINARYSEARCH_H__
#define __ALGORITHM_BINARYSEARCH_H__
#include <assert.h>

// ËÑË÷·¶Î§£º[0,n)
int BinarySearch(int arr[], int n, int target)
{
	assert(arr != NULL && n > 0);
	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

#endif // !__ALGORITHM_BINARYSEARCH_H__
