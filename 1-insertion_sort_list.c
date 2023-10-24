#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;
	next = current->next;
	while (next)
	{
		prev = current;
		current = next;
		next = next->next;
		while (prev && prev->n > current->n)
		{
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			if (current->next)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			print_list(*list);
			prev = current->prev;
		}
	}
}
