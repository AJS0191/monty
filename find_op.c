void (find_op(char *possible_op))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if(strcmp(possible_op,instructions[i].opcode) == 0)
		{
			instructions[i].f;
		}
	}
}
