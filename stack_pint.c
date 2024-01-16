#include "monty.h"

/**
 * stack_pint -  Prints the value at the top of the stack.
 *
 * Description: This function prints the value of the element
 * at the top of the stack. If the stack is empty, it prints an
 * error message and exits with a failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pint" operation
 * appears in the Monty file.
 */

void stack_pint(stack_t **stack, int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->prev)
		printf("%d\n", (*stack)->n);
}
