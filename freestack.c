#include "monty.h"

void free_stack(stack_t **stack)
{
	extern FILE *fp;
	stack_t *tmp = (*stack)->next;
	stack_t *free_hold;

	while(tmp->prev != NULL)
	{
		printf("made it to tmp%d\n", tmp->n);
		tmp = tmp->prev;
	}

	while (tmp)
	{
		free_hold = tmp;
		tmp = tmp->next;
		free(free_hold);
	}
	if (stack[0])
		free(stack[0]);
	free(stack);
	fclose(fp);
}
