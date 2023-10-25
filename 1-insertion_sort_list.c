#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @h: head pointer
 * @node1: pointer to first node
 * @node2: pointer to second node
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
	node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
	(*node1)->prev->next = node2;

	else
	*h = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *iteration, *insertNode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (iteration = (*list)->next; iteration != NULL; iteration = temp)
	{
		temp = iteration->next;
		insertNode = iteration->prev;

		while (insertNode != NULL && (iteration->n < insertNode->n))
		{
			swap_nodes(list, &insertNode, iteration);
			print_list((const listint_t *)*list);
		}
	}
}
