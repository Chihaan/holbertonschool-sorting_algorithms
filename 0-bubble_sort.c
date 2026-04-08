#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			swap = 0;
			if (array[j + 1] < array[j])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
