#include "monty.h"

/**
 * add_func - Adds the top two elements of the stack.
 *
 * Description: This function adds the values of the top two elements
 * of the stack. It first checks if the stack has at least two elements;
 * if not, it prints an error message and exits with failure status.
 * Otherwise, it adds the values and updates the stack by removing the
 * top element.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "add" operation appears
 * in the Monty file.
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	/* Check if the stack has at least two elements */
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	/* Move to the second element in the stack */
	tmp = (*stack)->next;
	/* Add the values of the top two elements */
	tmp->n += (*stack)->n;

	/* Remove the top element from the stack */
	pop_func(stack, line_number);
}

/**
 * sub_func - Subtracts the top element from the second element in the stack.
 *
 * Description: This function subtracts the value of the top element from the
 * second element in the stack. It checks if the stack has at least two
 * elements; if not, it prints an error message and exits with failure status.
 * Otherwise, it performs the subtraction and updates the stack by removing
 * the top element.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "sub" operation appears in
 * the Monty file.
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
 * div_func - Divides the second element by the top element in the stack.
 *
 * Description:
 * This function divides the value of the second element in the stack by
 * the value of the top element. It checks if the stack has at least two
 * elements; if not, it prints an error message and exits with failure status.
 * Additionally, it checks for division by zero, and if encountered, it prints
 * an error message and exits with failure status. Otherwise, it performs the
 * division and updates the stack by removing the top element.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "div" operation appears
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


/**
 * mul_func - Multiplies the values of the top two elements in the stack.
 *
 * Description:
 * This function multiplies the value of the top element by the value of the
 * second element in the stack. It checks if the stack has at least two
 * elements; if not, it prints an error message and exits with failure status.
 * Otherwise, it performs the multiplication and updates the stack by removing
 * the top element.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "mul" operation appears
 * in the Monty file.
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_memory();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	tmp->n *= (*stack)->n;

	pop_func(stack, line_number);
}

/**
 * mod_func - Computes the remainder of the division of the second element
 * by the top element in the stack.
 *
 * Description:
 * This function calculates the remainder when dividing the value of the second
 * element in the stack by the value of the top element. It checks if the stack
 * has at least two elements; if not, it prints an error message and exits with
 * failure status. Additionally, it checks for division by zero, and if
 * encountered, it prints an error message and exits with failure status.
 * Otherwise, it performs the modulo operation and updates the stack by
 * removing the top element.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "mod" operation appears
 * in the Monty file.
 */

void mod_func(stack_t **stack, unsigned int line_number)
{
	int len = stack_len(stack);
	stack_t *tmp = NULL;

	tmp = *stack;

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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

	tmp->n %= (*stack)->n;

	pop_func(stack, line_number);
}
