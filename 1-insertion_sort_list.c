#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @list_head: Pointer to head of doubly-linked list.
 * @first_node:Pointer to first node to swap.
 * @second_node: Second node to swap.
 */
void swap_nodes(listint_t **list_head, listint_t **first_node, listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*list_head = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
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
	listint_t *current_node, *sorted_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current_node = (*list)->next; current_node != NULL; current_node = next_node)
	{
		next_node = current_node->next;
		sorted_node = current_node->prev;
		while (sorted_node != NULL && current_node->n < sorted_node->n)
		{
			swap_nodes(list, &sorted_node, current_node);
			print_list((const listint_t *)*list);
		}
	}
}