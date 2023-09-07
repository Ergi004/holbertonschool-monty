#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 */

void _push(stack_t **top,unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = line_number;
    new->prev = NULL;

    if (*top == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = *top;
        (*top)->prev = new;
    }
    *top = new;
}

/**
 */

void _pall(stack_t **top, unsigned int __attribute__((unused)) line_number)
{
	stack_t *tmp = *top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 */

void _pint(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}


/**
 */

void _pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (!top || !(*top))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	*top = (*top)->next;
	if (*top)
	{
		(*top)->prev = NULL;
	}
	free(tmp);
}
				
