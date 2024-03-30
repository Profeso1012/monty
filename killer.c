#include "monty.h"

int kill(char *content, stack_t **stack, unsigned int counter, FILE *doc)
{
    instruction_t opcodes[] = {
        {"push", opcode_push},
        {"pall", opcode_pall},
        {NULL, NULL}
    };

    char *opcode = NULL;
    int i;                                                    
    (void)doc;
    opcode = strtok(content, " \t\n");
    if (!opcode || opcode[0] == '#')
        return 0;

    monty_data._args = strtok(NULL, "\n");
    if (monty_data._args && isspace(*monty_data._args))
        monty_data._args = strtok(NULL, "\n");

    for (i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, counter);
            return 0;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
    return 1;
}
