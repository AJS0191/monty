#include "monty.h"

int collect_data(char *filename)
{
	FILE *fp;
	char str1[10];
	int number;
	int c;
	int wordcount = 0;
	stack_t **stack = NULL;
	unsigned int linecount = 1;

	printf("FILENAME:%s\n", filename);
	fp = fopen (filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n", filename);
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
					;
				linecount++;
				break;
			}
			ungetc(c, fp);
			fscanf(fp, "%s", str1);
			if (strcmp(str1, "push"))
			{
				fscanf(fp, "%d", &number);
				wordcount++;
			}
			wordcount++;
			if (stack == NULL)
			{
				if (strcmp(str1, "push") == 0)
				{
					stack = stack_builder(number, 100);
					break;
				}
				else
				{
					fprintf(stderr, "Error: malloc failed\n");
					exit(EXIT_FAILURE);
				}
			}
			find_op(str1)(stack, linecount);
		}

	}
	fclose(fp);
	return (0);
}
