#include "monty.h"

/**
 * swap_func - Swaps the top two elements of the stack.
 *
 * Description: This function swaps the positions of the top two elements
 * of the stack. It checks if the stack has at least two elements; if not,
 * it prints an error message and exits with failure status. Otherwise,
 * it swaps the top two elements by adjusting the pointers accordingly.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "swap" operation appears
 * in the Monty file.
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, len++)
		;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	tmp->next = (*stack)->next;
	tmp->prev = *stack;

	(*stack)->next = tmp;
	(*stack)->prev = NULL;
}
