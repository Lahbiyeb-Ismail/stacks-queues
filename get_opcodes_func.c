#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);
}
