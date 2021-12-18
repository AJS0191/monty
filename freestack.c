#include "monty.h"

void free_stack(stack_t **stack)
{
	extern FILE *fp;
	stack_t *tmp = (*stack);
	stack_t *free_hold;

	while(tmp != NULL)
	{
		free_hold = tmp;
		tmp = tmp->prev;
		free(free_hold);
	}

	if (stack[1])
		free(stack[1]);
	free(stack);
	fclose(fp);
}
