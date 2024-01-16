#include "monty.h"

/**
 * stack_push - Pushes a new element onto the stack.
 *
 * Description: This function adds a new element with the specified value
 * to the top of the stack. If the value is zero, it prints an error message
 * and exits with failure status.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @value: The value to be pushed onto the stack.
 * @line_number: The line number where the "push" operation
 * appears in the Monty file.
 */

void stack_push(stack_t **stack, int value, int line_number)
{
	stack_t *new_node;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}


	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;

	/* Check if the stack is empty*/
	if (!(*stack))
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
