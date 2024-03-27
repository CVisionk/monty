#include "monty.h"



/**
 * perform_arithmetic - perform arithmatic tasks
 * @n: num1
 * @m: num2
 * @op: operator
 * Return: Ans on Success, exit otherwise.
 */
int perform_arithmetic(int n, int m, char op[])
{
	int match = 0;
	int add = strcmp("add", op);
	int sub = strcmp("sub", op);
	int div = strcmp("div", op);
	int mul = strcmp("mul", op);
	int mod = strcmp("mod", op);

	if (match == add)
	{
		return (m + n);
	} else if (match == sub)
	{
		return (m - n);
	} else if (match == div)
	{
		return (m / n);
	} else if (match == mul)
	{
		return (m * n);
	} else if (match == mod)
	{
		return (m % n);
	}

	return (0);
}

/**
 * do_arithmetic - perform arithmatic tasks
 * @stack: head of stack
 * @line_number: lines read
 * @op: operator
 */

void do_arithmetic(stack_t **stack, unsigned int line_number, char op[])
{

	stack_t *curr = *stack;

	if (!curr || !curr->next)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
		exit(EXIT_FAILURE);
	}

	int n = (curr->n);
	int m = (curr->next->n);

	(curr->next)->n = perform_arithmetic(n, m, op);
	*stack = curr->next;
	(*stack)->prev = NULL;
	free(curr);
}

/**
 * f_add - perform arithmatic tasks
 * @stack: head of stack
 * @line_number: lines read
 */

void f_add(stack_t **stack, unsigned int line_number)
{
	do_arithmetic(stack, line_number, "add");
}
