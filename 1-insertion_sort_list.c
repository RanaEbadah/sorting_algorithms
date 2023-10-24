#include "sort.h"

/**
*printNodesList -  print the double linked list
*@head: the list to be printed
*Return: void
*/
void printNodesList(listint_t *head)
{
	while (head != NULL)
	{
		printf("%d ", head->n);
		head = head->next;
	}
	printf("\n");
}

/**
*insertion_sort_list -  sorts a doubly linked list of integers
*in ascending order using the Insertion sort algorithm.
*@list: the list to be sorted
*Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *curr, *insertPtr, *nextNode;

	 if (*list == NULL || (*list)->next == NULL) {
        return;
    }

    sorted = *list;
    curr = (*list)->next;

    while (curr != NULL)
	{
        insertPtr = sorted;
        nextNode = curr->next;

        while (insertPtr->next != NULL && curr->n >= insertPtr->next->n) 
        insertPtr = insertPtr->prev;
        

        if (insertPtr == NULL)
		{
            curr->next = sorted;
            curr->prev = NULL;
            sorted->prev = curr;
            sorted = curr;
        }
		else
		{
            curr->prev->next = curr->next;
            if (curr->next != NULL)
            curr->next->prev = curr->prev;

            curr->next = insertPtr->next;
            curr->prev = insertPtr;
            if (insertPtr->next != NULL)
            insertPtr->next->prev = curr;

            insertPtr->next = curr;
        }
        curr = nextNode;
        printNodesList(sorted);
    }

    *list = sorted;
}
