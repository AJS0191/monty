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
        stack_t *head = *stack;

        if (stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = head->next;
head->next = head->next->next;
        head->next->prev = head;
        free(tmp);
}


/**
 * op_swap - swaps the data of the first two nodes of stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = *stack;
        int a;
        int b;
        int elements = 0;

        while (tmp != NULL)
        {
                elements++;
                tmp = tmp->next;
        }
        if (elements < 2)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = *stack;
        a = (*stack)->n;
        tmp = tmp->next;
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
        int a, b, sum;
        stack_t *tmp = *stack;
        int elements = 0;

        while (tmp != NULL)
        {
                elements++;
                tmp = tmp->next;
        }
        if (elements < 2)
	{
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = *stack;

        tmp = tmp->next;

        a = (*stack)->n;
        b = tmp->n;
        sum = a + b;

        tmp->n = sum;
        tmp->prev = NULL;
        free(*stack);
        *stack = tmp;
}
