#include "monty.h"

/**
 * op_push - adds node to top of stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	
	stack_t *newNode;
	stack_t *head = *stack;
	int n = stack[1]->n;

	if (n == 606)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = head;
	if (line_number == 1)
		newNode->prev = NULL;
	newNode->next = NULL;
	head = newNode;
	stack[0] = head;
}
