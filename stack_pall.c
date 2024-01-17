#include "monty.h"

/**
 * stack_pall - Prints all elements of the stack.
 *
 * Description: This function prints the values of all elements in
 * the stack from the top to the bottom.
 * If the stack is empty, it exits with a failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pall" operation
 * appears in the Monty file.
 */

void stack_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

		/* Check if the stack is empty */
	if (!(*stack))
		exit(EXIT_FAILURE);

/* Iterate through the stack and print each element */
	while (*stack)
	{
			/* Print the value of the current element */
		printf("%d\n", (*stack)->n);

		/* Move to the next element in the stack */
		*stack = (*stack)->next;
	}
}
