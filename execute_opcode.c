#include "monty.h"
/**
 * execute - executes the opcode func
 * @stack: head of linked list - stack
 * @counter: line_counter
 * @file: pntr to the monty file
 * @content: content of line
 * Return: no return value
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t instructn[] = {
		{"push", fn_push}, {"pall", fn_pall}, {"pint", fn_pint}, {"pop", fn_pop},
		{"swap", fn_swap}, {"add", fn_add}, {"nop", fn_nop},
		{"sub", fn_sub}, {"div", fn_div}, {"mul", fn_mul},
		{"mod", fn_mod}, {"pchar", fn_pchar}, {"pstr", fn_pstr}, {"rotl", fn_rotl},
		{"rotr", fn_rotr}, {"queue", fn_queue}, {"stack", fn_stack}, {NULL, NULL}};
	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (instructn[i].opcode && opc)
	{
		if (strcmp(opc, instructn[i].opcode) == 0)
		{
			instructn[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opc && instructn[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opc);
		fclose(file);
		free(content);
		stack_freer(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
