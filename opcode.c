#include "monty.h"

/**
 * _push - A function that add a new node to the beginning of a list.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;
	char *data = NULL;
	int n = 0, i = 0;
	(void)head;

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

	node = malloc(sizeof(stack_t));
	if (!node)
		fprintf(stderr, "Error: malloc failed\n"),
		_free_all_varx(),
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
 * _pall - A function that frees a stack_t list.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears.
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = varx.head;
	(void)head;
	(void)line_number;

	while (tmp)
		printf("%d\n", tmp->n), tmp = tmp->next;
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
