#include "monty.h"

/**
 * push - Handles the push opcode in Monty language
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty bytecode file
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *current, *new_node;

	for (i = 0; monty.arg[i] != '\0'; i++)
	{
		if (!isdigit(monty.arg[i]) && !(i == 0 && monty.arg[i] == '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(monty.arg);
	new_node->prev = NULL;
	new_node->next = NULL;
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

/**
 * pall - Prints all the values on the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (*stack == NULL)
		return;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack nodes
 * @stack: The pointer to the stack.
 *
 */

void free_stack(stack_t **stack)
{
	stack_t *current, *next;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
