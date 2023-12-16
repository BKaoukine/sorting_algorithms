#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *next_node;

/* Check if the list or the list head is NULL */
if (list == NULL || *list == NULL)
return;

/* Iterate through the list starting from the second node */
for (current = (*list)->next; current != NULL; current = next_node)
{
next_node = current->next;

/* Compare and swap elements to maintain sorted order */
while (current->prev != NULL && current->n < current->prev->n)
{
/* Adjust pointers to perform the swap */
current->prev->next = current->next;

if (current->next != NULL)
current->next->prev = current->prev;

current->next = current->prev;
current->prev = current->prev->prev;

if (current->prev != NULL)
current->prev->next = current;
else
*list = current;

current->next->prev = current;

/* Print the list after each swap */
print_list(*list);
}
}
}
