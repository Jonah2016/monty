#include "monty.h"
/**
 * stack_freer - frees a doubly linked list
 * @head: head of the stack
 */
void stack_freer(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

