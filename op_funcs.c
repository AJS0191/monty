void push(int n)
{
	stack_t *newNode;
	stack_t *head;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;
	newNode->prev = NULL;
	newNode->next = head;
	head = new;
	return (newNode);
}

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
void pint(stack_t **stack, unsigned int line_number)
{
	printf("%d", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	(*stack)->prev = NULL;
}
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
