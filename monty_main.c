#include "monty.h"

int main(int argc, char *argv)
{
	if (argc > 1)
		ERROR;
	if (collect_data.c(argv[1]) == NULL)
		ERROR;
	collect_data(argv[1]);
	return (0);

}
