#include "monty.h"

/**
 * main - Entry point of the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"nop", nop}, {"add", add}, {"swap", swap},
		{"pop", pop}, {"pint", pint}, {NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		parser(line, instructions, &stack, line_number);
		line_number++;
	}
	free_stack(&stack);
	free(line);
	fclose(file);

	return (0);
}
