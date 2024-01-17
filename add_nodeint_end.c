#include "monty.h"

/**
 * stack_t *add_dnodeint_end - Entry point
 *
 *  * @head: doubly-linked list head
 *  * @n: new doubly-linked list data
 *
 * Description: Function that adds a new node at the end of
 * a dlistint_t list.
 *
 * Prototype: dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *last_node;

	globals_var.new_node = malloc(sizeof(stack_t));

	if (!globals_var.new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_memory();
		return (NULL);
	}

	globals_var.new_node->n = n;
	globals_var.new_node->next = NULL;

	if ((*head) == NULL)
	{
		globals_var.new_node->prev = NULL;
		*head = globals_var.new_node;
	}
	else
	{
		last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		globals_var.new_node->prev = last_node;
		last_node->next = globals_var.new_node;
	}

	return (globals_var.new_node);
}
