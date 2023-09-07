#include "monty.h"

int main(void)
{
    stack_t *top = NULL;

    value = 1;
    _push(&top, value);
    value = 2;
    _push(&top, value);
    value = 3;
    _push(&top, value);

    printf("Printing the stack:\n");
    _pall(&top, value);
/**
    while (top != NULL)
    {
        stack_t *temp = top;
        top = top->next;
        free(temp);
    }
*/
    return (0);
}
