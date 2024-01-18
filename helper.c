#include "monty.h"

/**
 * stack_len - Calculates the number of elements in the stack.
 *
 * Description - This function traverses the stack and counts the
 * number of elements present.
 * It returns the count, representing the length of the stack.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 *
 * Return: The number of elements in the stack.
 */

int stack_len(stack_t **stack)
{
	int len;
	stack_t *tmp;

	tmp = *stack;

	for (len = 0; tmp; tmp = tmp->next, len++)
		;

	return (len);
}
