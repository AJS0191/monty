/**
 * pall - prints all stack elements
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pint - prints top stack element
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void pint(stack_t **stack, unsigned int line_number)
{
	printf("%d", (*stack)->n);
}


/**
 * pop - deletes top element from stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->prev = NULL;
}


/**
 * swap - swaps the data of the first two nodes of stack
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int a;
	int b;

	a = (*stack)->n;
	tmp = tmp->next;
	b = tmp->n;

	(*stack)->n = b;
	tmp->n = a;
}


/**
 * add - adds data of first two nodes together
 * @stack: the stack
 * @line_number: linenumber
 * Return: none
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b, sum;
	stack_t *tmp = *stack;

	tmp = tmp->next;

	a = (*stack)->n;
	b = (*tmp)->n;
	sum = a + b;

	tmp->n = sum;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
