#include "monty.h"
/**
 * op_pall - prints all stack elements
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (stack)
	{
		tmp = (*stack);
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}
}


/**
 * op_pint - prints top stack element
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * op_pop - deletes top element from stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->prev)
	{
		tmp = (*stack);
		(*stack) = tmp->prev;
		free(tmp);
	}
	else
	{
		(*stack) = NULL;
		free((*stack));
	}
}


/**
 * op_swap - swaps the data of the first two nodes of stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int a;
	int b;
	int elements = 0;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	while (tmp != NULL)
	{
		elements++;
		tmp = tmp->prev;

	}
	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	a = (*stack)->n;
	tmp = tmp->prev;
	b = tmp->n;

	(*stack)->n = b;
	tmp->n = a;
}


/**
 * op_add - adds data of first two nodes together
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int a;
	stack_t *tmp;
	int elements = 0;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);
	while (tmp != NULL)
	{
		elements++;
		tmp = tmp->prev;
	}
	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack);

	(*stack) = tmp->prev;
	a = tmp->n;
	(*stack)->n = a + (*stack)->n;
	free(tmp);
}
