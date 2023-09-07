#include "monty.h"

instruction_t instruction_op[] = {
                                {"push", _push},
                                {"pop", _pop},
				{"pall", _pall},
                                {NULL,NULL}
        };
void (*get_op(char *token, unsigned int __attribute__((unused)) line))(stack_t **, unsigned int)
{
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
