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
	global_var.line_count = 0;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
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
	void (*f)(stack_t * *stack, unsigned int line_number);
	FILE *file;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = { NULL, NULL };

	file = check_input(argc, argv);
	init_global_var(file);
	nlines = getline(&global_var.buffer, &size, file);
	while (nlines != -1)
	{
		lines[0] = _strtok(global_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_var.line_count);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_memory();
				exit(EXIT_FAILURE);
			}
			global_var.value = _strtok(NULL, " \t\n");
			f(&global_var.head, global_var.line_count);
		}
		nlines = getline(&global_var.buffer, &size, file);
		global_var.line_count++;
	}

	free_memory();

	return (0);
}
