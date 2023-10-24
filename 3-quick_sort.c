#include "sort.h"

/**
 *swap - swap 2 elements in an array
 *@xp: first elemnt.
 *@yp: second element.
 *Return: void
 */
void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 *partition - it partition the array into 2 parts
 *@arr: the array to be partition.
 *@lb: low boundry.
 *@ub: ubber boundary.
 *@size: array size.
 *Return: int (the location)
 */
int partition(int *arr, int lb, int ub, size_t size)
{
	int pivot, start, end;

	pivot = arr[lb];
	start = lb;
	end = ub;

	while (start < end)
	{
		while (arr[start] <= pivot)
		start++;

		while (arr[end] > pivot)
		end--;

		if (start < end)
		swap(&arr[start], &arr[end]);
	}
	swap(&arr[lb], &arr[end]);
	print_array(arr, size);
	return (end);
}

/**
*quick_sort - sorts an array of integers in ascending
*order using the Quick sort algorithm
*@array: the array to be sorted
*@size: The array size
*Return: void
*/
void quick_sort(int *array, size_t size)
{
	size_t lb, ub;

	if (array == NULL || size < 2)
	return;

	lb = 0;
	ub = size - 1;

	QuickSortD(array, lb, ub, size);
}

/**
*QuickSortD - sorts an array of integers in ascending
*order using the Quick sort algorithm
*@arr: the array to be sorted
*@lb: low boundry.
*@ub: ubber boundary.
*@size: The array size
*Return: void
*/
void QuickSortD(int *arr, int lb, int ub, size_t size)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(arr, lb, ub, size);
		QuickSortD(arr, lb, loc - 1, size);
		QuickSortD(arr, loc + 1, ub, size);
	}
}
