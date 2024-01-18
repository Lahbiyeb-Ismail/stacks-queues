#include "monty.h"

/**
 * get_opcodes - Retrieves the corresponding function for a given opcode.
 *
 * Description:
 * This function takes an opcode as input and searches for a matching opcode in
 * an array of instructions. If a match is found, it returns the associated
 * function.
 * If no match is found, it returns NULL. The array of instructions includes
 * supported opcodes and their corresponding functions.
 *
 * @opcode: The opcode to find the corresponding function for.
 *
 * Return: A function pointer to the corresponding operation, or NULL
 * if no match is found.
 */

void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"stack", stack_func},
		{"queue", queue_func},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);
}
