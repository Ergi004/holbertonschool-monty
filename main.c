#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
    stack_t *stack = NULL;
    char buffer[BUFFER_SIZE];
    char *token;
    unsigned int line_number = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        line_number++;

        token = strtok(buffer, " \t\n");

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
            token = strtok(NULL, " \t\n");
            if (token == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            op_func(&stack, line_number);
        }
        else
        {
            op_func(&stack, line_number);
        }
    }

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return (EXIT_SUCCESS);
}
