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
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_memory();
		exit(EXIT_FAILURE);
	}

	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;

	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;

	return (aux->next);
}
