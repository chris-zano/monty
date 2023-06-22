#include "main.h"

/**
 * m_push - adds a new node to the end of the stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
 */
void m_push(stack_t **h, unsigned int ln)
{
	int n, j = 0, flag = 0;
	headers_t *headers = _headers();

	if (headers->opcode)
	{
		if (headers->opcode[0] == '-')
			j++;
		for (; headers->opcode[j] != '\0'; j++)
			if (headers->opcode[j] > 57 || headers->opcode[j] < 48)
				flag = 1;
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			fclose(headers->file);
			free(headers->args);
			f_stack(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(headers->opcode);
	if (headers->flag == 0)
		m_addnode(h, n);
	else
		m_addqueue(h, n);
}

/**
 * m_pall - prints all elements in a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
 */
void m_pall(stack_t **h, unsigned int ln)
{
	stack_t *tmp;
	(void)ln;

	tmp = *h;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * m_pint - prints the top element in a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
 */
void m_pint(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * m_pop - removes an element from a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
 */
void m_pop(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();
	stack_t *tmp;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	*h = tmp->next;
	free(tmp);
}

/**
 * m_swap - swaps elements in a stack
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
 */
void m_swap(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();
	stack_t *tmp;
	int len = 0, i;

	tmp = *h;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	i = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = i;
}
