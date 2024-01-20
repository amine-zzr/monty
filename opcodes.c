#include "monty.h"

/**
 * push - Handles the push opcode in Monty language
 * @token: The argument token associated with the push opcode
 * @line_number: The line number in the Monty bytecode file
 *
 */

void push(char *token, unsigned int line_number)
{
	int i;
	stack_t *new_node;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (!isdigit(token[i]) && !(i == 0 && token[i] == '-'))
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

	new_node->n = atoi(token);
	new_node->prev = NULL;
	new_node->next = stack;

	if (stack)
		stack->prev = new_node;

	stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 *
 */

void pall(void)
{
	stack_t *current;

	if (stack == NULL)
		return;

	current = stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack nodes
 *
 */

void free_stack(void)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
