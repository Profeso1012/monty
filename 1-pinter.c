#include "monty.h"

/**
 * opcode_pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file being executed
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        fclose(monty_data.doc);
        free(monty_data.details);
        empty_stack(*stack);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
