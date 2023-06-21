#include "main.h"

/**
 * m_add - adds the first two items in a stack
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_add(stack_t **h, unsigned int ln)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	i = tmp->n + tmp->next->n;
	tmp->next->n = i;
	*h = tmp->next;
	free(tmp);
	printf("add -> m_add has been called\n");
}

/**
 * m_sub - subtracts the first two items in a stack
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_sub(stack_t **h, unsigned int ln)
{
	headers_t *headers = _headers();
	stack_t *tmp;
	int j, i;

	tmp = *h;
	for (i = 0; tmp != NULL; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	j = tmp->next->n - tmp->n;
	tmp->next->n = j;
	*h = tmp->next;
	free(tmp);
	printf("sub -> m_sub has been called\n");
}

/**
 * m_div - divides the first two items in a stack
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_div(stack_t **h, unsigned int ln)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	i = tmp->next->n / tmp->n;
	tmp->next->n = i;
	*h = tmp->next;
	free(tmp);
	printf("div -> m_div has been called\n");
}

/**
 * m_mul - multiplies the first two items in a stack
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_mul(stack_t **h, unsigned int ln)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	i = tmp->next->n * tmp->n;
	tmp->next->n = i;
	*h = tmp->next;
	free(tmp);
	printf("mul -> m_mul has been called\n");
}

/**
 * m_mod - finds the modulo of the first two items in a stack
 *
 * @h: h pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_mod(stack_t **h, unsigned int ln)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(headers->file);
		free(headers->args);
		f_stack(*h);
		exit(EXIT_FAILURE);
	}
	i = tmp->next->n % tmp->n;
	tmp->next->n = i;
	*h = tmp->next;
	free(tmp);
	printf("mod -> m_mod has been called\n");
}
