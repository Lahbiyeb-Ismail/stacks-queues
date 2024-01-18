#include "monty.h"

/**
 * rotl_func - Swaps the top two elements of the stack.
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

void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_1 = NULL;
	stack_t *tmp_2 = NULL;
	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;

	tmp_1 = (*stack)->next;
	tmp_2 = *stack;

	for (; tmp_2->next != NULL; tmp_2 = tmp_2->next)
		;

	tmp_1->prev = NULL;
	tmp_2->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = tmp_2;

	*stack = tmp_1;
}
