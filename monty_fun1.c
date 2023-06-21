#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (argument == NULL || !is_integer(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * _pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
