#include "monty.h"

char *arg;

/**
 * parser - Parses a line and executes the corresponding opcode function.
 * @line: The line to parse.
 * @instructions: The array of instruction_t structures.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void parser(char *line, instruction_t *instructions,
		stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i = 0;

	opcode = strtok(line, " \t\n");

	if (opcode == NULL)
		return;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				arg = strtok(NULL, " \t\n");
				if (arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(stack, line_number);
			}
			else
				instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
