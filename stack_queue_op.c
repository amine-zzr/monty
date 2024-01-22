#include "monty.h"

/**
 * stack_op - Sets the format of the data to a stack (LIFO).
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	(void)stack;

	monty.mode = 1;
}


/**
 * queue_op - Sets the format of the data to a queue (FIFO).
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	(void)stack;

	monty.mode = 0;
}
