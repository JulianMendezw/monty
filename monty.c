#include "monty.h"

/**
 * main - Interpreter for opcodes from a file <.m>.
 * @argc: Count of arguments.
 * @argv: Arguments from promt.
 *
 * Return:0 on succes.
 */


int main(int argc, char **argv)
{
	varx.fd = 0;
	varx.buffer = NULL;
	varx.head = NULL;

	_validate_number_arguments(argc);

	varx.fd = _open_file(argv);

	_get_info_data();

	return (0);
}
