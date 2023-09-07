#include "monty.h"


/**
 */

void _push(stack_t **top, unsigned int __attribute__((unused)) line_number)
{
	stack_t *new;
       
	new = malloc(sizeof(stack_t));
	
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;

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
