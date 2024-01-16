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
	/* Initialize pointers to traverse the stack*/
	stack_t *current = *stack;
	stack_t *next;

	/* Iterate through the stack and free each node */
	while (current != NULL)
	{
		/* Save the next node before freeing the current one */
		next = current->next;
		/* Free the current node */
		free(current);
		/* Move to the next node */
		current = next;
	}

	/* Set the stack pointer to NULL after freeing all nodes */
	*stack = NULL;
}
