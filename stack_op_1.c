#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _add - Adds the top two elements of the stack.
 * @stack: Stack
 * @line_lumber: Line number
 * Return: Nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "l%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

	int result = (*stack)->n +(*stack)->next->n;
	stack_t *tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->n = result;
}

/**
 * _nop - Doesn't do anything
 * @stack: Stack
 * @line_lumber: Line number
 * Return: Nothing
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
