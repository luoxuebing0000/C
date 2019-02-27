#include "BinarySearch.h"
#include "SearchHelpTools.h"
int main(void)
{
	int n = 100, target = 20;
	int *arr = NULL;
	generatorOrderedIntArray(&arr, n);
	int ret = BinarySearch(arr, n, target);
	free(arr);
	return 0;
}