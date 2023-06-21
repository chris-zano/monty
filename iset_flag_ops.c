#include "main.h"

/**
 * m_queue - adds the first two items in a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_queue(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();
	(void)h;
	(void)ln;
	headers->flag = 1;
	printf("queue -> m_queue has been called\n");
}

/**
 * m_stack - adds the first two items in a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_stack(stack_t **h, unsigned int ln)
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
	printf("stack -> m_stack has been called\n");
}
