#include "monty.h"

/**
 * _push - A function that add a new node to the beginning of a list.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _push(stack_t **head, unsigned int line_number)
{
	(void)head;
	stack_t *node = NULL;
	char *data = NULL;
	int n = 0, i = 0;

	data = strtok(NULL, " ");
	if (!data)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	for (i = 0; data[i]; i++)
	{
		if (data[i] < 48 || data[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number),
			_free_all_varx(),
			exit(EXIT_FAILURE);
		}
	}

	node = malloc(sizeof(stack_t));
	if (!node)
		fprintf(stderr, "Error: malloc failed\n"),
		exit(EXIT_FAILURE);

	if (varx.head)
		(varx.head)->prev = node;

	n = atoi(data);

	node->n = n;
	node->next = varx.head;
	node->prev = NULL;
	varx.head = node;
}


/**
 * _free - A function that frees a stack_t list.
 */

void _free(void)
{
	stack_t *current = NULL;

	while (varx.head)
		current = varx.head,
		varx.head = varx.head->next,
		free(current);
}

/**
 * _free_all_varx - A function that frees all variables.
 */

void _free_all_varx(void)
{
	if (varx.buffer)
		free(varx.buffer);

	_free();
	fclose(varx.fd);
}
