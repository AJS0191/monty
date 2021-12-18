#include "monty.h"

/**
 * stack_builder - builds the stack
 * @value: value
 * @max_lines: max lines
 * Return: stack
 */
stack_t **stack_builder(int value, int max_lines)
{
	stack_t **stack = malloc(sizeof(stack_t *) * max_lines);
	stack_t *head = NULL;
	stack_t *valueHold = NULL;
	(void) max_lines;
	(void) value;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}


	valueHold = malloc(sizeof(stack_t));

	if (valueHold == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	stack[0] = head;
	stack[2] = head;
	valueHold->prev = NULL;
	valueHold->next = NULL;
	valueHold->n = value;
	stack[1] = valueHold;
	return (stack);
}
