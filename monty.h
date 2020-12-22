#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct variables_s - All the variables that need to be free.
 * @fd: File descriptor.
 * @buffer: Pointer to the buffer created by getline.
 * @head: Pointer to first node of the stack.
 *
 * Description: We can acces to this variables on anywhere on our program.
 */
typedef struct variables_s
{
	FILE *fd;
	char *buffer;
	stack_t *head;
} var_t;
extern var_t varx;
var_t varx;

/** File: monty.c */
void _validate_number_arguments(int argc);
FILE *_open_file(char **argv);
void _get_info_data(void);
void _get_opcode(unsigned int line_number);
void _free_all_varx(void);

/** File: opcode_0.c */
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);

/** File: opcode_1.c */
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);

/** File: opcode_1.c */
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);

#endif
