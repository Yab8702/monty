#include "monty.h"


/**
 * _add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * execute_instruction - Executes the opcode instruction.
 * @opcd: Opcode to be executed
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */
void execute_instruction(char *opcd, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{"nop", _nop},
		{NULL, NULL}
	};
	int i = 0;

	if (opcd[0] == '#')
		return;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcd, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcd);
	exit(EXIT_FAILURE);
}

/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 *
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
