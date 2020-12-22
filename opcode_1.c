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
 * _sub - A function subtracts the top element of the stack from the second
 * top element of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */


void _sub(stack_t **head, unsigned int line_number)
{
	int div = 0;
	stack_t *tmp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	div = (*head)->next->n - (*head)->n;

	*head = (*head)->next;
	(*head)->n = div;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 * _div - A function divides the second top element of the stack by the to
 * element of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */


void _div(stack_t **head, unsigned int line_number)
{
	int div = 0;
	stack_t *tmp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	div = (*head)->next->n / (*head)->n;

	*head = (*head)->next;
	(*head)->n = div;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 * _mul - A function multiplies the second top element of the stack with
 * the top element of the stack.
 * @head: Pointer to the first node.
 * @line_number: Is the line number where the instruction appears
 */

void _mul(stack_t **head, unsigned int line_number)
{
	int mul = 0;
	stack_t *tmp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		_free_all_varx();
		exit(EXIT_FAILURE);
	}

	mul = (*head)->next->n * (*head)->n;

	*head = (*head)->next;
	(*head)->n = mul;
	(*head)->prev = NULL;

	free(tmp);
}
