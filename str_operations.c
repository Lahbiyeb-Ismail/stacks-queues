#include "monty.h"

/**
 * pchar_func - Prints the ASCII character corresponding to the top element
 * in the stack.
 *
 * Description:
 * This function prints the ASCII character represented by the value of the top
 * element in the stack. It checks if the stack is empty and if the value is
 * within the valid ASCII range (0 to 127). If the stack is empty or the value
 * is out of range, it prints an error message and exits with failure status.
 * Otherwise, it prints the character followed by a newline.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pchar" operation appears
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
 *  pstr_func - Prints the string represented by the ASCII values in the stack.
 *
 * Description:
 * This function prints the string represented by the ASCII values in the
 * stack. It iterates through the stack, starting from the top, and prints
 * characters until it encounters a value outside the valid ASCII range
 * (0 to 127) or reaches the end of the stack. It does not consider values
 * less than or equal to 0 or greater than or equal to 128 in the stack.
 * The resulting string is printed followed by a newline.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "pstr" operation appears
 * in the Monty file (not used).
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
