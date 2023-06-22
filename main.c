#include "main.h"

/**
 * main - interpreter for monty 98 code
 *
 * @argc: argument counter
 * @argv: argument vector - location of monty file
 *
 * Return: 0 (success) Always
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 0;
	ssize_t rbytes = 1;
	stack_t *stack = NULL;
	unsigned int i = 0;
	char *args;
	headers_t *headers = _headers();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	headers->file = fd;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rbytes > 0)
	{
		args = NULL;
		rbytes = getline(&args, &size, fd);
		headers->args = args;
		i++;
		if (rbytes > 0)
			iset_opcall(args, &stack, i, fd, headers);
		free(args);
	}
	f_stack(stack);
	fclose(fd);
	return (0);
}

/**
 * iset_opcall - searches for and executes the opcode
 *
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @args: line content
 * @headers: headers structure
 *
 * Return: no return
*/
int iset_opcall(char *args, stack_t **stack, unsigned int counter,
		FILE *file, headers_t *headers)
{
	unsigned int i = 0;
	char *opcode;
	instruction_t opcodes[] = {
		{"push", m_push}, {"pall", m_pall}, {"pint", m_pint},
		{"pop", m_pop}, {"swap", m_swap}, {"add", m_add},
		{"nop", m_nop}, {"sub", m_sub}, {"div", m_div},
		{"mul", m_mul}, {"mod", m_mod}, {"pchar", m_pchar},
		{"pstr", m_pstr}, {"rotl", m_rotl}, {"rotr", m_rotr},
		{"queue", m_queue}, {"stack", m_stack}, {NULL, NULL}
	};

	opcode = strtok(args, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	headers->opcode = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{	opcodes[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(args);
		f_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * _getline - custom implementation of the getline function
 * @lineptr: line pointer to read to
 * @n: number of bytes read
 * @stream: source to read from
 *
 * Return: number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = *n;
	int c;
	size_t i = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			new_lineptr = realloc(*lineptr, buffer_size);
			if (new_lineptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_lineptr;
			*n = buffer_size;
		}
		(*lineptr)[i] = c;
		i++;
		if (c == '\n')
		{
			break;
		}
	}
	if (i == 0)
	{
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (i);
}

