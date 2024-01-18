#include "monty.h"

/**
 * pop_func - Removes the top element from the stack.
 *
 * Description: This function pops the top element from the stack. It checks
 * if the stack is empty, and if so, it prints an error message and exits with
 * failure status. Otherwise, it removes the top element, updates the
 * stack pointer, and frees the memory for the removed node.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pop" operation appears in
 * the Monty file.
 */

void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
