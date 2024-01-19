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
	char *tmp_ptr;
	int arg;

	if (sscanf(line, "%255s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (sscanf(line + strlen("push"), "%d", &arg) == 1)
			{
				tmp_ptr = line + strlen("push");
				while (*tmp_ptr && (*tmp_ptr == ' ' || *tmp_ptr == '\t'))
					tmp_ptr++;

				if (isdigit(*tmp_ptr) || (*tmp_ptr == '-' && isdigit(*(tmp_ptr + 1))))
					push(&stack, arg);
				else
				{
					fprintf(stderr, "L%u, usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
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
			while (*line && (*line != '\n' && *line != ' ' && *line != '\t'))
				line++;

			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
