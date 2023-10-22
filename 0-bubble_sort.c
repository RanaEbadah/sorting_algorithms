#include "sort.h"

/**
 *swap - swap 2 elements in an array
 *@xp: first elemnt.
 *@yp: second element.
 *Return: void
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 *bubble_sort - sort an array using bubble sort
 *@array: the array to be sorted
 *@size: The array size
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
		break;
	}
}
