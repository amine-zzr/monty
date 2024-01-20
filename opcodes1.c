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

/**
 * swap - Handles the swap opcode in Monty language
 * @line_number: The line number in the Monty bytecode file
 *
 */

void swap(unsigned int line_number)
{
	int temp;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
}

/**
 * add - adds the top two elements, updates the second top element with
 * the result, and then removes the top element using the pop function.
 * @line_number: The line number in the Monty bytecode file
 *
 */

void add(unsigned int line_number)
{
	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack->next->n += stack->n;
	pop(line_number);
}

/**
 * nop - Handles the nop opcode in Monty language
 *
 * This function does not perform any action, as the nop opcode
 * is designed to do nothing.
 */

void nop(void)
{
}
