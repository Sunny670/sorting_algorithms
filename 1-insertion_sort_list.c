#include "sort.h"



/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @list_hd: Pointer to head of doubly-linked list.
 * @first_n:Pointer to first node to swap.
 * @second_n: Second node to swap.
 */
void swap_nodes(listint_t **list_hd, listint_t **first_n, listint_t *second_n)
{
	(*first_n)->next = second_n->next;
	if (second_n->next != NULL)
		second_n->next->prev = *first_n;
	second_n->prev = (*first_n)->prev;
	second_n->next = *first_n;
	if ((*first_n)->prev != NULL)
		(*first_n)->prev->next = second_n;
	else
		*list_hd = second_n;
	(*first_n)->prev = second_n;
	*first_n = second_n->prev;
}

/**
 * len_list - computes length of singly linked list
 * @head: pointer to head node of list
 *
 * Return:length of the list
 */

int len_list(listint_t *head)
{
	int len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
/**
 * insertion_sort_list - Sorts doubly linked list of integers
 *                       with the insertion sort algorithm.
 * @list: Pointer to head of a doubly-linked list.
 *
 * Description: Prints list after every swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_n, *sorted_n, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current_n = (*list)->next; current_n != NULL; current_n = next_node)
	{
		next_node = current_n->next;
		sorted_n = current_n->prev;
		while (sorted_n != NULL && current_n->n < sorted_n->n)
		{
			swap_nodes(list, &sorted_n, current_n);
			print_list((const listint_t *)*list);
		}
	}
}
