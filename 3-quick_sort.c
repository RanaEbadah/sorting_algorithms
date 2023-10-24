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
int partition(int *array, int low, int high, size_t size)
{
	 int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
			print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
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
