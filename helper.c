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

/**
 * init_global_var - Initializes global variables for the Monty bytecode
 * interpreter.
 *
 * Description: This function sets initial values for global variables used
 * in the Monty bytecode interpreter. It specifically initializes value, head,
 * file, buffer, line_count, and lifo members of the global_var structure.
 *
 * @file: A pointer to the FILE structure representing the Monty
 * bytecode file.
 */

void init_global_var(FILE *file)
{
	global_var.value = NULL;
	global_var.head = NULL;
	global_var.file = file;
	global_var.buffer = NULL;
	global_var.line_count = 1;
	global_var.lifo = 1;
}


/**
 * free_memory - Frees memory allocated for Monty bytecode interpreter.
 *
 * Description: This function releases the memory allocated for the dynamic
 * linked list, buffer, and closes the Monty bytecode file. It is intended
 * to be called when the program is about to exit to ensure proper memory
 * cleanup.
 */

void free_memory(void)
{
	free_dlistint(global_var.head);
	free(global_var.buffer);
	fclose(global_var.file);
}
