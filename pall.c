#include "monty.h"

/**
 * opcode_pall - prints all the values on the stack
 * @stack: double pointer to the beginning of the stack
 * @line_num: just fufilling all righteoness
*/
void opcode_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	(void)line_num;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
