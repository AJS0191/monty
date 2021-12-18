#include "monty.h"

void free_stack(stack_t **stack)
{
	extern FILE *fp;
	stack_t *tmp = (*stack)->next;
	stack_t *free_hold;

	while(tmp->prev != NULL)
	{
		free_hold = tmp;
		tmp = tmp->prev;
		free(free_hold);
	}
	free(tmp);
	if (stack[0])
		free(stack[0]);

	free(stack);
	fclose(fp);
}
