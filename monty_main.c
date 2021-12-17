#include "monty.h"

/**
 * main - takes monty file as input and creates and modifies stack from file
 * @argc: argument count
 * @argv: file name
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	collect_data(argv[1]);
	return (0);

}
