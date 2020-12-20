#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _validate_number_arguments(int argc);
FILE *_open_file(char **argv);
void _getline(FILE *fd);
void _push(stack_t **stack, unsigned int line_number);

int main (int argc, char **argv)
{
	FILE *fd = NULL;

	_validate_number_arguments(argc);

	fd = _open_file(argv);

	_getline(fd);

	return (0);
}

void _getline(FILE *fd)
{
	char *buffer = NULL;
	size_t nbytes = 0;
	unsigned int line_number= 0;
	stack_t *head = NULL;

	while (getline(&buffer, &nbytes, fd) != EOF && ++line_number)
	{
		buffer[strlen(buffer) - 1] = '\0';
		_get_opcode(buffer, line_number, &head);
	}

	fclose(fd);
	free(buffer);
}


void _get_opcode(char *buffer, unsigned int line_number, stack_t **head)
{

	char *opcode = NULL;
	int i = 0;

	instruction_t ops[] =
	{
		{"push", _push},
		{NULL, NULL}
	};

	opcode = strtok(buffer, " ");
	//data = strtok(NULL, " ");

	while (ops[i].opcode)
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(head, line_number);
			break;
		}

	if (!ops[i].opcode)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode),
		exit(EXIT_FAILURE);
}


void _validate_number_arguments(int argc)
{
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"),
		exit(EXIT_FAILURE);
}


FILE *_open_file(char **argv)
{
	FILE *fd = NULL;

	fd = fopen(argv[1], "r");
	if (!fd)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]),
		exit(EXIT_FAILURE);

	return(fd);
}
