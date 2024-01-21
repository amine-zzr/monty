#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}


/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		putchar('\n');
		return;
	}

	current = *stack;
	while (current && current->n != 0 && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = first;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}
