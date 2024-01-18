#include "monty.h"

/**
 * parser - Parses a line of Monty bytecode and executes
 *		the corresponding operation
 * @line: The line of Monty bytecode to parse
 * @line_number: The line number in the Monty bytecode file
 */

void parser(char *line, unsigned int line_number)
{
	char opcode[256];
	char *arg_str;
	int arg;

	if (sscanf(line, "%255s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			arg_str = line + strlen("push");
			while (*arg_str == ' ')
				arg_str++;
			if (*arg_str != '\0')
			{
				arg = atoi(arg_str);
				push(&stack, arg);
			}
			else
			{
				fprintf(stderr, "L%u, usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
