#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structs */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct monty_data_s
{
    FILE *doc;
    char *details;
    char *_args;
} monty_data_t;

/* Global Variable */
extern monty_data_t monty_data;

/* Function Prototypes */
void opcode_push(stack_t **stack, unsigned int line_num);
void opcode_pall(stack_t **stack);
stack_t *add_node(stack_t **head, int num);
void empty_stack(stack_t *stack);
int kill_function(char *content, stack_t **stack, unsigned int counter, FILE *doc);

#endif /* MONTY_H */
