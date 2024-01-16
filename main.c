#include "monty.h"

/**
 * main - Main function for the Monty interpreter program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Returns EXIT_SUCCESS if the program runs successfully,
 * EXIT_FAILURE otherwise.
 */

int main(int argc, char **argv)
{
		/*Check if the number of command-line arguments is not 2*/
	if (argc != 2)
	{
		/* Print a usage message to the console */
		printf("USAGE: monty file\n");

		/* Return EXIT_FAILURE to indicate an error*/
		return (EXIT_FAILURE);
	}

	/* Call the run_monty function with the provided filename */
	run_monty(argv[1]);

	/* Return EXIT_SUCCESS if everything executed successfully */
	return (EXIT_SUCCESS);
}

