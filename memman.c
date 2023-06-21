#include "main.h"

/**
 * f_stack - frees the stack pointed to by stack
 * @stack: head pointer to a stack
 * Return: void
 */
void f_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * m_addnode - adds a new node to the top of the stack
 *
 * @h: head of the stack
 * @n: new node
 *
 * Return: void
*/
void m_addnode(stack_t **h, int n)
{
	stack_t *new, *tmp;

	tmp = *h;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new;
	new->n = n;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * m_addqueue - adds a new node to the tail end of a stack
 *
 * @n: new node
 * @h: head of the stack
 *
 * Return: void
*/
void m_addqueue(stack_t **h, int n)
{
	stack_t *new, *tmp;

	tmp = *h;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*h = new;
		new->prev = NULL;
	}
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}
