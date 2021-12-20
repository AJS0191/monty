#include "monty.h"

int collect_data(char *filename)
{
	char str1[10];
	int number;
	int c;
	int wordcount = 0;
	stack_t **stack = NULL;
	unsigned int linecount = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(fp)) != EOF)
	{
		ungetc(c, fp);
		wordcount = 0;
		while ((c = fgetc(fp)) != '\n')
		{
			if (wordcount >= 1)
			{
				while (fgetc(fp) != '\n')
				{
					;
				}
				break;
			}
			ungetc(c, fp);
			fscanf(fp, "%s", str1);
			if (strcmp(str1, "push") == 0)
			{
				if (fscanf(fp, "%d", &number) == 1)
				{
					wordcount++;
				}
				else
					number = 606;
			}
			wordcount++;
			if (stack == NULL)
			{
				if (strcmp(str1, "push") == 0 || strcmp(str1, "pall") == 0 || strcmp(str1, "nop") == 0)
				{
					stack = stack_builder(number, 100);
				}
			}
			if (stack)
				stack[1]->n = number;
			find_op(str1, linecount, stack)(stack, linecount);
			linecount++;
			stack[1]->n = 606;
		}
	}

	free_stack(stack);
	return (0);
}
