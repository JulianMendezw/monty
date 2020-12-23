#include "monty.h"

/**
 * _free_all_varx - A function that frees all variables.
 */

void _free_all_varx(void)
{
	stack_t *current = NULL;

	if (varx.buffer)
		free(varx.buffer);

	while (varx.head)
		current = varx.head,
		varx.head = varx.head->next,
		free(current);

	fclose(varx.fd);
}

/**
 * _validate_data - A function that validate if the data is correct
 * @line_number:  Is the line number where the instruction appears
 *
 * Return: Data will be set in the stack.
 */

char *_validate_data(unsigned int line_number)
{
	int i = 0;
	char *data = NULL;

	data = strtok(NULL, " ");

	if (!data)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	if (data[0] == '-')
		i++;

	for (; data[i]; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			fprintf(stderr, "L%u: usage: push integer\n", line_number),
			_free_all_varx(),
			exit(EXIT_FAILURE);
	}
	return (data);
}
