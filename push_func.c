#include "monty.h"

/**
 * push_func - Pushes a new element onto the stack.
 *
 * Description: This function adds a new element with the specified value
 * to the top of the stack. If the value is zero, it prints an error message
 * and exits with failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "push" operation
 * appears in the Monty file.
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	int n, i;

	if (!global_var.value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	for (i = 0; global_var.value[i] != '\0'; i++)
	{
		if (!isdigit(global_var.value[i]) && global_var.value[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_memory();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global_var.value);

	if (global_var.lifo == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}
