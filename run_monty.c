#include "monty.h"

globals_var_t globals_var;

/**
 * init_globals_var - Initializes global variables for the Monty interpreter.
 *
 * Description: This function sets initial values for global
 * variables used in the Monty interpreter.
 * It specifically initializes the new_node_value, head, and file
 * members of the globals_var structure.
 *
 * @file: A pointer to the FILE structure representing the Monty bytecode file.
 */

void init_globals_var(FILE *file)
{
	globals_var.new_node_value = NULL;
	globals_var.head = NULL;
	globals_var.file = file;
}

/**
 * run_monty - Executes the Monty bytecode instructions from a given file.
 *
 * Description: This function reads the Monty bytecode instructions line by
 * line from the specified file, interprets each instruction, and executes
 * the corresponding operations.
 *
 * @filename: The name of the file containing Monty bytecode instructions.
 */

void run_monty(char *filename)
{
	void (*f)(stack_t * *stack, unsigned int line_number);
	FILE *file = fopen(filename, "r");
	stack_t *Stack;
	char line[256];
	unsigned int line_number = 0;

	init_globals_var(file);

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_memory();
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		char *token = strtok(line, " \n");

		if (token != NULL)
		{
			f = get_opcodes(token);
			if (f != NULL)
			{
				globals_var.new_node_value = strtok(NULL, "\n");
				f(&Stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
				free_memory();
				exit(EXIT_FAILURE);
			}

		}
		line_number++;
	}
}

