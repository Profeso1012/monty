#include "monty.h"

monty_data_t monty_data = {NULL, NULL, NULL};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    monty_data.doc = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        monty_data.details = NULL;
        read_line = getline(&monty_data.details, &size, monty_data.doc);
        monty_data._args = monty_data.details;
        counter++;
        if (read_line > 0)
        {
		if (kill(monty_data.details, &stack, counter, monty_data.doc) != 0)
		{
			fprintf(stderr, "Error executing instruction on line %d\n", counter);
			fclose(monty_data.doc);
			free(monty_data.details);
			empty_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
    }
    free(monty_data.details);
    empty_stack(stack);
    fclose(file);
    return (0);
}
