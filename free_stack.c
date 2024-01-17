#include "monty.h"

/**
 * free_stack - Frees the memory allocated for a stack.
 *
 * Description: This function deallocates the memory for each
 * node in the stack, starting from the top of the stack, and
 * sets the stack pointer to NULL.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 */

void free_stack(stack_t **stack)
{
	stack_t *curr_node;

	while ((curr_node = (*stack)) != NULL)
	{
		*stack = (*stack)->next;
		free(curr_node);
	}
}
