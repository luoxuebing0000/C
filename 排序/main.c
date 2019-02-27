#include "SortHelpTools.h"
#include "commonSortFuncs.h"

int main(void)
{
	int *arr = NULL;
	int n = 10000, l = 0, r = 100;
	generatorRandomIntArray(&arr, n, l, r);
	Sort("—°‘Ò≈≈–Ú", QuickSort, arr, n);
	return 0;
}