#include "monty.h"

/**
 * isNumeric - check if input is numeric
 * @num: string to check
 * Return: 0 if is digit;
 */

int isNumeric(char num[])
{
	int n = atoi(num);
	char isdigit[32];

	sprintf(isdigit, "%d", n);
	return (strcmp(isdigit, num));
}

/**
 * add_stack - add to stack
 * @s: head of stack/queue
 * @t: tail of stack
 * @l: lines read
 * @sn: num to add
 */

void add_stack(stack_t **s, stack_t **t, unsigned int l, char sn[])
{
	int n = atoi(sn);
	stack_t *newNode = malloc(sizeof(stack_t));

	if (isNumeric(sn) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->prev = NULL;
	if (!*s)
	{
		*t = newNode;
		newNode->next = NULL;
	} else
	{
		newNode->next = *s;
		(*s)->prev = newNode;
	}
	*s = newNode;

}

/**
 * pop_stack_queue - pop node from stack
 * @stack: head of stack/queue
 * @line_number: lines read
 */

void pop_stack_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	temp = *stack;
	if (0)
	{
		*stack = (*stack)->prev;
		(*stack)->next = NULL;
		free(temp);
	} else
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * print_stack_queue - pop node from stack
 * @stack: head of stack/queue
 * @line_number: lines read
 */

void print_stack_queue(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * f_pint - print last node
 * @stack: head of stack/queue
 * @line_number: lines read
 */

void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	} else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

}
