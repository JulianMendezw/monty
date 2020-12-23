#include "monty.h"

/**
 * _stack - A function that sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _stack(stack_t **head, unsigned int line_number)
{
	varx.queue = 0;
	(void)line_number;
	(void)head;
}

/**
 * _queue - A function  sets the format of the data to a queue (FIFO).
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _queue(stack_t **head, unsigned int line_number)
{
	varx.queue = 1;
	(void)line_number;
	(void)head;
}
