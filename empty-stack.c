#include "monty.h"

/**
 * empty_stack - Frees a stack.
 * @stack: Pointer to the stack head
 *
 * Description: Frees the memory allocated for each node in the stack.
 */
void empty_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
