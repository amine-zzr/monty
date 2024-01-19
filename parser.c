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
	int arg;

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

		arg = atoi(token);

		while (isspace((unsigned char)*token))
			token++;

		if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1))))
			push(&stack, arg);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
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
