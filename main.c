#include "main.h"

headers_t headers = {
	OPC_RESET,
	ARG_RESET,
	FLAG_RESET,
	FILE_RESET
}

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
	FILE fd;
	size_t size = 0;
	ssize_t rbytes = 1;
	stack_t *stack = NULL;
	unsigned int i = 0;
	char *args = NULL;

	goto checkfile;
readline:
	while (rbytes > 0)
	{
		rbytes = getline(&args, &size, fd);
		headers.args = args;
		i++;
		if (rbytes > 0)
			execute(args, &stack, i, fd);
		free(args);
	}
	goto cleanup;
checkfile:
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	headers.file = fd;
	goto readline;
cleanup:
	f_stack(stack);
	fclose(fd);
	return (0);
}

/**
 * execute - executes the opcode
 *
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 *
 * Return: no return
*/
int execute(char *args, stack_t **stack, unsigned int counter, FILE *file)
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
	}

	opcode = strtok(args, " \n\t");
	if (opcode && opcode[0] == #)
		return (0);
	headers.opcode = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{	opcodes[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(args);
		f_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
