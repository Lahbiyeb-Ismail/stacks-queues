#include "monty.h"

/**
 * queue_func - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void queue_func(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	global_var.lifo = 0;
}

/**
 * stack_func - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void stack_func(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	global_var.lifo = 1;
}
