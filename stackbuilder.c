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
	(void) max_lines;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	head = malloc(sizeof(stack_t));

	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	head->n = value;
	head->prev = NULL;
	head->next = NULL;
	stack[0] = head;

	return (stack);
}
