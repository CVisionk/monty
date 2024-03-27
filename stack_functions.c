#include "monty.h"

/**
 * isNumeric - check if input is numeric
 * @stack: head of stack/queue
 * @line_number: lines_read
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
 * @stack: head of stack/queue
 */

void add_stack(stack_t **stack, stack_t **tail, unsigned int line_number, char str[])
{
	int n = atoi(str);

	if(isNumeric(str)!=0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}



	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->n = n;
	newNode->prev = NULL;
	if(!*stack)
	{
		*tail = newNode;
		newNode->next = NULL;
	} else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	
	*stack = newNode;

}

/**
 * pop_stack_queue - pop node from stack
 */

void pop_stack_queue(stack_t **stack, unsigned int line_number)
{
	if(!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	if (prop.stack_is_q == 1)
	{
		stack_t *temp;
		temp = *stack;
		*stack = (*stack)->prev;
		(*stack)->next = NULL;
		free(temp);
	} else
	{
		stack_t *temp;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}


