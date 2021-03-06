#include "monty.h"

/**
 * _mod - A function  computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */


void _mod(stack_t **head, unsigned int line_number)
{
	int mod = 0;
	stack_t *tmp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	mod = (*head)->next->n % (*head)->n;

	*head = (*head)->next;
	(*head)->n = mod;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 * _pchar - A function  prints the char at the top of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	putchar((*head)->n), putchar('\n');

}

/**
 * _pstr - A function  prints the string starting at the top of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void)line_number;

	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - A function  prints the string starting at the top of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */


void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int data_c = 0, i = 0;
	(void)line_number;

	if (tmp)
		data_c = tmp->n;

	for (; tmp; i++)
	{
		if (!tmp->next)
		{
			tmp->n = data_c;
			break;
		}
		else
		{
			tmp->n = tmp->next->n;
			tmp = tmp->next;
		}
	}
}

/**
 * _rotr - A function  prints the string starting at the top of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int data_c = 0;
	(void)line_number;

	while (tmp)
	{
		if (!tmp->next)
		{
			data_c = tmp->n;
			break;
		}
		tmp = tmp->next;
	}

	while (tmp)
	{
		if (!tmp->prev)
		{
			tmp->n = data_c;
			break;
		}
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
}
