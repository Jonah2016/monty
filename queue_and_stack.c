#include "monty.h"
/**
 * fn_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return value
 */
void fn_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return value
 */
void addqueue(stack_t **head, int n)
{
	stack_t *tmp_node, *aux;

	aux = *head;
	tmp_node = malloc(sizeof(stack_t));
	if (tmp_node == NULL)
	{
		printf("Error\n");
	}
	tmp_node->n = n;
	tmp_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = tmp_node;
		tmp_node->prev = NULL;
	}
	else
	{
		aux->next = tmp_node;
		tmp_node->prev = aux;
	}
}

/**
 * fn_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return value
 */
void fn_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

