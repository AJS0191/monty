/**
 * push - adds node to top of stack
 * @stack - the stack
 * @line_number: linenumber
 * @n: data to be added to top of stack
 * Return: none
*/
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
