#include "monty.h"

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
	headers_t *headers = _headers();
	(void)h;
	(void)ln;
	headers->flag = 0;
}
