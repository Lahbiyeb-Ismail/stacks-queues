#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals_var_s - opcode and its function
 * @new_node_value: the opcode
 * @head: function to handle the opcode
 * @file: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct globals_var_s
{
	char *new_node_value;
	stack_t *head;
	FILE *file;
} globals_var_t;


extern globals_var_t  globals_var;

void init_globals_var(FILE *file);

void run_monty(char *filename);
void free_stack(stack_t *stack);
void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_memory(void);

/* TASK-0 */
/* pushes an element to the stack. */
void stack_push(stack_t **stack, unsigned int line_number);
/* prints all the values on the stack, starting from the top of the stack. */
void stack_pall(stack_t **stack, unsigned int line_number);

/* TASK-1: prints the value at the top of the stack, followed by a new line. */
void stack_pint(stack_t **stack, int line_number);

/* TASK-2:  removes the top element of the stack. */
void stack_pop(stack_t **stack, int line_number);

#endif /* STACK_H */
