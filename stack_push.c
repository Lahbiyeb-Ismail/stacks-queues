#include "monty.h"

/**
 * stack_push - Pushes a new element onto the stack.
 *
 * Description: This function adds a new element with the specified value
 * to the top of the stack. If the value is zero, it prints an error message
 * and exits with failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "push" operation
 * appears in the Monty file.
 */

void stack_push(stack_t **stack, unsigned int line_number)
{
	int n, i;

	if (!globals_var.new_node_value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	for (i = 0; globals_var.new_node_value[i]; i++)
	{
		if ((globals_var.new_node_value[i] < '0' ||
			globals_var.new_node_value[i] > '9')
			&& globals_var.new_node_value[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_memory();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globals_var.new_node_value);

	add_dnodeint_end(stack, n);
}
