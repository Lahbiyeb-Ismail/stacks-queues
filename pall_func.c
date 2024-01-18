#include "monty.h"

/**
 * pall_func - Prints all elements of the stack.
 *
 * Description: This function prints the values of all elements in
 * the stack from the top to the bottom.
 * If the stack is empty, it exits with a failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pall" operation
 * appears in the Monty file.
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;
	(void)line_number;

	curr_node = *stack;

/* Iterate through the stack and print each element */
	while (curr_node)
	{
			/* Print the value of the current element */
		printf("%d\n", curr_node->n);

		/* Move to the next element in the stack */
		curr_node = curr_node->next;
	}
}
