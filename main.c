#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * main - The main function
 * @argc: Arguments
 * @argv: Arguments
 * Return: Nothing
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char buffer[BUFFER_SIZE], *token;
	FILE *file;
	unsigned int line_number = 0;
	int hasAlpha = 0;
	char *numberCopy = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		line_number++;
		token = strtok(buffer, " \n");
		if (token == NULL || token[0] == '#')
		{
			continue;
		}
		void (*op_func)(stack_t **, unsigned int) = get_op(token, line_number);

		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			numberCopy = token;

			while (*numberCopy)
			{
				if (isalpha(*numberCopy))
				{
					hasAlpha = 1;
					break;
				}
				numberCopy++;
			}
			if (
			((strspn(token, "+-0123456789") == 0) || hasAlpha))
			{
				fprintf(stderr, "L%i: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			op_func(&stack, atoi(token));
		}
		else
			op_func(&stack, line_number);
	}
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
