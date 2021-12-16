#include "monty.h"

/**
 * op_push - adds node to top of stack
 * @stack - the stack
 * @line_number: linenumber
 * Return: none
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *head = stack[0];
	int n = (*stack)->n;

	if (n == '\0' || isdigit(n) == 0)
	{
		fprintf(stderr, "%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = head;
	head = newNode;
}
