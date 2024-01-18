#include "monty.h"

globals_t global_var;

/**
 * free_memory - frees the global variables
 *
 * Return: no return
 */
void free_memory(void)
{
	free_dlistint(global_var.head);
	free(global_var.buffer);
	fclose(global_var.file);
}

/**
 * init_global_var - initializes the global variables
 *
 * @file: file descriptor
 * Return: no return
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
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
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
