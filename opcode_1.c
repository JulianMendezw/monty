#include "monty.h"

/**
 * _add - A function that do anything..
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _add(stack_t **head, unsigned int line_number)
{
	int add = 0;
	stack_t *tmp = *head;


	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	add = (*head)->n + (*head)->next->n;

	*head = (*head)->next;
	(*head)->n = add;
	(*head)->prev = NULL;

	free(tmp);

}

/**
 * _nop - A function that do anything..
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * _sub - A function that do anything..
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */


void _sub(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	printf("test");
}
