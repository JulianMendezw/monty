#include "monty.h"

/**
 * _nop - A function that do anything..
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	_free_all_varx();
	exit(EXIT_SUCCESS);
}
