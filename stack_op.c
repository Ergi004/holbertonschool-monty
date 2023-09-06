#include "monty.h"


/**
 */

void _push(stack_t **top)
{
	stack_t *new = malloc(sizeof(stack_t));
	
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	
	if (*top == NULL)
		new->next = NULL;
	else 
	{
		new->next = *top;
		new->prev = NULL;
	}
	*top = new;
}

/**
 */

void _pall(stack_t **top)
{
	stack_t *tmp = *top;

	while (top != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
