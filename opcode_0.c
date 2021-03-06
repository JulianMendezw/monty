#include "monty.h"

/**
 * _push - A function that add a new node to the beginning of a list.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL, *tmp = varx.head;
	int n = 0;
	char *data = NULL;
	(void)head;

	data = _validate_data(line_number);

	node = malloc(sizeof(stack_t));
	if (!node)
		fprintf(stderr, "Error: malloc failed\n"), _free_all_varx(),
		exit(EXIT_FAILURE);

	if (varx.head)
		(varx.head)->prev = node;
	n = atoi(data);

	if (varx.queue == 0)
	{
		node->n = n;
		node->next = varx.head;
		node->prev = NULL;
		varx.head = node;
	}
	else
	{
		node->n = n;
		node->next = NULL;

		if (!varx.head)
			varx.head = node, node->prev = NULL;
		else
		{
			while (tmp->next)
				tmp = tmp->next;

			tmp->next = node;
			node->prev = tmp;
		}
	}
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
		printf("%i\n", tmp->n), tmp = tmp->next;
}

/**
 * _pint - A function that prints the first of the list.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears.
 */

void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = varx.head;
	(void)head;

	if (!tmp)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}

/**
 * _pop - A function that delete the first node of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears.
 */

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

		*head = (*head)->next;

		if (tmp->next)
			tmp->next->prev = NULL;

		free(tmp);
}

/**
 * _swap - A function that swaps the top two elements of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _swap(stack_t **head, unsigned int line_number)
{
	int tmp = 0;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
