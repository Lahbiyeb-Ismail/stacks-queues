#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals_var - global structure to use in the functions
 * @lifo: first parameter inside the current line
 * @value: second parameter inside the current line
 * @head: doubly linked list head
 * @file: file descriptor
 * @buffer: input text
 * @line_count: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals_var
{
	int lifo;
	char *value;
	stack_t *head;
	FILE *file;
	char *buffer;
	unsigned int line_count;
} globals_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern globals_t global_var;


/* TASK-0: */
/* push pushes an element to the stack. */
void push_func(stack_t **stack, unsigned int line_number);
/* pall prints all the values on the stack */
void pall_func(stack_t **stack, unsigned int line_number);

/* TASK-1: pint prints the value at the top of the stack */
void pint_func(stack_t **stack, unsigned int line_number);

/* TASK-2: pop removes the top element of the stack.*/
void pop_func(stack_t **stack, unsigned int line_number);

/* TASK-3: swap swaps the top two elements of the stack. */
void swap_func(stack_t **stack, unsigned int line_number);

/* TASK-4: add adds the top two elements of the stack. */
void add_func(stack_t **stack, unsigned int line_number);

/* TASK-5: nop doesn’t do anything. */
void nop_func(stack_t **stack, unsigned int line_number);

/* TASK-6: sub subtracts the top two element of the stack */
void sub_func(stack_t **stack, unsigned int line_number);

/* TASK-7: div divides the top two element of the stack */
void div_func(stack_t **stack, unsigned int line_number);

/* TASK-8: mul multiplies the top two element of the stack */
void mul_func(stack_t **stack, unsigned int line_number);

/* TASK-9: */
/* computes the rest of the division of the top two element of the stack */
void mod_func(stack_t **stack, unsigned int line_number);

/* TASK-11: pchar prints the char at the top of the stack */
void pchar_func(stack_t **stack, unsigned int line_number);

/* TASK-12: pstr prints the string starting at the top of the stack */
void pstr_func(stack_t **stack, unsigned int line_number);

/* TASK-13: rotl rotates the stack to the top.*/
void rotl_func(stack_t **stack, unsigned int line_number);

/* TASK-14: rotr rotates the stack to the bottom. */
void rotr_func(stack_t **stack, unsigned int line_number);

/* TASK-15: */
/* queue sets the format of the data to a queue (FIFO). */
void queue_func(stack_t **stack, unsigned int line_number);
/* stack sets the format of the data to a stack (LIFO). */
void stack_func(stack_t **stack, unsigned int line_number);


/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* string helper functions */
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void run_monty(FILE *file);
void init_global_var(FILE *file);
void free_memory(void);
FILE *check_file_input(int argc, char *argv[]);

/* Helper function */
int stack_len(stack_t **stack);

#endif
