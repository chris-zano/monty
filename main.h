#ifndef MAIN_H
#define MAIN_H

/* INCLUDE STATEMENTS GO HERE */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/* MACRO DEFINITIONS GO HERE */
#define OPC_RESET NULL
#define ARG_RESET NULL
#define FILE_RESET NULL
#define FLAG_RESET 0

/* STRUCTURE DEFINITIONS GO HERE */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct headers_s - structure for header container
 *			which carries values through the program.
 *
 * @opcode: the opcode to be executed, carried through the program.
 * @args: arguments attached to the headers, used as options for execution.
 * @flag: indicates which data structure to use, a stack or a queue.
 * @file: a monty file to be executed.
 *
 */
typedef struct headers_s
{
	char *opcode;
	char *args;
	int flag;
	FILE *file;
} headers_t;

/* GLOBAL VARIABLE ( EXTERN DECLARATIONS ) */
extern headers_t headers;

/* FUNCTION DECLARATIONS GO HERE */

/* "m" stands for monty - m_push >> monty_push */
/* "f" stands for free - f_stack >> free_stack */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int iset_opcall(char *args, stack_t **stack, unsigned int counter, FILE *file);
void f_stack(stack_t *stack);
void m_push(stack_t **h, unsigned int ln);
void m_pall(stack_t **h, unsigned int ln);
void m_pint(stack_t **h, unsigned int ln);
void m_pop(stack_t **h, unsigned int ln);
void m_swap(stack_t **h, unsigned int ln);
void m_add(stack_t **h, unsigned int ln);
void m_nop(stack_t **h, unsigned int ln);
void m_sub(stack_t **h, unsigned int ln);
void m_div(stack_t **h, unsigned int ln);
void m_mul(stack_t **h, unsigned int ln);
void m_mod(stack_t **h, unsigned int ln);
void m_pchar(stack_t **h, unsigned int ln);
void m_pstr(stack_t **h, unsigned int ln);
void m_rotl(stack_t **h, unsigned int ln);
void m_rotr(stack_t **h, __attribute__((unused)) unsigned int ln);
void m_queue(stack_t **h, unsigned int ln);
void m_stack(stack_t **h, unsigned int ln);
void m_addnode(stack_t **h, int n);
void m_addqueue(stack_t **h, int n);

#endif /* MAIN_H */
