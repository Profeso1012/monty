#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @doc: poiner to monty doc
* @content: line content
* Return: no return
*/
int kill(char *content, stack_t **stack, unsigned int counter, FILE *doc)
{
	instruction_t opcodes[] = {
				{"push", opcode_push}, {"pall", opcode_pall}, {"pint", opcode_pint},
				/*{"pop", opcode_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", opcode_pchar},
				{"pstr", opcode_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},*/
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	monty_data._args = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && op)
	{
		if (strcmp(op, opcodes[i].opcode) == 0)
		{	opcodes[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opcodes[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(doc);
		free(content);
		empty_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
