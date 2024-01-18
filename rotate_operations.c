#include "monty.h"

/**
 * rotl_func - Rotates the stack to the top, moving the top element to
 * the bottom.
 *
 * Description:
 * This function rotates the stack to the top, moving the top element
 * to the bottom. It checks if the stack is empty or has only one element;
 * if so, it does nothing. Otherwise, it performs the rotation by updating
 * the pointers accordingly.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "rotl" operation appears
 * in the Monty file (not used).
 */

void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_1 = NULL;
	stack_t *tmp_2 = NULL;
	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;

	tmp_1 = (*stack)->next;
	tmp_2 = *stack;

	for (; tmp_2->next != NULL; tmp_2 = tmp_2->next)
		;

	tmp_1->prev = NULL;
	tmp_2->next = *stack;

	(*stack)->next = NULL;
	(*stack)->prev = tmp_2;

	*stack = tmp_1;
}


/**
 * rotr_func - Rotates the stack to the bottom, moving the bottom element
 * to the top.
 *
 * Description:
 * This function rotates the stack to the bottom, moving the bottom
 * element to the top. It checks if the stack is empty or has only
 * one element; if so, it does nothing. Otherwise, it performs the
 * rotation by updating the pointers accordingly.
 *
 * @stack: Pointer to the pointer to the top of the stack.
 * @line_number: The line number where the "rotr" operation appears
 * in the Monty file (not used).
 */

void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	if (!(*stack) || !(*stack)->next)
		return;

	tmp = (*stack);

	for (; tmp->next; tmp = tmp->next)
		;

	tmp->prev->next = NULL;
	tmp->next = *stack;

	tmp->prev = NULL;
	(*stack)->prev = tmp;

	*stack = tmp;
}
