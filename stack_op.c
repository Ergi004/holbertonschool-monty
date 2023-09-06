#include <main.h>

int value;

/**
 */

void _push(stack_t **top, unsigned int line_number)
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
		nnew->next = top;
		*top->prev = NULL;
	}
	*top = new;
}

/**
 */

void _pall(stack_t **top, unsigned int line_number)
{
	stact_t *tmp = *top;

	while (top != NULL)
	{
		printf("%d\n", tmp->n);
	       tmp = tmp->next;
	}
}

/**
 */


