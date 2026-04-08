#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * partition - Swaps boxes.
 *
 * @array: The array.
 * @size: Size of the array.
 * @low: The lowest idx.
 * @high: The highest idx.
 *
 * Return: Nothing.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], count = low - 1, j, tmp;
	(void)size;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			count++;
			tmp = array[count];
			array[count] = array[j];
			array[j] = tmp;
			if (count != j)
				print_array(array, size);
		}
	}
	tmp = array[count + 1];
	array[count + 1] = array[high];
	array[high] = tmp;
	if (count + 1 != high)
		print_array(array, size);
	return (count + 1);
}
/**
 * quick_sort_recursion - Sorts an array using recursion.
 *
 * @array: The array.
 * @size: Size of the array.
 * @low: The lowest idx.
 * @high: The highest idx.
 *
 * Return: Nothing.
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low >= high)
		return;

	pivot_idx = partition(array, size, low, high);

	quick_sort_recursion(array, size, low, pivot_idx - 1);
	quick_sort_recursion(array, size, pivot_idx + 1, high);
}
/**
 * quick_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
