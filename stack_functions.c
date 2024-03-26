#include "monty.h"

/**
 * add_stack - add to stack
 * @num: number to add
 * Return: return address of new node
 */

stack_t *add_stack(const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->n = n;
	newNode->prev = NULL;
	if(!head)
	{
		tail = newNode;
		newNode->next = NULL;
	} else
	{
		newNode->next = head;
		head->prev = newNode;
	}
	
	head = newNode;

	return newNode;
}

 *pop_stack_queue()
{
	if(!head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_count);
		exit(EXIT_FAILURE);
	}

	if (stack_mode_q == 1)
	{
		stack_t *temp;
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	} else
	{
		stack_t *temp;
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}
