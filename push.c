/**
 * op_push - adds node to top of stack
 * @n: data to be added to top of stack
 * @stack - the stack
 * @line_number: linenumber
 * Return: none
*/
void op_push(int n, int line_number)
{
	stack_t *newNode;
	stack_t *head;

	if (n == NULL || is(digit(n)) == 0)
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
	newNode->n = number;
	newNode->prev = NULL;
	newNode->next = head;
	head = new;
	return (newNode);
}
