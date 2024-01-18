#include "monty.h"

/**
 * _strcmp - Entry point
 *
 *  * @s1: char array
 *  * @s2: char array
 *
 * Description: Function that compare two character arrays
 * or strings terminated by null value (C-strings) lexicographically.
 *
 * Prototype: int _strcmp(char *s1, char *s2);
 *
 * Return: the pointer to the copied string.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
