#include "monty.h"
/**
 * free_stack - freedoubly linked list
 * @head: first node of stack
 * Return: none
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * f_stack - free stack
 * @head: first node(unused)
 * @counter: line counter (unused)
 *
 * Return: none
*/

void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 0;
}
/**
* addnode - add node to top of stack
* @head: first node
* @n: new value
*
* Return: none
*/

void addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
#include "monty.h"

/**
 * f_queue - print first node of queue
 * @head: first node of queue (unused)
 * @counter: line counter (unused)
 *
 * Return: none
 */

void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 1;
}

/**
 * addqueue - add node to tail of queue
 * @n: new value
 * @head: head of the queue
 *
 * Return: none
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
