#include "monty.h"

/**
 * find_op - matches the correct op_function
 * @possible_op: word passed in from file
 * @line_number: the line number
 * @stack: the stack
 * Return: the correctly paired function
 */
void (*find_op(char *possible_op, unsigned int line_number, stack_t **stack))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
	};
	int i;

	for (i = 0; i < 7; i++)
	{
		if (strcmp(possible_op, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}
	op_not_found(possible_op, line_number, stack);

	return (NULL);
}
