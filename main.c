#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    char buffer[BUFFER_SIZE];
    char *token;
    FILE *file;
    unsigned int line_number = 0;

    if (argc != 2)
    {
	    fprintf(stderr, "USAGE: monty file\n");
	    return(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
	    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	    return(EXIT_FAILURE);
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
                fclose(file);
		while (stack != NULL)
		{
			stack_t *temp = stack;
			stack = stack->next;
			free(temp);
		}
		return(EXIT_FAILURE);
	    }
	    if (!is_integer(token))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                while (stack != NULL)
                {
                    stack_t *temp = stack;
                    stack = stack->next;
                    free(temp);
                }
		return(EXIT_FAILURE);
            }
	   
            op_func(&stack, atoi(token));
        }
        else if (strcmp(token, "pint") == 0)
        {
            if (stack == NULL)
            {
	  	 fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                fclose(file);
                while (stack != NULL)
                {
                    stack_t *temp = stack;
                    stack = stack->next;
                    free(temp);
                
	}
		return(EXIT_FAILURE);
	    }
    
            op_func(&stack, line_number);
        }
	else
		op_func(&stack, line_number);

    }

    fclose(file);

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
    return (EXIT_SUCCESS);
}
