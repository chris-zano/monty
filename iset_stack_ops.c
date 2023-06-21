#include "main.h"

/**
 * m_pchar - prints char at the top of the stack && \n
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_pchar(stack_t **h, unsigned int ln)
{
	printf("pchar -> m_pchar has been called");
}

/**
 * m_pstr - prints string at the top of the stack && \n
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_pstr(stack_t **h, unsigned int ln)
{
	printf("pstr -> m_pstr has been called");
}

/**
 * m_rotl - rotates the stack to the top
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_rotl(stack_t **h, unsigned int ln)
{
	printf("rotl -> m_rotl has been called");
}

/**
 * m_rotr - rotate the stack to the bottom
 *
 * @h: head pointer to the stack
 * @ln: line number
 * Return: void
*/
void m_rotr(stack_t **h, __attribute__((unused)) unsigned int ln)
{
	printf("rotr -> m_rotr has been called");
}

/**
 * m_nop - does nothing.
 *
 * @h: head pointer to the stack
 * @ln: line number
 *
 * Return: void
*/
void m_nop(stack_t **h, unsigned int ln)
{
	printf("nop -> m_nop has been called");
}
