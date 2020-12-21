#include "monty.h"


/**
 * _get_info_data - Funtion to get the info from any file.
 */

void _get_info_data(void)
{
	size_t nbytes = 0;
	unsigned int line_number = 0;

	while (getline(&varx.buffer, &nbytes, varx.fd) != EOF && ++line_number)
	{
		if (varx.buffer)
		{
			varx.buffer[strlen(varx.buffer) - 1] = '\0';
			_get_opcode(line_number);
		}
	}
}

/**
 * _get_opcode - To get a instruction from a struct.
 *
 * @line_number: is the line number where the instruction appears.
 */

void _get_opcode(unsigned int line_number)
{

	char *opcode = NULL;
	int i = 0;

	instruction_t ops[] = {
	{"push", _push},
	{"pall", _pall},
	{NULL, NULL}
	};

	opcode = strtok(varx.buffer, " ");

	if (opcode)
	{
		for (i = 0; ops[i].opcode; i++)
			if (strcmp(ops[i].opcode, opcode) == 0)
			{
				ops[i].f(&varx.head, line_number);
				break;
			}
	}

	if (!ops[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		_free_all_varx();

		exit(EXIT_FAILURE);
	}
}

/**
 *_validate_number_arguments - To validate number of arguments passed to monty.
 *
 * @argc: Count of arguments.
 */

void _validate_number_arguments(int argc)
{
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"),
		exit(EXIT_FAILURE);
}

/**
 * _open_file - To open a file where is the info.
 *
 * @argv: Argument to get the name of file.
 *
 * Return: The number of file descriptor opened.
 */

FILE *_open_file(char **argv)
{
	varx.fd = fopen(argv[1], "r");
	if (!varx.fd)
		fprintf(stderr, "Error: Caxn't open file %s\n", argv[1]),
		exit(EXIT_FAILURE);

	return (varx.fd);
}
