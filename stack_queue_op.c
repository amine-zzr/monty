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

/**
 * add_node - Adds a new node to the stack or queue.
 * @stack: The pointer to the stack.
 * @new_node: The new node to add.
 */

void add_node(stack_t **stack, stack_t *new_node)
{
	stack_t *current;

	if (monty.mode == 1) /* LIFO */
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else /* FIFO */
	{
		if (!*stack)
			*stack = new_node;
		else
		{
			current = *stack;
			while (current->next)
				current = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}
