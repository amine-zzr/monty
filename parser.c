#include "monty.h"

/**
 * parser - Parses a line of Monty bytecode and executes
 *		the corresponding operation
 * @line: The line of Monty bytecode to parse
 * @line_number: The line number in the Monty bytecode file
 */

void parser(char *line, unsigned int line_number)
{
	char *token;
	char opcode[256];

	token = strtok(line, " \t\n");
	if (token == NULL)
		return;

	strcpy(opcode, token);

	if (strcmp(opcode, "push") == 0)
	{
		token = strtok(NULL, " \t\n");
		if (token == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		push(token, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall();
	else if (strcmp(opcode, "pint") == 0)
		pint(line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(line_number);
	else if (strcmp(opcode, "add") == 0)
		add(line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop();
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
