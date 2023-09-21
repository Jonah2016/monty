#include "monty.h"
/**
 * node_setter - add node to the stack head
 * @head: head of the stack
 * @n: new_value
 * Return: no return value
 */
void node_setter(stack_t **head, int n)
{

	stack_t *tmp_node, *aux;

	aux = *head;
	tmp_node = malloc(sizeof(stack_t));
	if (tmp_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = tmp_node;
	tmp_node->n = n;
	tmp_node->next = *head;
	tmp_node->prev = NULL;
	*head = tmp_node;
}
