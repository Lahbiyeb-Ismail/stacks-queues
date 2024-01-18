#include "monty.h"

/**
 * queue_func - Sets the mode to queue (FIFO) for future stack operations.
 *
 * Description:
 * This function sets the mode to queue (First In, First Out) for future stack
 * operations. It takes pointers to the top of the stack and the current line
 * number as parameters but does not utilize them. The global variable `lifo`
 * is set to 0, indicating the queue mode for upcoming operations.
 *
 * @stack: Pointer to the pointer to the top of the stack (not used).
 * @line_number: The current line number (not used).
 */

void queue_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global_var.lifo = 0;
}

/**
 * stack_func - Sets the mode to stack (LIFO) for future stack operations.
 *
 * Description:
 * This function sets the mode to stack (Last In, First Out) for future stack
 * operations. It takes pointers to the top of the stack and the current line
 * number as parameters but does not utilize them. The global variable `lifo`
 * is set to 1, indicating the stack mode for upcoming operations.
 *
 * @stack: Pointer to the pointer to the top of the stack (not used).
 * @line_number: The current line number (not used).
 */

void stack_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	global_var.lifo = 1;
}
