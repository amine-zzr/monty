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
	int arg, i;

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
		for (i = 0; token[i] != '\0'; i++)
		{
			if (!isdigit(token[i]) && !(i == 0 && token[i] == '-'))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}

		arg = atoi(token);
		push(&stack, arg);

	}
	else if (strcmp(opcode, "pall") == 0)
		pall(&stack);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
