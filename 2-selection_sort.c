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
*selection_sort - sorts an array of integers
*in ascending order using the Selection sort algorithm
*@array: the array to be sorted
*@size: The array size
*Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
		min = &array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			min = &array[j];
		}

		if (min != &array[i])
		swap(min, &array[i]);
		print_array(array, size);

	}
}
