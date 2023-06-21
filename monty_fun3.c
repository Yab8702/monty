#include "monty.h"


/**
 * _sub - Subtracts the top element from the second top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 *
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _div - Divides the second top element by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 *
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _mul - Multiplies the second top element with the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _mod - Computes the remainder of dividing the second top element
 * by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
