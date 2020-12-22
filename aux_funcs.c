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
