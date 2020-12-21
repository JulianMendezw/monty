#include "monty.h"

/**
 * main - Interpreter for opcodes from a file <.m>.
 * @argc: Count of arguments.
 * @argv: Arguments from promt.
 *
 * Return:0 on succes.
 */


int main(int argc, char **argv)
{
	varx.fd = 0;
	varx.buffer = NULL;
	varx.head = NULL;

	_validate_number_arguments(argc);

	varx.fd = _open_file(argv);

	_getline();

	return (0);
}

/**
 * _getline - Funtion to get the info from any file.
 */

void _getline(void)
{
	size_t nbytes = 0;
	unsigned int line_number = 0;

	while (getline(&varx.buffer, &nbytes, varx.fd) != EOF && ++line_number)
	{
		if (varx.buffer)
		{
			varx.buffer[strlen(varx.buffer) - 1] = '\0';
			_get_opcode(line_number);
			printf("im done with getline %d\n", line_number);
		}
	}

	printf("-> im freeding when program its ok \n");
	_free_all_varx();
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

	instruction_t ops[] =	{
							{"push", _push},
							{NULL, NULL}
							};

	opcode = strtok(varx.buffer, " ");
	printf("opcode: %s\n", opcode);

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
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]),
		exit(EXIT_FAILURE);

	return (varx.fd);
}