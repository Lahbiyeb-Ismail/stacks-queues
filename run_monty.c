#include "monty.h"

/**
 * run_monty - Executes the Monty bytecode instructions from a given file.
 *
 * Description: This function reads the Monty bytecode instructions line by
 * line from the specified file, interprets each instruction, and executes
 * the corresponding operations.
 *
 * @file: The name of the file containing Monty bytecode instructions.
 */


void run_monty(FILE *file)
{
	void (*f)(stack_t **, unsigned int line_number);

	size_t size = 256;
	ssize_t num_lines = 0;
	char *lines[2] = { NULL, NULL };

	num_lines = getline(&global_var.buffer, &size, file);

	while (num_lines != -1)
	{
		lines[0] = strtok(global_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
					global_var.line_count, lines[0]);
				free_memory();
				exit(EXIT_FAILURE);
			}

			global_var.value = strtok(NULL, " \t\n");
			f(&global_var.head, global_var.line_count);
		}

		num_lines = getline(&global_var.buffer, &size, file);
		global_var.line_count++;
	}
}
