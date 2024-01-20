#include "monty.h"

/**
 * pint - Handles the pint opcode in Monty language
 * @line_number: The line number in the Monty bytecode file
 *
 */

void pint(unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack->n);
}

/**
 * pop - Handles the pop opcode in Monty language
 * @line_number: The line number in the Monty bytecode file
 *
 */

void pop(unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = stack;
	stack = stack->next;
	free(temp);
}
