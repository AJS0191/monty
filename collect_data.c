#include "monty.h"

int collect_data(char *filename)
{
	extern FILE *fp;
	char str1[10];
	int number;
	int c;
	int wordcount = 0;
	int push = 0;
	stack_t **stack = NULL;
	unsigned int linecount = 0;
	int nop;

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
			nop = 0;
			printf("nop: %d\n", nop);
			if (wordcount >= 1)
			{
				while (fgetc(fp) != '\n')
				{
					;
				}
				break;
			}
				linecount++;
				ungetc(c, fp);
				fscanf(fp, "%s", str1);
				if (strcmp(str1, "push") == 0)
				{
					fscanf(fp, "%d", &number);
					wordcount++;
					push = 1;
				}
				wordcount++;
				if (stack == NULL)
				{
					push = 0;
					if (strcmp(str1, "push") == 0)
					{
						stack = stack_builder(number, 100);
					}
					else if (strcmp(str1, "nop") == 0)
					{
						nop = 1;
						printf("nop = %d\n", nop);
					}
					else
					{
						fprintf(stderr, "Error: malloc failed\n");
						exit(EXIT_FAILURE);
					}
				}
				if (nop == 1)
				{
					wordcount--;
					break;
				}
				else
				{
					if (push == 1)
						(*stack)->n = number;
					find_op(str1)(stack, linecount);
					(*stack)->n = 606;
					push = 0;
				}
		}
	}

	free_stack(stack);
return (0);
}
