#include "monty.h"

/**
 * pchar_func - Swaps the top two elements of the stack.
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

void pchar_func(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr_func - Swaps the top two elements of the stack.
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

void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;
	(void)line_number;

	curr_node = *stack;

	while (curr_node && curr_node->n > 0 && curr_node->n < 128)
	{
		printf("%c", curr_node->n);
		curr_node = curr_node->next;
	}

	printf("\n");
}
