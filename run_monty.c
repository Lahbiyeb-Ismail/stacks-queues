#include "monty.h"

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
	FILE *file = fopen(filename, "r");
	stack_t *Stack;
	char line[256];
	unsigned int line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		char *token = strtok(line, " \n");

		if (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				int value = atoi(strtok(NULL, " \n"));

				stack_push(&Stack, value, line_number);
			}
			else if (strcmp(token, "pall") == 0)
				stack_pall(&Stack);
			else if (strcmp(token, "pint") == 0)
				stack_pint(&Stack, line_number);
		}
		line_number++;
	}

	fclose(file);
	free_stack(&Stack);
}
