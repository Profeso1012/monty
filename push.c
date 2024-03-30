#include "monty.h"

/**
 * opcode_push - pushes an element onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_num: current line number in the file
 */
void opcode_push(stack_t **stack, unsigned int line_num)
{
    int num, i = 0, flag = 0;

    if (monty_data._args)
    {
        if (monty_data._args[0] == '-')
            i++;
        for (; monty_data._args[i] != '\0'; i++)
        {
            if (monty_data._args[i] > 57 || monty_data._args[i] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_num);
            fclose(monty_data.doc);
            free(monty_data.details);
            empty_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        fclose(monty_data.doc);
        free(monty_data.details);
        empty_stack(*stack);
        exit(EXIT_FAILURE);
    }
    num = atoi(monty_data._args);
    /* Implement the actual pushing onto the stack here */
    printf("Pushing onto stack: %d\n", num);
}
