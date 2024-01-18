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
	int i = 0, ret_val = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret_val = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (ret_val);
}
