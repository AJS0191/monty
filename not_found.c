#include "monty.h"
/**
 * op_not_found - displays error when no op found
 *
 * @possible_op: the op passed
 * @line_number: number of lines
 *
 * Return: void
 **/

void op_not_found(char *possible_op, unsigned int line_number, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, possible_op);
	free_stack(stack);
	exit(EXIT_FAILURE);
	
}
