#include "monty.h"

stack_t **stack_builder(int value, int max_lines);
{
	stack_t **stack = malloc(sizeof(stack_t *) * maxlines);
	stack_t *head = NULL;
	if (stack == NULL)
		MALLOC ERROR;

	head = malloc(sizeof(stack_t));

	if (head == NULL)
		MALLOC ERROR;

	head->n = value;
	head->prev = NULL;
	head->next = NULL;
	stack[0] = head;

	return(stack[0]);
}
