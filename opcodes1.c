#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds the top two elements, updates the second top element with
 * the result, and then removes the top element using the pop function.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty bytecode file
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Handles the nop opcode in Monty language
 *
 * This function does not perform any action, as the nop opcode
 * is designed to do nothing.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
