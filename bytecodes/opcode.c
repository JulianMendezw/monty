#include "monty.h"
#include <stdlib.h>

/**
 * add_dnodeint - A function that add a new node to the beginning list.
 *@head: Pointer to the first node.
 *@n: Data to set in a new node.
 * Return: A new node.
 */

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;
	char *data = NULL;
	int n = 0;

	node = malloc(sizeof(stack_t));
	if (!node)
		fprintf(stderr, "Error: malloc failed\n"),
		exit(EXIT_FAILURE);

	if (*head)
		(*head)->prev = node;
	data = strtok(NULL, " ");

	//add error handling
	n = atoi(data);

	node->n = n;
	node->next = *head;
	node->prev = NULL;
	*head = node;
	printf("->Node added %d\n", line_number);
}
