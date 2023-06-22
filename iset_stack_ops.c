#include "main.h"

/**
 * m_pchar - prints char at the top of the stack && \n
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_pchar(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();
	stack_t *tmp;

	tmp = *h;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * m_pstr - prints string at the top of the stack && \n
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_pstr(stack_t **h, unsigned int ln)
{
	stack_t *tmp;
	(void)ln;

	tmp = *h;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * m_rotl - rotates the stack to the top
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_rotl(stack_t **h, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp = *h, *fast;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	fast = (*h)->next;
	fast->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = tmp;
	(*h) = fast;
}

/**
 * m_rotr - rotate the stack to the bottom
 *
 * @h: h pointer to the stack
 * @ln: line number
 * Return: void
*/
void m_rotr(stack_t **h, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	tmp = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*h)->prev = tmp;
	(*h) = tmp;
}

/**
 * m_nop - does nothing.
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_nop(stack_t **h, unsigned int ln)
{
	(void) ln;
	(void) h;
}
