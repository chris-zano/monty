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
