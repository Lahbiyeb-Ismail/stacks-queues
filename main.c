#include "monty.h"

globals_t global_var;


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
