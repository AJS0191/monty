#include <stdio.h>
#include <stdlib.h>

int collect_data(char *filename)
{
	FILE *fp;
	char str1[10];
	int number;
	int c;
	int wordcount = 0;
	stack_t **stack = NULL;
	int linecount = 0;

	printf("FILENAME:%s\n", filename);
	fp = fopen (filename, "r");

	/* need a way to find the total linecount  */
	while ((c = fgetc(fp)) != EOF)
	{
		ungetc(c, fp);
		wordcount = 0;
		while ((c = fgetc(fp)) != '\n')
		{
			linecount++;
			if (wordcount == 2)
			{
				while (fgetc(fp) != '\n')
					;
				break;
			}
			ungetc(c, fp);
			fscanf(fp, "%s %d", str1, &number);
			printf("This is the string: %s\n", str1);
			printf("This is the number: %d\n", number);
			wordcount++;
			wordcount++;
			if (stack == NULL)
			{
				if (strcmp(str1, "push") == 0)
				{
					stack = stack_builder(number, 100);
					break;
				}
				else
					ERROR NO STACK;
			}
			void (find_op(str1))(stack, linecount);
					}
		}

	}
	fclose(fp);
	return (0);
}
