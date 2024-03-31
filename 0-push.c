#include "monty.h"

/**
 * opcode_push - pushes an element onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_num: current line number in the file
 */
void opcode_push(stack_t **stack, unsigned int line_num)
{
    int num, i = 0, flag = 0;
    stack_t *new_node;

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

    /* Allocate memory for a new node */
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(monty_data.doc);
        free(monty_data.details);
        empty_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Assign data to the new node */
    new_node->n = num;
    new_node->prev = NULL;

    /* If the stack is empty */
    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        /* Set the previous pointer of the current top node to the new node */
        (*stack)->prev = new_node;
        /* Set the next pointer of the new node to the current top node */
        new_node->next = *stack;
        /* Update the top of the stack to be the new node */
        *stack = new_node;
    }
}
