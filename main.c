#include "monty.h"

int main(void)
{
    stack_t *top = NULL; // Initialize an empty stack

    // Test the _push function
    value = 10;
    _push(&top);
    value = 20;
    _push(&top);
    value = 30;
    _push(&top);

    // Test the _pall function
    printf("Printing the stack:\n");
    _pall(&top);

    // Clean up the stack (you should have a function for this in monty.c)
    while (top != NULL)
    {
        stack_t *temp = top;
        top = top->next;
        free(temp);
    }

    return (0);
}

