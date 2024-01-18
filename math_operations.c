#include "monty.h"

/**
 * add_func - Swaps the top two elements of the stack.
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

void add_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	tmp->n += (*stack)->n;

	pop_func(stack, line_number);
}


/**
 * sub_func - Swaps the top two elements of the stack.
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

void sub_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	tmp->n -= (*stack)->n;

	pop_func(stack, line_number);
}

/**
 * div_func - Swaps the top two elements of the stack.
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

void div_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	tmp->n /= (*stack)->n;

	pop_func(stack, line_number);
}
