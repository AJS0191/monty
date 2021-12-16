#include "monty.h"

int main(int argc, char *argv)
{
	if (argc != 1)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (collect_data.c(argv[1]) == NULL)
		ERROR;
	collect_data(argv[1]);
	return (0);

}
