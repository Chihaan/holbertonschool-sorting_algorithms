#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp_idx;
	int tmp;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		tmp_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tmp)
			{
				tmp = array[j];
				tmp_idx = j;
			}
		}
		array[tmp_idx] = array[i];
		array[i] = tmp;
		if (tmp_idx != i)
			print_array(array, size);
	}
}
