#ifndef __ALGORITHM_SEARCHHELPTOOLS_H
#define __ALGORITHM_SEARCHHELPTOOLS_H
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

int generatorOrderedIntArray(int **arr/*out*/, int n) /*out*/
{
	int *intArr = (int *)malloc(sizeof(int)*n);
	if (NULL == intArr)
		return -1;
	memset(intArr, 0, sizeof(int)*n); // ≥ı ºªØ

	for (int i = 0; i < n; i++)
		intArr[i] = i;
	*arr = intArr;
	return 0;
}

#endif // !__ALGORITHM_SEARCHHELPTOOLS_H
