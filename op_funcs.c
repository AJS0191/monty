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

		printf("Trying to print with pall\n");
        if (stack || (*stack)->next)
        {
                tmp = (*stack)->next;
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
        printf("%d\n", (*stack)->next->n);
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

        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }

		if ((*stack)->next->prev)
		{

			tmp = (*stack)->next;
			printf("tmp:%d\n", tmp->n);
			(*stack)->next = tmp->prev;
			printf("stack->next:%d\n", (*stack)->next->n);
			free(tmp);
		}
		else
		{
			(*stack)->next = NULL;
			free((*stack)->next);

		}
		printf("popped the node\n");
}


/**
 * op_swap - swaps the data of the first two nodes of stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;
        int a;
        int b;
        int elements = 0;


	while (tmp != NULL)
    {
		printf("tmp: %d\n", tmp->n);
		elements++;
		tmp = tmp->prev;

    }
        if (elements < 2)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;
        a = (*stack)->next->n;
        tmp = tmp->prev;
        b = tmp->n;

        (*stack)->next->n = b;
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
        stack_t *tmp = (*stack)->next;

        int elements = 0;

		printf("tmp: %d\n", tmp->n);

        while (tmp != NULL)
        {
                elements++;
                tmp = tmp->prev;
        }
        if (elements < 2)
	{
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;

		(*stack)->next = tmp->prev;
		a = tmp->n;
		(*stack)->next->n = a + (*stack)->next->n;
		free(tmp);

}
