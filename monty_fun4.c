#include "monty.h"


/**
 * _pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL && current->n != 0
			&& (current->n >= 0 && current->n <= 127))
	{
		if (current->n == '\0')
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotates the stack to the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = NULL;

	(void)line_number;
	if (first != NULL && first->next != NULL)
	{
		second = first->next;
		while (first->next != NULL)
			first = first->next;
		first->next = *stack;
		(*stack)->prev = first;
		*stack = second;
		second->prev = NULL;
		first->next->next = NULL;
	}
}

/**
 * _rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
