#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts a ddoubly linked list in ascending order.
 *
 * @list: The list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *check, *tmp, *swap;

	if (!list)
		return;

	check = *list;
	check = check->next;

	while (check)
	{
		tmp = check->next;
		while (check->prev && check->prev->n > check->n)
		{
			swap = check->prev;
			swap->next = check->next;
			check->next = swap;
			check->prev = swap->prev;
			swap->prev = check;
			if (swap->next)
				swap->next->prev = swap;
			if (check->prev)
				check->prev->next = check;
			else
				*list = check;
			print_list(*list);
		}
		check = tmp;
	}
}
