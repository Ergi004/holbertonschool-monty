#include "monty.h"

/**
 * get_op - Reads the file
 * @token: Tokenizes the commands
 * @line: Line
 * Return: NULL.
 */

void (*get_op(char *token, unsigned int line))(stack_t **, unsigned int)
{
	(void) line;
	instruction_t instruction_op[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruction_op[i].opcode != NULL; i++)
	{
		if (strcmp(token, instruction_op[i].opcode) == 0)
		{
			return (instruction_op[i].f);
		}
	}
	return (NULL);
}
