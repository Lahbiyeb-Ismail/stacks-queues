#include "monty.h"

globals_t global_var;


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

/**
 * check_file_input - Checks and opens the Monty bytecode file for input.
 *
 * This function validates the command-line input, ensuring that the correct
 * number of arguments is provided. It then attempts to open the Monty bytecode
 * file specified in the command-line arguments for reading. If successful,
 * it returns the file pointer; otherwise, it prints an error message and exits
 * with failure status.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: The file pointer to the opened Monty bytecode file.
 */

FILE *check_file_input(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;

	file = check_file_input(argc, argv);
	init_global_var(file);

	run_monty(file);

	free_memory();

	return (0);
}

